<div class="libraryTitle">
    <?=$langArray['libraryTitle']?>
    <hr class="hr-double">
</div>
<div class="libraryDescriptionShort">
    <?=$langArray['libraryDescriptionShort']?>
</div>
<!-- блок отображается только для администратора -->
<div class="goToAdminPage">
    <?php
        use Kkochetkov\RdcCom\core\Session;
        $session=new Session();
        if($session->getSession('userRole') == 'Admin'){
            echo '<a href="/showAdminPanel" class="refToAdm">Управление пользователями.</a>';
        }
    ?>
</div>