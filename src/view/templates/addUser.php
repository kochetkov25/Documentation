<?php
  use Kkochetkov\RdcCom\core\Session;
use Kkochetkov\RdcCom\model\TestDBService;

  /* не позволяем пользователю увидеть страницу, если он не админ */
  $session=new Session();
  if($session->getSession('userRole') != 'Admin'){
    // echo '<h1>404 not found</h1><br>';
    // echo '<h2><a href="/">Вернуться на главную страницу</a></h2>';
    // exit();
    header('Location: /');
    exit();
  }
?>
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="UTF-8">
    <title> Add new user </title>
    <link rel="stylesheet" href="./../../../public/css/addUser__style.css">
     <meta name="viewport" content="width=device-width, initial-scale=1.0">
     <link rel="icon" href="su-27.png" type="image/x-icon">
   </head>
<body>
  <div class="container">
    <div class="title">Добавление пользователя</div>
    <div class="content">
      <div class="usersTable">
          <table>
          <caption>Зарегистрированные пользователи</caption>
            <tr><th>ID</th><th>Login</th><th>Password</th><th>Role</th><th></th></tr>
              <?php
                TestDBService::showAllUsers();
              ?>
          </table>
      </div>
      <form action="/showAdminPanel" method="post">
        <div class="user-details">
          <div class="input-box">
            <span class="details">Логин</span>
            <input type="text" name="newUserLog" placeholder="Введите логин пользователя" required>
          </div>
          <div class="input-box">
            <span class="details">Пароль</span>
            <input type="text" name="newUserPass" placeholder="Введите пароль пользователя" required>
          </div>
        </div>
        <div class="status-message">
            <?php
            // в зависимотси от возвращенного кода операции добавления вывожу либо сообщение
            // об успехе, либо о неудаче
              if($session->getSession('addStatus') == 1){
                echo '<span style="color: green;">Пользователь успешно добавлен!</span>';
              }elseif($session->getSession('addStatus') == 2){
                echo '<span style="color: red;">Ошибка при добавлении пользователя! Логин или пароль содержат больше 16-и символов.</span>';
              }
              // удаляю из сессии статус добавления, чтобы повторно не отображать сообщение
              $session->deleteSession('addStatus');
            ?>
        </div>
        <div class="button">
          <input type="submit" value="Добавить">
        </div>
        <a class="backRef" href="/">
            Вернуться на главную страницу.
        </a>
      </form>
    </div>
  </div>
</body>
</html>