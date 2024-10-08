window.onload=function(){
	const textContainer=document.querySelectorAll('.TextContainer');/*получаю все элементы с классом текстконтейнер*/
	textContainer.forEach(el=> /*пробежать по всем элементам*/ 
		{
			if(!el.parentElement.closest(".NewNode"))/*проверяем, что элемент не является дочернем к NewNode,*/
			{
				/*вытаскиваю весь текст из элемента, затем убираю все пробелы и табуляцию*/
				var text=el.lastElementChild.lastElementChild.textContent;
				var new_text=text.replace(/\s/g,"")
				if(new_text==0)/*если получилась строка с нулевой длинной, у класса родителя выставляю дисплей none*/
				{
					el.parentElement.style.display="none";
				}
			}
		});
}
