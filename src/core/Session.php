<?php
namespace Kkochetkov\RdcCom\core;

class Session{
    private $sessionClone;
    /* Передаю ссылку на массив сессий в локальную переменную. Запускаю механизм сессий, 
    в случае если он не был запущен */
    public function __construct()
    {
        if(session_status() !== PHP_SESSION_ACTIVE){
            session_start();
        }
        $this->sessionClone=&$_SESSION;
    }

    /* добавить новую переменную в массив сессий*/
    public function addSession($key,$value){
        if(isset($_SESSION[$key])){
            unset($_SESSION[$key]);
            $this->sessionClone[$key]=NULL;
        }
        $_SESSION[$key]=$value;
        $this->sessionClone[$key]=$value;
    }
    
    /* проверка наличия значения по ключу */
    public function hasSession($key){
        return isset($this->sessionClone[$key]);
    }

    /* взять переменную из массива сессий */
    public function getSession($key){
        return $this->sessionClone[$key] ?? null;
    }

    /* удалить переменную по ключу из массива сессий */
    public function deleteSession($key){
        unset($_SESSION[$key]);
        $this->sessionClone[$key]=null;
    }
}
?>