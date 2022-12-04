/*замена цвета у некоторых слов, для большей наглядности.*/

window.onload=function(){
	/*Если один из блоков, предназначенных для текста, пуст, то он не будет отображаться*/
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


	/*замена цвета у ключевых слов в блоках синтакс и пример*/
	var elem = document.querySelector('#codeList');
		for(var i=0;i<2;i++){
			if(i==1){
				elem=document.querySelector('#syntaxList');
			}
		/*Замена цвета у TVec, TRec.*/
		elem.innerHTML = elem.innerHTML.replaceAll('TVec2f','<span style="color: #3DC999;">TVec2f</span>');
		elem.innerHTML = elem.innerHTML.replaceAll('TRect2f','<span style="color: #3DC999;">TRect2f</span>');
		elem.innerHTML = elem.innerHTML.replaceAll('TRect4f','<span style="color: #3DC999;">TRect4f</span>');
		/*Замена цвета комментария*/
		elem.innerHTML = elem.innerHTML.replaceAll('/*','<span style="color: green;">/*');
		elem.innerHTML = elem.innerHTML.replaceAll('*/','*/</span>');
		elem.innerHTML = elem.innerHTML.replaceAll('}','}<br><br>');
		/*Замена цветов типов данных*/
		elem.innerHTML = elem.innerHTML.replaceAll('void','<span style="color: blue;">void</span>');
		elem.innerHTML = elem.innerHTML.replaceAll('float','<span style="color: blue;">float</span>');
		elem.innerHTML = elem.innerHTML.replaceAll(' int','<span style="color: blue;"> int</span>');
		elem.innerHTML = elem.innerHTML.replaceAll('double','<span style="color: blue;">double</span>');
		/*Замена цвета TRender TInterface*/
		elem.innerHTML = elem.innerHTML.replaceAll(':TRender',':<span style="color: #3DC999;">TRender</span>');
		elem.innerHTML = elem.innerHTML.replaceAll(':TInterface',':<span style="color: #3DC999;">TInterface</span>');
		}
}

