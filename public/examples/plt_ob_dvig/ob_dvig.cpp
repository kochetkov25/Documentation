/*
**  File        : ob_dvig.cpp
**  Authors		:
**  Created on	:
**  Modified on :
**  Description : ob_dvig
*/

#include "plt_ob_dvig.h"

extern cls_plt_ob_dvig  	plt_ob_dvig;
void drawOb_dvig(void){
	/*Параметры для отрисовки фрагмента берутся из протокола. Для примера
	параметры заданы константами*/

	/*координата x центра фрагмента*/
	float x_c = 0;
	/*координата y центра фрагмента*/
	float y_c = 0;
	/*положение РУД*/
	float pQ_PWL = 70;
	/*мощность двигателя*/
	float power = 70;
	/*инициализация объектов для формирования изображения в OpenGL и
	последующей отрисовки*/
	if (plt_ob_dvig.init()){
		/*установка центра фрагмента*/
		plt_ob_dvig.setXY(x_c, y_c);
		/*отрисовка шкалы в виде текстуры*/
		plt_ob_dvig.scale();
		/*отрисовка индексов номинальных значений мощности двигателя*/
		plt_ob_dvig.indexLimit();
		/*отрисовка указателя положения РУД*/
		plt_ob_dvig.indexRud(pQ_PWL);
		/*отрисовка текстового индекса*/
		plt_ob_dvig.indexT(power);
		/*отрисовка стрелки мощности в виде текстуры*/
		plt_ob_dvig.index(power);
	}
}