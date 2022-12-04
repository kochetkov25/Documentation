<?php
/*Данный алгоритм выполняет поиск по запросу пользователя в нужной базе данных (русской
или английской). Затем формируется ответ из базы данных, который уже можно использовать для предоставления информации*/
global $lang_array;
global $link;
global $sql;
global $request;
switch ($_SESSION['enter']){
    case null:
        //var_dump("0");
        //$request="SELECT `function_title`,`type` FROM `connection`";
        //$sql=mysqli_query($link,"SELECT `function_title`,`type` FROM `connection`");
    /*пока пользователь ничего не ввел, выводим сообщение об отсутствии совпадений*/
     ?> 
            <?=$lang_array['none']?>
            <?php
        break;
    case Search:
        //var_dump("1");
    /*если пользователь ввел свой запрос при выбранном английском языке, то делаем запрос в английскую базу данных*/
        $request="SELECT * FROM `connection` WHERE `function_title` REGEXP '$_SESSION[text]'";
        $sql=mysqli_query($link,"SELECT * FROM `connection` WHERE `function_title` REGEXP '$_SESSION[text]'");
        break;
    case Найти:
    /*если пользователь ввел свой запрос при выбранном русском языке, то делаем запрос в русскую базу данных*/
        $request="SELECT * FROM `connection` WHERE `function_title` REGEXP '$_SESSION[text]'";
        $sql=mysqli_query($link,"SELECT * FROM `connection` WHERE `function_title` REGEXP '$_SESSION[text]'");
        break;
}
/*если из базы данных пришел пустой ответ, то есть совпадений не найдено, то выводим соответствующее сообщение. Если же ответ не пустой, то формируем список ближайших совпадений, а также ссылки с необходимой информцией, для перехода на страницу с описанием*/
if(isset($sql)):
        if(mysqli_num_rows($sql)==0):
            ?> 
            <?=$lang_array['none']?>
            <?php
        endif;
            while($count=mysqli_fetch_assoc($sql)):
                //if($count["type"]=="function"):
                    ?>
                    <div class="Expand"></div>
                    <div class="Content">
                    <a href="./description.php?id=<?=$count["function_title"]?>" class="ref_menu"><?=$count["function_title"]?></a></div>
                    <?php
                //endif;
            endwhile;
endif;
            ?>
            <!--
        <a href="./index.php?par=off" class="ref_menu"><h3><?=$lang_array['main_lang']?></h3></a>-->