/*функция для табов в меню*/
document.addEventListener('DOMContentLoaded', ()=>{
	/*получение необходимых классов*/
	const tabs_2= document.querySelector('.tabs');
	const tabsBtn_2=document.querySelectorAll('.tabs__btn');
	const tabsContent_2=document.querySelectorAll('.tabs__content');
	/*получение uri страницы, путем разделения url с помошью разделителей '?' и '/'*/
	var uri=document.URL.split('/');
	uri=uri[uri.length-1].split('/');
	uri=uri[uri.length-1].split('?');
	/*функция tabsHandler отвечает за установку active на нужный таб и контент*/
const tabsHandler = (path) => {
	/*пробегаю по всем табам и убираю класс active, далее вешаю active на таб с полученным path*/
	tabsBtn_2.forEach(ele => {ele.classList.remove('tabs__btn--active')});
	document.querySelector(`[data-tabs-path="${path}"]`).classList.add('tabs__btn--active');

	/*пробегаю по всем блокам контента и убираю класс active, далее вешаю active на контент с полученным path*/
	tabsContent_2.forEach(ele => {ele.classList.remove('tabs__content--active')});
	document.querySelector(`[data-tabs-target="${path}"]`).classList.add('tabs__content--active');
};
/*в блоке switch/case прописаны триггеры, при которых должно происходить переключение табов.
Текущее состояние табов помещается в локальное хранилище, чтобы при переходе на страницу, для 
которой нет триггера, состояние нажатого таба сохранялось*/
	 	switch(uri[0]){
			case "LibrariesMain":
				localStorage.removeItem("current_path");
				localStorage.setItem("current_path","h__file");
				break;
			case "ExampleMain":
				localStorage.removeItem("current_path");
				localStorage.setItem("current_path","cpp__file");
				break;
			case '':
				localStorage.removeItem("current_path");
				localStorage.setItem("current_path","h__file");
				break;
			case 'Description':
				localStorage.removeItem("current_path");
				localStorage.setItem("current_path","h__file");
				break;
		}
		tabsHandler(localStorage.getItem("current_path"));
});