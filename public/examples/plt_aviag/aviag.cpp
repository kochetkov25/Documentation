/*
**  File        : aviag.cpp
**  Authors		:
**  Created on	:
**  Modified on :
**  Description : aviag
*/

#include "plt_aviag.h"

extern cls_plt_aviag 	plt_aviag;
void drawAviag(void){
	/*Параметры для отрисовки фрагмента берутся из протокола. Для примера
	параметры заданы константами*/

	/*координата x центра фрагмента*/
	float x_c = 0;
	/*координата y центра фрагмента*/
	float y_c = 0;
	/*угол тангажа*/
	float par_Tang = 10;
	/*угол крена*/
	float par_Kren = 15;
	/*позиция закрылок*/
	float flap_position = 1;
	/*смещение горизонтальной директорной планки.
	Задается в пределах -1 - 1*/
	float Dt = 0.1;
	/*смещение вертикальной директорной планки.
	Задается в пределах -1 - 1*/
	float Dk = -0.1;
	/*положение шасси справа*/
	bool chassiRightOn = true;
	/*положение шасси слева*/
	bool chassiLeftOn = true;
	/*положение носовой стойки шасси*/
	bool chassiFrontOn = true;
	/*инициализация объектов для формирования изображения в OpenGL и
	последующей отрисовки*/
	if (plt_aviag.init()){
		/*установка центра фрагмента*/
		plt_aviag.setXY(x_c, y_c);
		/*отрисовка шкалы тангажа в виде текстуры*/
		plt_aviag.scaleTang(par_Tang);
		/*отрисовка шкалы крена в виде текстуры*/
		plt_aviag.scaleKren();
		/*отрисовка силуэта летательного аппарата*/
		plt_aviag.indexLA(par_Kren);
		/*отрисовка закрылок в виде текстуры*/
		plt_aviag.flaps(flap_position, par_Kren);
		/*отрисовка шасси в виде текстуры*/
		plt_aviag.chassi(par_Kren, chassiRightOn, chassiLeftOn, chassiFrontOn);
		/*отрисовка горизонтальной директорной планки*/
		plt_aviag.dirPlankaHor(Dt);
		/*отрисовка вертикальной директорной планки*/
		plt_aviag.dirPlankaVert(Dk);
	}
}