<?php
namespace Kkochetkov\RdcCom\controller;

use Kkochetkov\RdcCom\core\Cookie;
class RedirectController{
    /* обработка перехода по ссылке */
    public function redirectAction() {
        $cookie=new Cookie();
        /* первый тип редиректа. Переход по ссылке, для просмотра функции из библиотеки lib_common */
        if(isset($_GET['item_name'])){
            $item_name=htmlspecialchars($_GET['item_name']);
            $cookie->addCookie('resultActionRedirect',$item_name);
            return $cookie->getCookie('resultActionRedirect');
        }
        /* второй тип редиректа. Переход по ссылке для просмотра готового примера */
        if(isset($_GET['exmp_name'])){
            $exmp_name=htmlspecialchars($_GET['exmp_name']);
            $cookie->addCookie('resultActionRedirectExmp',$exmp_name);
            return $cookie->getCookie('resultActionRedirectExmp');
        }
        /* в случае отсутствия перехода по ссылке, возвращаю запрос, который является не нулевым */
        return $cookie->getCookie('resultActionRedirect') ?? $cookie->getCookie('resultActionRedirectExmp');
    }
}
?>