
window.addEventListener("load",function(){

	if(localStorage.getItem("status")!=null)/*если на прошлой странице состояние окна было установлено не null, то на текущей странице устанавливается то же состояние, что и на прошлой*/
	{
		document.getElementById("12").className=localStorage.getItem("status");
	}
});


document.addEventListener("click",function(e){
	e=window.event;
	var clickedElem=e.target; /*получаем элемент по которому кликнули*/
	if(clickedElem.closest('.ExpandLeaf')){ /*выход из функции, если клик по картинке, которая является дочерней не к узлу дерева, а к ответвлению*/
		return;
	}

	if(!clickedElem.classList.contains('Expand')){ /*выход из функции, если клик не по картинке*/
		return;
	}

	if(clickedElem.closest('.ExpandOpen')){ /*смена класса*/
		document.getElementById("12").className="Node IsRoot ExpandClosed";
	}
	else
	{
		document.getElementById("12").className="Node IsRoot ExpandOpen";
	}
	localStorage.setItem("status",document.getElementById("12").className);/*сохранение состояния выпадающего меню (открыто/закрыто)*/
})