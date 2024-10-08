<link rel="stylesheet" href="./../../../public/css/descriptionTemplate__style.css">
<link rel="stylesheet" href="./../../../public/css/exampleTemplate__style.css">
<link rel="stylesheet" href="./../../../public/css/subExampleTempContent__style.css">
<link rel="stylesheet" href="./../../../public/css/descriptionTemplate__style.css">
<script type="text/javascript" src="./../../../public/js/switchTabsContent.js"></script>
<script type="text/javascript" src="./../../../public/js/copyButtonEvent.js"></script>
<script type="text/javascript" src="./../../../public/js/rollableBlockContent.js"></script>
<script type="text/javascript" src="./../../../public/js/hideEmptyTemplate.js"></script>
<div class="contabs">
    <ul class="contabs__list">
        <li class="contabs__item"><button class="contabs__btn contabs__btn--active" data-contabs-path="h__file"><?=$langArray['tabsItemExmpH']?></button></li>
        <li class="contabs__item"><button class="contabs__btn" data-contabs-path="cpp__file"><?=$langArray['tabsItemExmpCPP']?></button></li>
        <li class="contabs__item"><button class="contabs__btn" data-contabs-path="set__file"><?=$langArray['tabsItemExmpGraph']?></button></li>
        <div class="contabsTitle">
            <?=$resultExmpArray['h_title']?>
        </div>
    </ul>
        <div class="contabs__content contabs__content--active" data-contabs-target="h__file">
            <div class="file__content">
                <p class="file__contetn__title">
                    <!-- HERE PUT h_title -->
                    <!-- <?=$resultExmpArray['h_title']?> -->
                </p>
                <a class="def" href=<?=EXAMPLE_DIR . $resultExmpArray['example_name'] . '/' . $resultExmpArray['example_name'] . '.h'?> download>
                    <button class="copyButton" id="btn_1">
                        <span class="defText" id="def_1"><?=$langArray['exampleButtonCopy']?></span>
                        <span class="successText" id="succ_1"><?=$langArray['exampleButtonCopied']?></span>
                    </button>
                </a>
                <div id="text__btn_1" class="file__contetn__description codeTemplate">
                <!-- HERE PUT h_description -->
                <?=$resultExmpArray['h_description']?>
                </div>
            </div>
        </div>
        <div class="contabs__content" data-contabs-target="cpp__file">
            <div class="file__content">
                <p class="file__contetn__title">
                    <!-- HERE PUT cpp_title -->
                    <!-- <?=$resultExmpArray['cpp_title']?> -->
                </p>
                <a class="def" href=<?=EXAMPLE_DIR . $resultExmpArray['example_name'] . '/' . $resultExmpArray['example_name'] . '.cpp'?> download>
                    <button class="copyButton" id="btn_2">
                        <span class="defText" id="def_1"><?=$langArray['exampleButtonCopy']?></span>
                        <span class="successText" id="succ_1"><?=$langArray['exampleButtonCopied']?></span>
                    </button>
                </a>
                <div id="text__btn_2" class="file__contetn__description codeTemplate">
                    <!-- HERE PUT cpp_description -->
                    <?=$resultExmpArray['cpp_description']?>
                </div>
            </div>                
        </div>
        <div class="contabs__content" data-contabs-target="set__file">
            <div class="file__content">
                <p class="file__contetn__title">
                    <!-- HERE PUT graph_title -->
                    <!-- <?=$resultExmpArray['graph_title']?> -->
                </p>
                <div class="file__contetn__description">
                    <!-- HERE PUT graph_description -->
                    <?php require_once 'subExampleTempContent.php' ?>
                </div>
            </div>                
        </div>
</div>