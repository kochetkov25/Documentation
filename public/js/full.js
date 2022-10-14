	window.onload=function(){
        if(document.getElementsByClassName("in_function_return_values")[0].textContent==""){
            document.getElementsByClassName("return_values_content")[0].style.display="none";
        } 

        if(document.getElementsByClassName("in_function_example")[0].textContent==""){
        	document.getElementsByClassName("function_example_content")[0].style.display="none";
        }

        if(document.getElementsByClassName("in_parameters_content")[0].textContent==""){
        	document.getElementsByClassName("parameters_content")[0].style.display="none";
        }

        if(document.getElementsByClassName("in_syntax_content")[0].textContent==""){
        	document.getElementsByClassName("syntax_content")[0].style.display="none";
        }
    };
/*очень простая функция, если блоки "возвращаемые значения","пример" и "синтаксис"пустые, то
 эти блоки выводится не будут"*/
