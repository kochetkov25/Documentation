document.addEventListener('DOMContentLoaded',()=>{
    const logoutRef=document.getElementById('logoutRef');
    // если пользователь разлогинился, очищаю весь массив localStorage
    if(logoutRef){
        logoutRef.addEventListener("click",function(){
            localStorage.clear();
        });
    }
});