<?php
namespace Kkochetkov\RdcCom\controller;

use Kkochetkov\RdcCom\core\Cookie;
class ChangeLanguageController{
    /* установка нужного языка */
    public function changeLanguageAction(){
        $cookie=new Cookie();
        if(isset($_POST['language'])){
            $language=htmlspecialchars($_POST['language']);
            $cookie->addCookie('resultActionLanguage',$language);
        }
        if(!$cookie->hasCookie('resultActionLanguage')){
            $cookie->addCookie('resultActionLanguage','ru');
        }
        return $cookie->getCookie('resultActionLanguage');
    }
}
?>