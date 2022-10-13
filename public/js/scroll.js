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
})