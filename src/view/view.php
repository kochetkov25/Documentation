<?php
namespace Kkochetkov\RdcCom\view;

class View{
    public $langArray;
    private static $refID=0;
    private static $searchID=0;
    /* при создании класса view определяем локализационный массив */
    public function __construct($currentLanguage){
        if($currentLanguage=="en")
            {
                $this->langArray=array(
                    'headerTitle'=>'Technical documentation for the RDC graphics library using OpenGL.',
                    'tabsItemLib'=>'Libraries',
                    'tabaItemExmp'=>'Examples',
                    'commonFunc'=>'Common functions and data types',
                    'graphFunc'=>'Graphical functions',
                    'searchPlaceholder'=>'Enter a request',
                    'searchButton'=>'Search',
                    'searchTitle'=>'Look for:',
                    'libraryTitle'=>'Library of functions.',
                    'libraryDescriptionShort'=>'A&nbsp;detailed description of&nbsp;all the functions and data types contained in&nbsp;the library.',
                    'exampleTitle'=>'A list of examples.',
                    'exampleDescriptionShort'=>'A&nbsp;list of&nbsp;illustrative examples of&nbsp;fragments of&nbsp;scales for the formation of&nbsp;display frames.',
                    'templateDescriptionBlock'=>'Description',
                    'templateSyntaxBlock'=>'Syntax',
                    'templateParametersBlock'=>'Parameters',
                    'templateGraphicsBlock'=>'Graphical representation',
                    'templateExampleBlock'=>'Example',
                    'tabsItemExmpH'=>'.H',
                    'tabsItemExmpCPP'=>'.CPP',
                    'tabsItemExmpGraph'=>'Example',
                    'exampleButtonCopy'=>'Download',
                    'exampleButtonCopied'=>'Success!'
                );
            }else{
                $this->langArray=array(
                    'headerTitle'=>'Техническая документация на&nbsp;графическую библиотеку РПКБ с&nbsp;использованием OpenGL.',
                    'tabsItemLib'=>'Библиотеки',
                    'tabaItemExmp'=>'Примеры',
                    'commonFunc'=>'Общие функции и типы данных',
                    'graphFunc'=>'Графические функции',
                    'searchPlaceholder'=>'Введите ваш запрос',
                    'searchButton'=>'Найти',
                    'searchTitle'=>'Поиск:',
                    'libraryTitle'=>'Библиотека функций.',
                    'libraryDescriptionShort'=>'В данном разделе находится подробное описание графических функций из каждой библиотеки.',
                    'exampleTitle'=>'Перечень примеров.',
                    'exampleDescriptionShort'=>'Список наглядных примеров фрагментов шкал и графических карт для формирования индикационных кадров.',
                    'templateDescriptionBlock'=>'Описание',
                    'templateSyntaxBlock'=>'Синтаксис',
                    'templateParametersBlock'=>'Параметры',
                    'templateGraphicsBlock'=>'Графическое отображение',
                    'templateExampleBlock'=>'Пример',
                    'tabsItemExmpH'=>'.H',
                    'tabsItemExmpCPP'=>'.CPP',
                    'tabsItemExmpGraph'=>'Пример',
                    'exampleButtonCopy'=>'Загрузть',
                    'exampleButtonCopied'=>'Успешно!' 
                );
            }
    }
    /* вывод всех заголовков в виде ссылок */
    public function printAllTitles($resultArray){
        if(is_array($resultArray)){
                foreach($resultArray as $value){
                    ?>
                    <div class="Expand"></div>
                    <div class="ConDesc">
                        <a id=<?=self::$searchID++ . 'refID'?> onclick="returnID(this.id)" class="ref_menu" href="/Description?item_name=<?=urlencode($value)?>">
                            <?=$value?>
                        </a>
                    </div>
                <?php 
            }
        }
    }
    /* вывод всех заголовков, которые были найдены по ключевому слову в виде ссылок */
    public function printAllSearchResults($resultSearchArray){
        if(is_array($resultSearchArray)){
            if(empty($resultSearchArray)){
                echo 'Ничего не найдено';
            }else{
                foreach($resultSearchArray as $value){
                    ?>
                    <div class="Expand"></div>
                    <div class="ConDesc">
                        <a id=<?=self::$refID++ . 'searchID'?> onclick="returnID(this.id)" class="ref_menu" href="/Description?item_name=<?=urlencode($value)?>">
                            <?=$value?>
                        </a>
                    </div>
                <?php }
            }
        }
    }
    /* отображение главной страницы */
    public function render($outputRenderArr=null)
    {
        require_once __DIR__ . '/templates/MainPage.php';
    }
}
?>