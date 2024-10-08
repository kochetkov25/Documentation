<?php
namespace Kkochetkov\RdcCom\core;

class Cookie{
    private $cookieClone;
    /* конструктор по умолчанию. Копирует массив куки в локальную переменную. Необходимо для работы с куки до редиректа */
    public function __construct()
    {
        $this->cookieClone=&$_COOKIE;
    }

    /* добавить новую переменную в куки */
    public function addCookie($key,$value){
        if(isset($_COOKIE[$key])){
            setcookie($key,null,-1);
            $this->cookieClone[$key]=null;
        }
        setcookie($key,$value,0);
        $this->cookieClone[$key]=$value;
    }
    
    /* проверка наличия значения по ключу */
    public function hasCookie($key){
        return isset($this->cookieClone[$key]);
    }

    /* взять переменную из куки */
    public function getCookie($key){
        return $this->cookieClone[$key] ?? null;
    }
}
?>