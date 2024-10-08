window.addEventListener("load",function(){
    const copyButtonEvent = (buttonID) =>
    {
        var button=document.getElementById(buttonID);
	    if(button){
		    button.addEventListener('click',function(){
                /* по клику на кнопку, меняю у надписей дисплей и ставлю кнопке класс active */
			    button.children[0].style.display="none";
			    button.children[1].style.display="block";
                button.classList.add('active');

                // /* получаю текст соответсвующей кнопки путем конкатенации строки text__ и айди кнопки */
                // var text=document.getElementById("text__"+buttonID);
                // if(text){
                //     /* ряд манипуляций, чтобы записаться текст в буффер обмена */
                //     text=text.textContent;
                //     var textArea=document.createElement("textarea");
                //     textArea.value=text;
                //     textArea.style.top=0;
                //     textArea.style.left=0;
                //     textArea.style.position="fixed";
                //     document.body.appendChild(textArea);
                //     textArea.focus();
                //     textArea.select();
                //     document.execCommand('copy');
                //     document.body.removeChild(textArea);
                // }

                /* по истечению 2 секунд возврашаю в исходное положение кнопку и надпись */
			    setTimeout(function(){
				    button.children[0].style.display="block";
				    button.children[1].style.display="none";
                    button.classList.remove('active');
			    },2000);
		    });
	    }
    }
    copyButtonEvent('btn_1');
    copyButtonEvent('btn_2');
    copyButtonEvent('btnEXMP-1');
    copyButtonEvent('btnEXMP-2');
    copyButtonEvent('btnEXMP-3');
});