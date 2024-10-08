<?php
namespace Kkochetkov\RdcCom\core;

use Kkochetkov\RdcCom\controller\ChangeLanguageController;
use Kkochetkov\RdcCom\controller\LoginController;
use Kkochetkov\RdcCom\controller\RedirectController;
use Kkochetkov\RdcCom\controller\SearchController;
use Kkochetkov\RdcCom\model\TestDBService;
use Kkochetkov\RdcCom\view\View;
use PDO;

class MainRourter{
/* массив для регистрации страниц, на которые возможен переход */
private static $listPages=[];
/* массив, содержащий страницы, которые должны быть выведены на экран */
private static $outputArr=[];
/* массив для вызова нужных контроллеров, исходя из содержимого POST/GET запросов.
Каждый ключ, является одним из возможных ключей передаваемых POST/GET массивами.
Каждый вложенный массив содержит в себе:
0 - контроллер;
1 - метод обработки действия запроса;
3 - контейнер для записи результата работы контроллера. */
private static $ActionsList=[
    'logout_status'=>[LoginController::class,'logout','result'=>null],
    /* смена языка по кнопке */
    'language'    =>[ChangeLanguageController::class,'changeLanguageAction','resultActionLanguage'=>null],
    /* поиск с использованием поисковой строки */
    'user_request'=>[SearchController::class,'searchAction','resultActionSearch'=>null],
    /* переход по ссылке для просмотра чего-либо из библиотеки */
    'item_name'   =>[RedirectController::class,'redirectAction','resultActionRedirect'=>null],
    /* вывод всех графических функций (не зависит от пользователя) */
    'common_fun'  =>['menuResult'=>'common_function'],
    /* вывод всех общих функций (не зависит от пользователя) */
    'graph_func'  =>['menuResult'=>'graphic_function'],
    /* переход по ссылке для просмотре примера */
    'exmp_name'   =>[RedirectController::class,'redirectAction','resultActionRedirectExmp'=>null],
    /* */
    'map2d'       =>['menuResult'=>'map2d_lib'],
    'map3d'       =>['menuResult'=>'map3d_lib'],
    'mapTHM'      =>['menuResult'=>'mapTHM_lib'],
    'mapBPF'      =>['menuResult'=>'mapBPF_lib'],
    'geoProj'     =>['menuResult'=>'geoProj_lib']  
];
    /* метод для добавления страниц на которые возможен переход */
    public static function currentPage($uri,$page){
        self::$listPages[]=[
            'uri' =>$uri,
            'page'=>$page
        ];
    }
    /* массив для записи подмассивов */
    private static $outputRenderArr=[];
    /* функция, которая позволяет расширять рендер массив как асоциативный массив */
    private static function addRenderArr($arrName,$arr){
        self::$outputRenderArr=array_merge(self::$outputRenderArr,array($arrName=>$arr));
    }
    /* метод для подключения нужной страницы */
    public static function enable($resultItemArray = array(),
                                  $resultExmpArray = array(),
                                  $langArray = array())
    {
        if(strpos($_SERVER['REQUEST_URI'],'?')){
            $currentURI=mb_strimwidth($_SERVER['REQUEST_URI'],0,strpos($_SERVER['REQUEST_URI'],'?'));
        }else{
            $currentURI=$_SERVER['REQUEST_URI'];
        }
        foreach(self::$listPages as $var){
            if($var['uri'] == $currentURI){
                require_once __DIR__ . './../view/templates' . '/' . $var['page'] . '.php';
                die();
            }
        }
        echo '404 not found';
    }
    /* запуск основного сценария на странице */
    public static function start(){
        /* создание необходимых экземпляров и подключение к базе данных */
        $mainCookie=new Cookie();
        $dbService=new TestDBService();
        $loginController=new LoginController();
        $dbInfo=require_once 'config.php';
        $dbService->pdo_connect($dbInfo['host'],$dbInfo['db'],$dbInfo['user'],$dbInfo['pass']);
        /* проверяем пришел ли запрос на авторизацию пользователя */
        $loginController->login();
        /* проверяем авторизован ли пользователь и если нет, отправляем на страницу авторизации,
        до тех пор, пока пользователь не будет авторизован */
        if(!$loginController->isAuth())
        {
            require_once __DIR__ . './../view/templates/signInPage.php';
            exit;
        }
        /* извлечение ключей из массивов POST/GET */
        $actionPOST=array_keys($_POST)[0] ?? null;
        $actionGET=array_keys($_GET)[0] ?? null;
        $currAction=$actionPOST ?? $actionGET;
        /* запуск необходимого контроллера. 
        1) проверяю наличие ключа в массиве действий;
        2) получаю нужный контроллера и действие;
        3) переставляю указатель вложенного массива в конец
        4) записываю результат работы контроллера в контейнер
        5) сбрасываю положение указателя */
        if(isset(self::$ActionsList[$currAction])){
            $controller=new self::$ActionsList[$currAction][0];
            $action=self::$ActionsList[$currAction][1];
            end(self::$ActionsList[$currAction]);
            self::$ActionsList[$currAction][key(self::$ActionsList[$currAction])]=$controller->$action();
            reset(self::$ActionsList);
        }
        /* Пробегаю весь массив ActionList, где в каждый подмассив записан результат работы контроллера. 
        каждый результат работы контроллера передаю в БД и получаю ответ в виле асоциативного массива. 
        Затем формирую рендер массив, который передается в класс view для отрисовки */
        foreach(self::$ActionsList as $name => $value){
            /* ключевое слово передается в БД либо из ActionList, либо из куки */
            $subRenderArr=$dbService->get_result_array(end($value) ?? 
                                          $mainCookie->getCookie(key($value)),key($value));
            self::addRenderArr($name.'__RenderArr',$subRenderArr);
        }
        /* убираю первый элемент рендер массива, так как он содержит результат работы контроллера языка
        и не оказывает влияния на прочую отрисовку. */
        array_shift(self::$outputRenderArr);
        /* убираю еще один эллемент массива, отвечающий за аутентификацию */
        array_shift(self::$outputRenderArr);
        /* создание экземпляра рендер с нужным языком (язык как и все остальные результаты работы контроллеров
        достается из ActionList или Cookie) */
        $view=new View(end(self::$ActionsList['language']) ??
                        $mainCookie->getCookie('resultActionLanguage'));

        /* запуск функции, отвечающей за графическое отображение на странице */
        $view->render(self::$outputRenderArr);
    }
    /* проверяет uri на наличие ключевого слово для запуска админ сценраия */
    public static function checkAdminPanel(){
        if($_SERVER['REQUEST_URI'] == '/showAdminPanel'){
            return true;
        }
    }
    /* админ сценарий. Нужен для добавления пользователя */
    public static function startAdmin(){
        $mainCookie=new Cookie();
        $dbService=new TestDBService();
        $loginController=new LoginController();
        $dbInfo=require_once 'config.php';
        $dbService->pdo_connect($dbInfo['host'],$dbInfo['db'],$dbInfo['user'],$dbInfo['pass']);        

        $loginController->addNewUser();
        $loginController->deleteUser();

        require_once __DIR__ . './../view/templates/addUser.php';
    }
}
?>