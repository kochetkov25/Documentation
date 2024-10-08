<?php
namespace Kkochetkov\RdcCom\controller;

use Kkochetkov\RdcCom\core\Cookie;
class SearchController{
    /* формирование запроса пользователя (переменная добавляется в глобальный массив $_COOKIE только после редиректа*/
    public function searchAction(){
        $Cookie=new  Cookie();
        if(isset($_POST['user_request'])){
            $request=htmlspecialchars($_POST['user_request']);
            $Cookie->addCookie('resultActionSearch',$request);
        }
        return $Cookie->getCookie("resultActionSearch");
    }
}
?>