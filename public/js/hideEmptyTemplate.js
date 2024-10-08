window.onload=function(){
    /*получение текста со станицы .H*/
    const textContainerH=document.getElementById('text__btn_1');
    /*получение текста со страницы .CPP*/
    const textContainerCPP=document.getElementById('text__btn_2');
    /*получение всех табов*/
    switchTab=document.getElementsByClassName('contabs__btn');
    /*получение всего контента, связанного с каждым табом*/
    switchContent=document.getElementsByClassName('contabs__content');
    /*получение блока color.h со страницы CPP*/
    colorWrapper=document.getElementById('colorHWrapper');
    datText=document.getElementById('30');
    refToArch=document.getElementById('refToArch');

    /*копирую текст CPP и H в отдельную переменную*/
    textH=textContainerH.textContent;
    textCPP=textContainerCPP.textContent;

    /*скрытие таба и соответствующего ему контента, если в них нет текста*/
    if(textH==0){
        switchTab[0].style.display="none";
        switchTab[0].classList.remove('contabs__btn--active');
        switchContent[0].classList.remove('contabs__content--active');
        switchContent[0].style.display="none";
    }

    if(textCPP==0){
        switchTab[1].style.display="none";
        switchContent[1].style.display="none";
        /*выставляю active оставшемуся табу с примером*/
        switchTab[2].classList.add('contabs__btn--active');
        switchContent[2].classList.add('contabs__content--active');
        /*сокрытие блока color.h выполнено в при условии textCPP, но с тем же успехом, может быть выполнено и выше*/
        colorWrapper.style.display="none";
        datText.style.display="none";
        refToArch.style.display="block";
    }
}
