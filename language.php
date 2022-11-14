<?php
/*локализационный массив. Здесь содержатся все эллементы верстки, которые должны переводится при смене языка страницы*/
if($_SESSION["lang"]=="en")
{
    $lang_array=array(
        'description_lang'=>"Description",
        'syntax_lang'=>"Syntax",
        'parameters_lang'=>"Parameters",
        "return_values_lang"=>"Return Values",
        "information_lang"=>"Information",
        "contacts_lang"=>"Contacts",
        "documentation_lang"=>"Developer network library",
        "documentation_list_lang"=>"Search through all libraries:",
        "main_lang"=>"Go to the main",
        "search_lang"=>"Search",
        "type_lang"=>"Enter a keyword for search...",
        "main_page_lang"=>"Welcome",
        "main_desc_lang"=>"The Developer network library - is your definitive source for developer documentation. We continue to provide the most up-to-date information for your local help every day.",
        "none"=>"No matches",
        "exmaple_lang"=>"Example"
    );
}
else
{
    $lang_array=array(
        'description_lang'=>"Описание",
        'syntax_lang'=>"Синтаксис",
        'parameters_lang'=>"Параметры",
        "return_values_lang"=>"Графическое отображение",
        "information_lang"=>"Информация",
        "contacts_lang"=>"Контакты",
        "documentation_lang"=>"Техническая документация на графическую библиотеку с использованием OpenGL разработки РПКБ",
        "documentation_list_lang"=>"Поиск по всем библиотекам:",
        "main_lang"=>"Вернуться на главную",
        "search_lang"=>"Найти",
        "type_lang"=>"  Введите ключевое слово для поиска...",
        "main_page_lang"=>"Добро пожаловать",
        "main_desc_lang"=>"Библиотека технической документации РПКБ - это ваш надежный источник информации для разработчика. Каждый день мы предоставляем самую свежую информацию для вашей локальной справки.",
        "none"=>"Совпадений не найдено",
        "exmaple_lang"=>"Пример"
    );
}


