/*функция срабатывает, когда страница полностью прогружена*/
window.addEventListener("load",function(){
/*пробегаем по всем возможным id для веток, и меняем их класс на класс из локального хранилища, в случае 
если класс ветки изначально не был null. null означает, что страницу только открыли и менять на ней 
класс не требуется*/
for(var i=0;i<8;i++){
	if(localStorage.getItem("status_"+i)!=null){
		document.getElementById(localStorage.getItem("elem_"+i)).className=localStorage.getItem("status_"+i);
	}
}

});

/*функция срабатывает при клике на любой элемент на странице index или description*/
document.addEventListener("click",function(e){
	e=window.event;

	var clickedElem=e.target; /*получаем элемент по которому кликнули*/

	if(clickedElem.closest('.ExpandLeaf')){ /*выход из функции, если клик по картинке, которая является дочерней не к узлу дерева, а к ответвлению*/
		return;
	}

	if(!clickedElem.classList.contains('Expand')){ /*выход из функции, если клик не по картинке*/
		return;
	}

/*смена класса у контейнера для его открытия/закрытия.
если кликнули по элементу, дочернему к элементу с классом "IsRoot(является веткой) ExpandClosed(ветка закрыта)"
то создаем переменную parent, записываем в нее класс родитель (очевидно, что картинка (+ или -) является 
дочерней к самой ветке.) далее меняем класс родителя на "Node IsRoot ExpandOpen" иначе на "Node IsRoot ExpandClosed"*/
if(clickedElem.closest('.IsRoot') && clickedElem.closest('.ExpandClosed')){
	var parent=clickedElem.parentNode;
	parent.className="Node IsRoot ExpandOpen";
}
else
{
	var parent=clickedElem.parentNode;
	parent.className="Node IsRoot ExpandClosed";
}

/*Чтобы оставить меню открытым при переходе на другую страницу, записываем в локальное хранилище id класса родителя
и имя класса родителя, в последствии будем получать на новой странице класс родитель по id, и менять его класс 
на класс, сохраненный в локальном хранилище*/
	var id=parent.id;
	localStorage.setItem("elem_"+id,id);
	localStorage.setItem("status_"+id,parent.className);/*сохранение состояния выпадающего меню (открыто/закрыто)*/
})