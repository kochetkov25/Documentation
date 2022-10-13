
<?php
    include './app/include/database.php';
    session_start();
    if(!empty($_POST["lang"]))
    {
        $_SESSION["lang"]=$_POST["lang"];
        header("Location: ".$_SERVER["REQUEST_URI"]);
        exit;
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
?>

<!DOCTYPE html>

<head>
    <!--Подключение img и скриптов-->
    <title></title>
    <link rel="stylesheet" href="./public/css/style_description.css">
    <link rel="icon" href="img/ico.png" type="image/x-icon">
    <script type="text/javascript" src="./public/js/scroll.js"></script>
    <script type="text/javascript" src="./public/js/full.js"></script>
    <script type="text/javascript" src="./public/js/scroll_for_content.js"></script>
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
            <form  name="select_form" method="post" action="./description.php?id=<?=$cont["function_title"]?>" class="change-lag">
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
                <form method="post" action="./description.php?id=<?=$cont["function_title"]?>" class="form">
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

        <div class="list">
            <ul class="MainContainer">
                <li id="12" class="Node IsRoot ExpandClosed">
                    <div class="Expand"></div>
                    <div class="Content">lib_common</div>
                    <ul class="MainContainer">
                        <li class="Node ExpandLeaf">
                            <?php require 'all_list_lib_common.php'?>
                        </li>
                    </ul>   
                </li>
            </ul>
        </div>

    </div>
    <!--content - правая часть страницы, отведенная под предоставление информации о функции. Разбита на шесть подклассов:
    name_content - заголовочная надпись. Название текущей функции
    description_content - описание функции
    syntax_content - синтаксис функции
    parameters_content - параметры функции
    return_values_content - возвращаемые значения функции
    function_example_content - пример использования функции
    В каждом подклассе реализована одинаковая структура для реализации свертывания\развертывания блока
    -->
    <div class="content">

        <div class="name_content">
           <?=$cont['function_title']?>
            <hr class="hr-double">
        </div>

        <div class="description_content">
            <div class="TextContainer">
                <div id="10" class="NewNode NewIsRoot ExpandOpen">
                    <div id="1" class="NewExpand"></div>
                    <div class="NewContent"><h2><?=$lang_array['description_lang']?></h2></div>
                    <div class="TextContainer">
                        <p><?=$cont['function_description']?></p>
                    </div>
                </div>
            </div>
           <!-- <h2><?=$lang_array['description_lang']?></h2>
            <p><?=$cont['function_description']?></p>-->
        </div>

        <div class="syntax_content">
            <div class="TextContainer">
                <div id="20" class="NewNode NewIsRoot ExpandOpen">
                    <div id="2" class="NewExpand"></div>
                    <div class="NewContent"><h2><?=$lang_array['syntax_lang']?></h2></div>
                    <div class="TextContainer">
                        <?=$cont['function_syntax']?>
                    </div>
                </div>
            </div>
           <!-- <h2><?=$lang_array['syntax_lang']?></h2>
                    <?=$cont['function_examples']?>-->
        </div>

        <div class="parameters_content">
            <div class="TextContainer">
                <div id="30" class="NewNode NewIsRoot ExpandOpen">
                    <div id="3" class="NewExpand"></div>
                    <div class="NewContent"><h2><?=$lang_array['parameters_lang']?></h2></div>
                    <div class="TextContainer">
                        <p class="in_parameters_content"><?=$cont['function_parametrs']?></p>
                    </div>
                </div>
            </div>
            <!--<h2><?=$lang_array['parameters_lang']?></h2>
            <p class="in_parameters_content"><?=$cont['function_parametrs']?></p>-->
        </div>

        <div class="return_values_content">
            <div class="TextContainer">
                <div id="40" class="NewNode NewIsRoot ExpandOpen">
                    <div id="4" class="NewExpand"></div>
                    <div class="NewContent"><h2><?=$lang_array['return_values_lang']?></h2></div>
                    <div class="TextContainer">
                        <p class=in_function_return_values><?=$cont['function_return_values']?></p>
                    </div>
                </div>
            </div>
            <!--<h2><?=$lang_array['return_values_lang']?></h2>
            <p class=in_function_return_values><?=$cont['function_return_values']?></p>-->
        </div>

        <div class="function_example_content">
            <div class="TextContainer">
                <div id="50" class="NewNode NewIsRoot ExpandOpen">
                    <div id="5" class="NewExpand"></div>
                    <div class="NewContent"><h2><?=$lang_array['exmaple_lang']?></h2></div>
                    <div class="TextContainer">
                       <p class="in_function_example"><?=$cont['function_examples']?></p>
                    </div>
                </div>
            </div>
            <!--<h2><?=$lang_array['exmaple_lang']?></h2>
            <p class="in_function_example"><?=$cont['function_notes']?></p>-->
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