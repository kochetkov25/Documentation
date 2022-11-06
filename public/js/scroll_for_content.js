document.addEventListener("click",function(e){
	e=window.event;
	var clickedElem=e.target; /*получаем элемент по которому кликнули*/
	if(clickedElem.closest('.ExpandLeaf')){ /*выход из функции, если клик по картинке, которая является дочерней не к узлу дерева, а к ответвлению*/
		return;
	}

	if(!clickedElem.classList.contains('NewExpand')){ /*выход из функции, если клик не по картинке*/
		return;
	}

	if(clickedElem.closest('.ExpandOpen')){ /*смена класса.*/
		document.getElementById(clickedElem.id+0).className="Node IsRoot ExpandClosed";
	}
	else
	{
		document.getElementById(clickedElem.id+0).className="Node IsRoot ExpandOpen";
	}
})
/*смена класса реализована плохо. У картинки по которой пользователь кликает есть id,
у самого блока с предоставлением информации id = id_картинки + 0. Таким образом,
происходит смена класса нужного блока*/