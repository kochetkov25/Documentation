<!DOCTYPE html>
<html lang>
<head>
  <link rel="stylesheet" href="./../../../public/css/signInPage__style.css">
  <link rel="icon" href="su-27.png" type="image/x-icon">
</head>

<body class="mainWrapper">
    <div class="form_auth_block">
      <div class="form_auth_block_content">
        <p class="form_auth_block_head_text">Авторизация</p>
        <form class="form_auth_style" action=<?=$_SERVER['REQUEST_URI']?> method="post">
          <label>Введите имя пользователя:</label>
          <input type="login" name="auth_login" required >
          <label>Введите пароль:</label>
          <input type="password" name="auth_pass" required >
          <button class="form_auth_button" type="submit" name="form_auth_submit">Войти</button>
        </form>
        <div class="incorrect_data">
          <?php 
            use Kkochetkov\RdcCom\core\Session;
            $session=new Session();
            echo $session->getSession('flash');
          ?>
        </div>
      </div>
    </div>
</body>

</html>