        <link rel="stylesheet" href="./../../../public/css/descriptionTemplate__style.css">
        <script type="text/javascript" src="./../../../public/js/rollableBlockContent.js"></script>        
        <script type="text/javascript" src="./../../../public/js/colorWords_hideEmpty.js"></script>        
        <div class="name_content">
            <?=$resultItemArray['function_title']?>
            <hr class="hr-double">
        </div>
        <div id="descriptionList" class="description_content">
            <div class="TextContainer">
                <div id="10" class="NewNode NewIsRoot ExpandOpen">
                    <div class="titleWrapper">
                    <div id="1" class="NewExpand"></div>
                    <div class="NewContent"><h2><?=$langArray['templateDescriptionBlock']?></h2></div></div>
                    <div class="TextContainer">
                        <?=$resultItemArray['function_description']?>
                    </div>
                </div>
            </div>
        </div>
        <div id="syntaxList" class="syntax_content">
            <div class="TextContainer">
                <div id="20" class="NewNode NewIsRoot ExpandOpen">
                    <div class="titleWrapper">
                    <div id="2" class="NewExpand"></div>
                    <div class="NewContent"><h2><?=$langArray['templateSyntaxBlock']?></h2></div></div>
                    <div id="code_content" class="TextContainer">
                        <div class="in_syntax_content codeTemplate">
                            <?=$resultItemArray['function_syntax']?>
                        </div>
                    </div>
                </div>
            </div>  
        </div>
        <div class="parameters_content">
            <div class="TextContainer">
                <div id="30" class="NewNode NewIsRoot ExpandOpen">
                    <div class="titleWrapper">
                    <div id="3" class="NewExpand"></div>
                    <div class="NewContent"><h2><?=$langArray['templateParametersBlock']?></h2></div></div>
                    <div class="TextContainer">
                        <div class="in_parameters_content">
                            <?=$resultItemArray['function_parametrs']?>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <div class="return_values_content">
            <div class="TextContainer">
                <div id="40" class="NewNode NewIsRoot ExpandOpen">
                    <div class="titleWrapper">
                    <div id="4" class="NewExpand"></div>
                    <div class="NewContent"><h2><?=$langArray['templateGraphicsBlock']?></h2></div></div>
                    <div class="TextContainer">
                        <div class="in_function_return_values">
                            <?=$resultItemArray['function_return_values']?>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <div id="codeList" class="function_example_content">
            <div class="TextContainer">
                <div id="50" class="NewNode NewIsRoot ExpandOpen">
                    <div class="titleWrapper">
                    <div id="5" class="NewExpand"></div>
                    <div class="NewContent"><h2><?=$langArray['templateExampleBlock']?></h2></div></div>
                    <div id="code_content" class="TextContainer">
                        <div class="in_function_example codeTemplate">
                            <?=$resultItemArray['function_examples']?>
                        </div>
                    </div>
                </div>
            </div>
        </div>
