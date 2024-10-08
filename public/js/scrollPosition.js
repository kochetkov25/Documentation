/* сохраняет полоэжение скролбара при переходе на новую старницу */
window.onbeforeunload=function()
{
    const menu=document.getElementById('mainMenu');
    localStorage.setItem('menuPos',menu.scrollTop);
}
/* по истечении 100 милисекунд перемещает скроллбар на нужное место */
setTimeout(function scroll(){
    menuPos=localStorage.getItem('menuPos');
    if(menuPos)
    {
        menu=document.getElementById('mainMenu');
        menu.scrollTo(0,menuPos);
    }
},80);
