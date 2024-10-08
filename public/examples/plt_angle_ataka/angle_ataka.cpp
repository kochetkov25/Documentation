/*
**  File        : plt_angle_ataka.h
**  Authors		:
**  Created on	:
**  Modified on :
**  Description : plt_angle_ataka
*/

#include "plt_angle_ataka.h"

extern cls_plt_angle_ataka plt_angle_ataka;
void drawAngle_ataka(void)
{
	/*Параметры для отрисовки фрагмента берутся из протокола. Для примера
	параметры заданы константами*/
	/*координата x центра фрагмента*/
	float x_c = 0;
	/*координата y центра фрагмента*/
	float y_c = 0;
	/*угол атаки*/
	float angle_attak = 10;
	/*максимально допустимый угол атаки*/
	float angle_attak_max = 12;
	/*инициализация объектов для формирования изображения в OpenGL и
	последующей отрисовки*/
	if (plt_angle_ataka.init()){
		/*установка центра фрагмента*/
		plt_angle_ataka.setXY(0, 0);
		/*отрисовка сектора критических углов атаки*/
		plt_angle_ataka.AngleAttakCritical(12);
		/*отрисовка шкалы в виде текстуры*/
		plt_angle_ataka.scale();
		/*отрисовка текстового индекса*/
		plt_angle_ataka.indexT(cls_plt_angle_ataka::ELocation::_e_Up, 10);
		/*отрисовка стрелки в виде текстуры*/
		plt_angle_ataka.index(10);
		/*отрисовка символа альфа в виде текстуры*/
		plt_angle_ataka.AngleAttakSym();
	}
}
