<?php
namespace Kkochetkov\RdcCom\model;

use PDO;
use PDOException;
use Kkochetkov\RdcCom\core\Session;
use PhpMyAdmin\SqlParser\Statement;

class TestDBService{
    private static $pdo;
    /* массив для выполнения sql запросов.
    sql - sql запрос;
    fieldAffected - количество полей по которым будет происходить поиск (кол-во знаков ? в запросе);
    mode - определяет в каком виде будут предоставленны данные из базы данных (одна из PDO констант) */
    private static $requestsList=[
        'resultActionSearch'  => array(
            'sql'          =>'SELECT `function_title` FROM `connection_ru` WHERE LOWER(`function_description`) REGEXP LOWER(?) OR LOWER(`function_title`) REGEXP LOWER(?)',
            'fieldAffected'=>2,
            'mode'         =>PDO::FETCH_COLUMN,
        ),
        'resultActionRedirect'=> array(
            'sql'          =>'SELECT * FROM `connection_ru` WHERE LOWER(`function_title`) = LOWER(?)',
            'fieldAffected'=>1,
            'mode'         =>PDO::FETCH_ASSOC,
        ),
        'menuResult'=>array(
            'sql'          =>'SELECT `function_title` FROM `connection_ru` WHERE `type` LIKE ? ORDER BY `function_title`',
            'fieldAffected'=>1,
            'mode'         =>PDO::FETCH_COLUMN,
        ),
        'resultActionRedirectExmp'=>array(
            'sql'          =>'SELECT * FROM `examples_ru` WHERE `example_name` = ?',
            'fieldAffected'=>1,
            'mode'         =>PDO::FETCH_ASSOC,
        )
    ];
    /* подключение к базе данных и установка параметров работы с базой данных */
    public static function pdo_connect($host, $db, $user, $pass, $charset='utf8'){
        $dsn="mysql:host=$host;dbname=$db;charset=$charset";
        $opt=[
            PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION,
            PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
            PDO::ATTR_EMULATE_PREPARES   => false,
        ];
        self::$pdo=new PDO($dsn,$user,$pass,$opt);
    }
    /* метод для получения результирующего массива. 
    type - определяет от какого контроллера пришел запрос;
    request - текст запроса. */
    public static function get_result_array($request, string $type){
        if(array_key_exists($type,self::$requestsList) && isset($request)){
            $statement=self::$pdo->prepare(self::$requestsList[$type]['sql']);
            $executeArr=array();
            $counter=0;
            while($counter < self::$requestsList[$type]['fieldAffected']){
                /* кол-во затронутых полей 'fieldAffected', нужно для того, чтобы добавить в массив,
                который будет отправлен в бд, строго столько значений, сколько нужно */
                array_push($executeArr,$request);
                $counter++;
            }
            try{
                $statement->execute($executeArr);
                /* для любого запроса, нужен режим fetchAll, кроме запросов, которые нужно для редиректа
                на другую страницу и соответственно выбирают из БД одну целую строку */
                if($type == 'resultActionRedirect' || $type == 'resultActionRedirectExmp'){
                    return $statement->fetch(self::$requestsList[$type]['mode']);
                }else{
                    return $statement->fetchAll(self::$requestsList[$type]['mode']);
                }
            }catch(PDOException $e){
                /* в данном случа необходим блок try\catch т.к. при отправке запроса с символом
                "\" PDO выбрасывает на фатальную ошибку, хотя этого быть не должно*/
                return null;
            }
        }else{
            return null;
        }        
    }
    /* простая проверка на правильность введенных данных.
    1) если запрос по логину пользователя вернул 0 строк, выходим из функции false
    2) если запрос по логину пользователя вернул не ноль строк, проверяем правильность введенных данных
    если верно, то true, иначе false */
    public static function checkUser($userLogin, $userPassword) : bool
    {
        $statement=self::$pdo->prepare('SELECT * FROM `users` WHERE `login` = ?');
        $executeArr=array();
        array_push($executeArr,$userLogin);
        $statement->execute($executeArr);
        if(!$statement->rowCount()){
            return false;
        }else{
            $userInfo=$statement->fetchAll(PDO::FETCH_ASSOC)[0];
            if($userLogin==$userInfo['login'] && $userPassword==$userInfo['password']){
                $session=new Session();
                $session->addSession('user_id',$userInfo['id']);
                $session->addSession('mainUserLogin',$userInfo['login']);
                $session->addSession('userRole',$userInfo['role']);
                return true;
            }else{
                return false;
            }
        }
    }
    /* простая функция для добавления пользователя в бд. Возвращает статус операции */
    public static function addUser($newLogin,$newPassword) : bool
    {
        $statement=self::$pdo->prepare('INSERT INTO `users` (`id`, `login`, `password`, `role`) VALUES (?, ?, ?, ?)');
        $executeArr=[NULL,$newLogin,$newPassword,'User'];
        try
        {
            $isAdd=$statement->execute($executeArr);
        }
        catch(PDOException $e)
        {
            return false;
        }
        return true;
    }

    // функция удаляет пользователя из бд
    public static function deleteUser($deleteUserID) : bool
    {
        $statement=self::$pdo->prepare('DELETE FROM `users` WHERE `id` = ?');
        $executeArr=[$deleteUserID];
        try
        {
            $isDelete = $statement->execute($executeArr);
        }
        catch(PDOException $e)
        {
            print_r($e->getMessage());
            return false;
        }
        return true;
    }

    // функция для вывода информации о всех пользователях в таблицу.
    // решил не выносить вывод во view так как он очень простой и маленький
    public static function showAllUsers() : void
    {
        $statement=self::$pdo->prepare('SELECT * FROM `users`');
        $executeArr=array();
        $statement->execute($executeArr);
        $result=$statement->fetchAll(PDO::FETCH_ASSOC);
        foreach($result as $row){
            echo "<tr><td>".$row['id']."</td><td>".$row['login']."</td><td>".$row['password']."</td><td>".$row['role']."</td>
                        <td>
                            <form actino='/showAdminPanel' method='post'>
                                <input type='hidden' value='".$row['id']."' name='delUserID'>
                                <input type='submit' value='Delete' class='deleteButton'>
                            </form>
                        </td>
                  </tr>";
        }
    }
}
?>