<meta charset="utf-8">

<?php
    include './app/include/database.php';
    session_start();

    if($_GET["par"]=="off")
    {
        $_SESSION["text"]=null;
        $_SESSION["enter"]=null;
        header("Location: ./index.php");
    }

//установка языка при первом открытии страницы
    if(empty($_SESSION["lang"]))
    {
        $_SESSION["lang"]="ru";
    }

    if(!empty($_POST["lang"]))
    {
        $_SESSION["lang"]=$_POST["lang"];
        header("Location: ".$_SERVER["REQUEST_URI"]);
        exit;
    }
    else
    {

    }

    if(!empty($_POST["text"])&&!empty($_POST["enter"]))
    {
        $_SESSION["text"]=$_POST["text"];
        $_SESSION["enter"]=$_POST["enter"];
        header("Location: ".$_SERVER["REQUEST_URI"]);
        exit;
    }


    //var_dump($_SESSION);
    //var_dump($_POST);
    //var_dump($_GET);
    //var_dump(count($_GET));
    //$cont=$_GET;


    global $link;
    if($_SESSION["lang"]=="en") {
        $par_request = "SELECT * FROM `connection` WHERE `function_title` LIKE '$_GET[id]'";
        $par_sql = mysqli_query($link, "SELECT * FROM `connection` WHERE `function_title` LIKE '$_GET[id]'");
        $cont = mysqli_fetch_assoc($par_sql);
    }

    if($_SESSION["lang"]=="ru") {
        $par_request = "SELECT * FROM `connection_ru` WHERE `function_title` LIKE '$_GET[id]'";
        $par_sql = mysqli_query($link, "SELECT * FROM `connection_ru` WHERE `function_title` LIKE '$_GET[id]'");
        $cont = mysqli_fetch_assoc($par_sql);
    }
    require 'language.php';
    global $lang_array;

    //var_dump("session");
    //var_dump($_SESSION["lang"]);
    //var_dump("post");
    //var_dump($_POST["lang"]);
?>



<!DOCTYPE html>

<head>
    <!--Подключение img и скриптов-->
    <title></title>
    <link rel="stylesheet" href="./public/css/style_index_upp.css">
    <link rel="icon" href="img/ico.png" type="image/x-icon">
    <script type="text/javascript" src="./public/js/scroll.js"></script>
</head>

<body>
<!--container - общий контейнер для всех частей страницы. Разбит на 4 большие подкласса:
header - заголовочная часть страницы
menu -  левая часть страницы отведенная под поиск и навигацию
content - правая часть страницы, содержит в себе основной контент
footer - нижняя часть страницы(пустая)
-->
<div class="container">
    <!--header - заголовочная(верхняя) часть сайта. Разбта на три подкласса:
    logo - логотип РПКБ
    main_title - заголовочная надпись
    language_switch - кнопки для смены языка
    -->
    <div class="header">

        <div class="logo">
            <a href="index.php?par=off"><img src="img/rpkb_2_app.svg"></a>
        </div>

        <div class="main_title">
            <?=$lang_array['documentation_lang']?>
        </div>

        <div class="language_switch">
            <form  name="select_form" method="post" action="./index.php" class="change-lag">
                <input name="lang" type="submit" value="ru" id="submit" class="ru_btn">
                <input name="lang" type="submit" value="en" id="submit" class="eng_btn">
            </form>
        </div>

    </div>
    <!--menu - левая часть страницы, отведенная под поиск и навгацию. Разбита на
    три подкласса:
    search_bar - форма поиска и текстовое название формы
    search_list - область страницы отведенная под визуализацию результатов поиска
    list - область страницы отведенная под визуализацию всех библиотечных функций 
    -->
    <div class="menu">

        <div class="search_bar">

            <div class="name">
                <?=$lang_array['documentation_list_lang']?>
            </div>

            <div class="form_class">
                <form method="post" action="./index.php?id=<?=$cont["function_title"]?>" class="form">
                    <input type="text" name="text" placeholder="<?=$lang_array['type_lang']?>" class="search" required>
                    <input type="submit" name="enter" value="<?=$lang_array['search_lang']?>" class="btn">
                </form>
            </div>

        </div>

        <div class="search_list">
            <ul class="MainContainer">
                <li class="Node ExpandLeaf">
                    <?php require 'new_search_alg.php'?>
                </li>
            </ul>
            <hr class="hr-double">
        </div>
<!--Начало тестов-->
        <div class="list">
            <ul class="MainContainer">
                <li id="0" class="Node_0 IsRoot ExpandClosed">
                    <div class="Expand"></div>
                    <div class="Content">lib_common</div>
                    <ul class="MainContainer">
                        <li id="1" class="Node_1 IsRoot ExpandClosed" style="margin-left: 20px">
                            <div class="Expand"></div>
                            <div class="Content">Общие функции и типы данных</div>
                            <ul class="MainContainer">
                                <li class="Node ExpandLeaf">
                                <?php require 'all_list_lib_common.php'?>
                                </li>
                            </ul>
                        </li>

                        <li id="2" class="Node_2 IsRoot ExpandClosed" style="margin-left: 20px">
                            <div class="Expand"></div>
                            <div class="Content">Графические функции</div>
                            <ul class="MainContainer">
                                <li class="Node ExpandLeaf">
                                <?php require 'all_list_lib_common.php'?>
                                </li>
                            </ul>
                        </li>
                    </ul>   
                </li>
            </ul>
        </div>
<!--Конец тестов-->
    </div>
    <!--content - правая часть страницы, отведенная под основной контент. Разбита на два подкласса:
    name_content - заголовочная надпись
    description_content - вводная часть, основной контент
    -->
    <div class="content">

        <div class="name_content">
            <?=$lang_array['main_page_lang']?>
            <hr class="hr-double">
        </div>

        <div class="description_content">
            <?=$lang_array['main_desc_lang']?>
        </div>

    </div>
    <!--footer - на данный моент не используется-->
    <div class="footer">
        <div class="information">
            <a href="#" class="ref_menu"><h4><?=$lang_array['information_lang']?></h4></a>
        </div>
        <div class="contacts">
            <a href="#" class="ref_menu"><h4><?=$lang_array['contacts_lang']?></h4></a>
        </div>
    </div>
</div>
</body>