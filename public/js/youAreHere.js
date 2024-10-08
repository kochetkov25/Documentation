function returnID(clickID){
    uri=document.URL.split('/');
    localStorage.setItem('refIDKey',clickID);
}

document.addEventListener('DOMContentLoaded',()=>{
    // получаю текущий uri
    var uri=document.URL.split('/');
	uri=uri[uri.length-1].split('/');
	uri=uri[uri.length-1].split('?');

    // выполняю закрашивание элемента, только в случае, если пользователь  
    // находится на странице описания
    if(localStorage.getItem('refIDKey')){
        if(uri[0] == 'Description'){
            document.getElementById(localStorage.getItem('refIDKey')).classList.add('activeRef');
        }
    }
});

