<?php
/*подключение к базе данных*/
$link=mysqli_connect('localhost','root','','my_first_base');
if(mysqli_connect_errno())
{
    echo 'Error:: incorrect connection';
    exit();
}

