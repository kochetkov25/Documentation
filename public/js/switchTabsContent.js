/*функция для отображения необходимого контента по клику на один из табов (относится к табам
на странице templates.php*/
document.addEventListener('DOMContentLoaded', ()=>{
	/*получение необходимых классов*/
	const tabs= document.querySelector('.contabs');
	const tabsBtn=document.querySelectorAll('.contabs__btn');
	const tabsContent=document.querySelectorAll('.contabs__content');
	/*если tabs существует, то вешаю на tabs обработку события клик.*/
	if(tabs){
		tabs.addEventListener('click',(e)=>{
			if(e.target.classList.contains('contabs__btn')){
				/*получаю текущий path у tabs и передаю в функцию tabsHandler*/
				const tabsPath=e.target.dataset.contabsPath;
				tabsHandler(tabsPath);
			}
		});
	}

	/*функция tabsHandler отвечает за установку active на нужный таб и контент*/
const tabsHandler = (path) => {
	/*пробегаю по всем табам и убираю класс active, далее вешаю active на таб с полученным path*/
	tabsBtn.forEach(el => {el.classList.remove('contabs__btn--active')});
	document.querySelector(`[data-contabs-path="${path}"]`).classList.add('contabs__btn--active');

	/*пробегаю по всем блокам контента и убираю класс active, далее вешаю active на контент с полученным path*/
	tabsContent.forEach(el => {el.classList.remove('contabs__content--active')});
	document.querySelector(`[data-contabs-target="${path}"]`).classList.add('contabs__content--active');
};	
});

