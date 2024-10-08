<div class="wrapperSubExmpTempContent">
    <div class="listOfFilesContent">
        <div class="exmpContent">
            <div class="TextContainer">
                <div id="10" class="NewNode NewIsRoot ExpandOpen">
                    <div class="titleWrapper">
                    <div id="1" class="NewExpand"></div>
                    <div class="NewContent"><h2>Пример</h2>
                        <a href=<?=EXAMPLE_DIR . $resultExmpArray['example_name'] . '/' . str_replace('plt_','',$resultExmpArray['example_name']) . '.cpp'?> download>
                            <button class="copyButton btnEXMP" id="btnEXMP-1">
                                <span class="defText" id="def_1"><?=$langArray['exampleButtonCopy']?></span>
                                <span class="successText" id="succ_1"><?=$langArray['exampleButtonCopied']?></span>
                            </button>
                        </a>
                    </div></div>
                    <div id="code_content" class="TextContainer">
                        <div class="in_syntax_content codeTemplate">
                            <?=$resultExmpArray['cpp_callExample']?>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <div class="colorContent">
            <div class="TextContainer">
                <div id="20" class="NewNode NewIsRoot ExpandClosed">
                    <div class="titleWrapper" id="colorHWrapper">
                    <div id="2" class="NewExpand"></div>
                    <div class="NewContent"><h2>color.h</h2>
                        <a href=<?=EXAMPLE_DIR .'/color.h'?> download>
                            <button class="copyButton btnEXMP" id="btnEXMP-2">
                                <span class="defText" id="def_1"><?=$langArray['exampleButtonCopy']?></span>
                                <span class="successText" id="succ_1"><?=$langArray['exampleButtonCopied']?></span>
                            </button>
                        </a>
                    </div></div>
                    <div id="code_content" class="TextContainer">
                        <div class="in_syntax_content codeTemplate">
                            <?php require_once 'colorTemplate.php' ?>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <div class="symgenContent">
            <div class="TextContainer">
                <div id="30" class="NewNode NewIsRoot ExpandClosed">
                    <div class="titleWrapper">
                    <div id="3" class="NewExpand"></div>
                    <div class="NewContent"><h2>dat.h</h2>
                        <a href=<?=EXAMPLE_DIR . $resultExmpArray['example_name'] . '/' . str_replace('plt_','',$resultExmpArray['example_name']) . '_dat' .'.h'?> download>
                            <button class="copyButton btnEXMP" id="btnEXMP-3">
                                <span class="defText" id="def_1"><?=$langArray['exampleButtonCopy']?></span>
                                <span class="successText" id="succ_1"><?=$langArray['exampleButtonCopied']?></span>
                            </button>
                        </a>
                    </div></div>
                    <div id="code_content" class="TextContainer">
                        <div class="in_syntax_content codeTemplate">
                            <?=$resultExmpArray['dat_description']?>
                        </div>
                    </div>
                </div>
                <!-- Дополнительный блок для реализации примеров карт -->
                <div id="refToArch">
                    По данной <a href=<?=EXAMPLE_DIR .'/files.zip'?> download class="refArch">ссылке</a>, вы можете скачать архив со всеми необходимыми файлами для запуска примера.
                </div>
            </div>
        </div>
    </div>
    <div class="pictureContent">
        <?=$resultExmpArray['graph_description']?>
    </div>
</div>  