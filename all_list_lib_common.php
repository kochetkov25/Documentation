<?php
/*данный файл просто выводит абсолютно все содержащиеся в библиотеке функции. Это нужно для 
реализации разворачиваемого списка в левой части экрана*/
global $lang_array;
global $link;
global $sql;
global $request;
$request="SELECT `function_title`,`type` FROM `connection`";
$sql=mysqli_query($link,"SELECT `function_title`,`type` FROM `connection`");
while($count=mysqli_fetch_assoc($sql)):
                if($count["type"]=="function"):
                    ?>
                    <div class="Expand"></div>
                    <div class="Content">
                    <a href="./description.php?id=<?=$count["function_title"]?>" class="ref_menu"><?=$count["function_title"]?></a></div>
                    <?php
                endif;
            endwhile;
?>