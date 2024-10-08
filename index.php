<?php
require_once __DIR__ . '/vendor/autoload.php';
const EXAMPLE_DIR='./../../../public/examples/';
use Kkochetkov\RdcCom\core\MainRourter;
ini_set('display_errors', 1);
ini_set('error_reporting', E_ALL);
ini_set('display_startup_errors', 1);
MainRourter::currentPage("/signInPage","signInPage");
MainRourter::currentPage("/","libraryMain");
MainRourter::currentPage("/LibrariesMain","libraryMain");
MainRourter::currentPage("/Description","descriptionTemplate");
MainRourter::currentPage("/ExampleMain","exampleMain");
MainRourter::currentPage("/ExampleTemplate","exampleTemplate");
MainRourter::currentPage("/addUser","addUser");
// старт разных сценариев
if(MainRourter::checkAdminPanel())
{
    MainRourter::startAdmin();
}else{
    MainRourter::start();
}
?>