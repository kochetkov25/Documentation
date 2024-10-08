/*
**  File        : ndvig.cpp
**  Authors		:
**  Created on	:
**  Modified on :
**  Description : ndvig
*/

#include "plt_ndvig.h";

extern cls_plt_ndvig  	plt_ndvig;
void drawNdvig(void){
	/*Параметры для отрисовки фрагмента берутся из протокола. Для примера
	параметры заданы константами*/

	/*координата x центра фрагмента*/
	float x_c = 0;
	/*координата y центра фрагмента*/
	float y_c = 0;
	/*обороты двигателя*/
	float PropRev = 75;
	/*ограничение максимально допустимых обортов. Принимает значения 0, 1, 2.*/
	float PropRevLim = 2;
	/*инициализация объектов для формирования изображения в OpenGL и
	последующей отрисовки*/
	if (plt_ndvig.init()){
		/*задание центра фрагмента*/
		plt_ndvig.setXY(x_c, y_c);
		/*отрисовка шкалы в виде текстуры*/
		plt_ndvig.scale();
		/*отрисовка индекса оборотов*/
		plt_ndvig.index(PropRev);
		/*отрисовка индекса ограничителя допустимых оборотов*/
		plt_ndvig.indexLimit(PropRevLim);
		/*отрисовка текстового индекса*/
		plt_ndvig.indexT(PropRev);
	}
}