<?php
/*данный файл просто выводит все объекты, которые отноятся к общим функциям и типам данных*/
global $lang_array;
global $link;
global $sql;
global $request;
$request="SELECT `function_title`,`type` FROM `connection` ORDER BY `function_title`";
$sql=mysqli_query($link,"SELECT `function_title`,`type` FROM `connection` ORDER BY `function_title`");
while($count=mysqli_fetch_assoc($sql)):
                if($count["type"]=="common_function"):
                    ?>
                    <div class="Expand"></div>
                    <div class="Content">
                    <a href="./description.php?id=<?=$count["function_title"]?>" class="ref_menu"><?=$count["function_title"]?></a></div>
                    <?php
                endif;
            endwhile;
?>