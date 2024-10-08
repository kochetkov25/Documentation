<?php
namespace Kkochetkov\RdcCom\controller;
use Kkochetkov\RdcCom\model\TestDBService;
use Kkochetkov\RdcCom\core\Session;

class LoginController{
    /* функция проверяет авторизован пользователь или нет.
    Если пользователь авторизован в сессию должен быть записан id пользователя
    по ключу user_id */
    public function isAuth(){
        $session=new Session();
        return $session->hasSession('user_id');
    }
    /* функция для авторизации пользователя. Если пользователь не авиторизован и
    пришел пост запрос на авторизацию, проверяем введенные данные. Если данные 
    введены неверно, генерируем сообщение об ошибке */
    public function login(){
        if(!$this->isAuth() && isset($_POST['auth_login'])){
            $session=new Session();
            if(!TestDBService::checkUser($_POST['auth_login'],$_POST['auth_pass'])){
                $session->addSession('flash','логин или пароль введен неверно');
            }else{
                $session->deleteSession('flash');
                header('Location: /');
                exit();
            }
        }
    }
    /* функция очищает все супер глобальные массивы и перекидывает пользователя на страницу регистрации */
    public function logout(){
        if(isset($_GET['logout_status'])){
            session_destroy();
            $_POST=array();
            $_GET=array();
            header('Location: /');
            exit();
        }
    }

    /* контроллера для добавления нового пользователя. Выполняет запрост в бд и возвращает статус */
    public function addNewUser(){
        if(isset($_POST['newUserLog']) && isset($_POST['newUserPass'])){
            $session=new Session();

            $newLogin = htmlspecialchars($_POST['newUserLog']);
            $newPassword = htmlspecialchars($_POST['newUserPass']);

            if(TestDBService::addUser($newLogin,$newPassword)){
                $session->addSession('addStatus',1);
                // делаю переадресацию на тот же uri, чтобы очистить post и не вызвать 
                // неожиданного поведения
                header("Location: ".$_SERVER['REQUEST_URI']);
                exit();
            }else{
                $session->addSession('addStatus',2);
                header("Location: ".$_SERVER['REQUEST_URI']);
                exit();
            }
        }
    }

    // удаление пользователя из бд
    public function deleteUser(){
        if(isset($_POST['delUserID']))
        {
            $session = new Session();
            $deleteUserID = htmlspecialchars($_POST['delUserID']);

            TestDBService::deleteUser($deleteUserID);
            header("Location: ".$_SERVER['REQUEST_URI']);
            exit();
        }   
    }
}
?>