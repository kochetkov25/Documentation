<!DOCTYPE html>
<html lang>
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>RDC</title>
    <link rel="stylesheet" href="./../../../public/css/mainPage__style.css">
    <link rel="stylesheet" href="./../../../public/css/libraryMain__style.css">
    <script type="text/javascript" src="./../../../public/js/rollableBlockMenu.js"></script>
    <script type="text/javascript" src="./../../../public/js/switchTabsMenu.js"></script>
    <script type="text/javascript" src="./../../../public/js/youAreHere.js"></script>
    <script type="text/javascript" src="./../../../public/js/scrollPosition.js"></script>
    <script type="text/javascript" src="./../../../public/js/unsetLocalStorage.js"></script>
    <link rel="icon" href="su-27.png" type="image/x-icon">
</head>
<body>
<header class="header">
        <div class="header__container">
            <a href="/LibrariesMain" class="header__logo" id="mainLogo">
                <img class="main__img" src="./../../../public/img/Union_2.svg">
            </a>

            <div class="header__title">
                <?=$this->langArray['headerTitle']?>
            </div>

            <div class="language_switch">
                <div class="logout_form">
                    <div class="user_login">
                        <?php
                            use Kkochetkov\RdcCom\core\Session;
                            $session=new Session();
                            echo $session->getSession('mainUserLogin'); 
                        ?>
                    </div>
                    <a class="ref_logout" href="/?logout_status=1" id="logoutRef">Выйти</a>
                </div>

                <form class="select_lang_form" method="post" action=<?=$_SERVER['REQUEST_URI']?> class="change-lag">
                    <input name="language" type="submit" value="ru" id="submit" class="ru_btn">
                    <input name="language" type="submit" value="en" id="submit" class="eng_btn" disabled>
                </form>
            </div>
        </div>
    </header>
    <main class="main">
        <section class="hero">
            <div class="heroWrapper">
                <div class="heroMenu" id="mainMenu">
                    <div class="searchBar">
                        <div class="searchBar__title">
                            <?=$this->langArray['searchTitle']?>
                        </div>
                        <div class="searchBar__formWrapper">
                            <form action=<?=$_SERVER['REQUEST_URI']?> method="post" class="searchBar__form">
                                <input type="text" name="user_request" placeholder="Введите запрос" class="searchBar__formInput">
                                <input type="submit" value=<?=$this->langArray['searchButton']?> class="searchBar__formBtn">
                            </form>
                        </div>
                    </div>
                    <div class="searchBar__resultList">
                        <ul class="MainContainer">
                            <li class="Node ExpandLeaf">
                                <?php $this->printAllSearchResults($outputRenderArr["user_request__RenderArr"]); ?>
                            </li>
                        </ul>
                    </div>
                    <div class="navigationList">
                        <div class="tabs">
                            <ul class="tabs__list">
                                <li class="tabs__item"><button onclick="window.location.href='/LibrariesMain';" class="tabs__btn tabs__btn--active" data-tabs-path="h__file"><?=$this->langArray['tabsItemLib']?></button></li>
                                <li class="tabs__item"><button onclick="window.location.href='/ExampleMain';" class="tabs__btn" data-tabs-path="cpp__file"><?=$this->langArray['tabaItemExmp']?></button></li>
                            </ul>
                            <div class="tabs__content tabs__content--active" data-tabs-target="h__file">
                                        <ul class="MainContainer">
                                            <li id="0" class="Node_0 IsRoot ExpandClosed">
                                                    <div class="Expand"></div>
                                                    <div class="ConDesc">lib_common</div>
                                                    <ul class="MainContainer">
                                                        <li id="1" class="Node_1 IsRoot ExpandClosed" style="margin-left: 20px">
                                                            <div class="Expand"></div>
                                                            <div class="ConDesc"><?=$this->langArray['commonFunc']?></div>
                                                            <ul class="MainContainer">
                                                                <li class="Node ExpandLeaf">
                                                                    <?php $this->printAllTitles($outputRenderArr["common_fun__RenderArr"]); ?>
                                                                </li>
                                                            </ul>
                                                        </li>

                                                        <li id="2" class="Node_2 IsRoot ExpandClosed" style="margin-left: 20px">
                                                            <div class="Expand"></div>
                                                            <div class="ConDesc"><?=$this->langArray['graphFunc']?></div>
                                                            <ul class="MainContainer">
                                                                <li class="Node ExpandLeaf">
                                                                    <?php $this->printAllTitles($outputRenderArr["graph_func__RenderArr"]) ?>
                                                                </li>
                                                            </ul>
                                                        </li>
                                                    </ul>   
                                            </li>
                                        </ul>           

                                        <ul class="MainContainer">
                                            <li id="3" class="Node_3 IsRoot ExpandClosed">
                                                    <div class="Expand"></div>
                                                    <div class="ConDesc">lib_map2d</div>
                                                    <ul class="MainContainer">
                                                        <li class="Node ExpandLeaf">
                                                            <?php $this->printAllTitles($outputRenderArr["map2d__RenderArr"]) ?>
                                                        </li>
                                                    </ul>   
                                            </li>
                                        </ul> 

                                        <ul class="MainContainer">
                                            <li id="4" class="Node_4 IsRoot ExpandClosed">
                                                    <div class="Expand"></div>
                                                    <div class="ConDesc">lib_map3d</div>
                                                    <ul class="MainContainer">
                                                        <li class="Node ExpandLeaf">
                                                            <?php $this->printAllTitles($outputRenderArr["map3d__RenderArr"]) ?>
                                                        </li>
                                                    </ul>   
                                            </li>
                                        </ul>   
                                        
                                        <ul class="MainContainer">
                                            <li id="5" class="Node_5 IsRoot ExpandClosed">
                                                    <div class="Expand"></div>
                                                    <div class="ConDesc">lib_thm</div>
                                                    <ul class="MainContainer">
                                                        <li class="Node ExpandLeaf">
                                                            <?php $this->printAllTitles($outputRenderArr["mapTHM__RenderArr"]) ?>
                                                        </li>
                                                    </ul>   
                                            </li>
                                        </ul>

                                        <ul class="MainContainer">
                                            <li id="6" class="Node_6 IsRoot ExpandClosed">
                                                    <div class="Expand"></div>
                                                    <div class="ConDesc">lib_map_bpf</div>
                                                    <ul class="MainContainer">
                                                        <li class="Node ExpandLeaf">
                                                            <?php $this->printAllTitles($outputRenderArr["mapBPF__RenderArr"]) ?>
                                                        </li>
                                                    </ul>   
                                            </li>
                                        </ul>

                                        <ul class="MainContainer">
                                            <li id="7" class="Node_7 IsRoot ExpandClosed">
                                                    <div class="Expand"></div>
                                                    <div class="ConDesc">lib_geo_proj</div>
                                                    <ul class="MainContainer">
                                                        <li class="Node ExpandLeaf">
                                                            <?php $this->printAllTitles($outputRenderArr["geoProj__RenderArr"]) ?>
                                                        </li>
                                                    </ul>   
                                            </li>
                                        </ul>
                            </div>
                            <div class="tabs__content" data-tabs-target="cpp__file">
                                <div class="file__content">
                                    <?php require_once 'exampleListMainPage.php' ?>
                                </div>                
                            </div>
                        </div>                 
                    </div>
                </div>
                <div class="heroContent" id="MainContentContainer">
                    <?php
                        use Kkochetkov\RdcCom\core\MainRourter;
                        MainRourter::enable($outputRenderArr["item_name__RenderArr"],$outputRenderArr["exmp_name__RenderArr"],$this->langArray); 
                    ?>
                </div>
            </div>
        </section>
    </main>
</body>
</html>