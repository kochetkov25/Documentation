/*
**  File        : drawMapThm.cpp
**  Authors		:
**  Created on	:
**  Modified on :
**  Description :
*/
#include "lib_common\interface.h"
#include "lib_common\render.h"
#include "lib_thm\lib_thm.h"

void drawTHM(void)
{
	/*создание объекта класса TRender дл€ формировани€ изображени€ в OpenGL*/
	static _CMN::TRender render;
	/*инициализаци€ шрифтов*/
	render.initFonts("./files/fonts/");
	/*создание объекта класса TInParams дл€ задани€ параметров отрисовки карты*/
	LibThm::TInParams parThm;
	/*задание высоты окна просмотра в пиксел€х*/
	parThm.width = 950;
	/*задание ширины окна просмотра в пиксел€х*/
	parThm.height = 950;
	/*задание пути до необходимых файлов: текстур, шрифтов, DAT файлов.*/
	parThm.pchFilesPath = "./files";
	/*задание пути до файлов базы данных*/
	parThm.pchBD_Path = "D:/documentation/Proj_cpp/kai50/BSF";
	/*передача ссылки на созданный объект класса TRender в parMap2d*/
	parThm.pRender = &render;
	/*задание широты летательного аппарата в градусах*/
	parThm.geoVw_deg.fi = 40.05;
	/*задание долготы летательного аппарата в градусах*/
	parThm.geoVw_deg.lm = 40;
	/*задание курса летательного аппарата в градусах*/
	parThm.psiVw_deg = 0;
	/*задание высоты летательного аппарата*/
	parThm.htVw_m = 10000;
	/*устанавливаетс€ €ркость карты от 0 до 100*/
	parThm.bright_perc = 100;
	/*устанавливаютс€ серые цвета карты от 0 до 100*/
	parThm.graysc_perc = 0;
	/*задание прозрачности дл€ фона карты от 0 до 100*/
	parThm.alphaFone_perc = 100;
	/*задание координат наблюдател€ в пиксел€х*/
	parThm.scrPosVw_pix = _CMN::TVec2f(0, 0);
	/*задание масштаба*/
	parThm.scale_m = 80;
	/*устанавливаетс€ поворот координатных осей экрана*/
	parThm.rotation_deg = 0;
	/*если установлен true, карта будет отрисована*/
	parThm.isDraw = 1;
	/*создание объекта класса TParScale дл€ отрисовки масштабной шкалы*/
	LibThm::TParScale scale;
	/*отрисовка количества километров в длинне шкалы*/
	scale.flagM = 1;
	/*задание длинны шкалы*/
	float length = 400;
	scale.dx = length;
	/*установка точки отрисовки (лева€ верхн€€ точка шкалы)*/
	float x = 0;
	float y = -410;
	float z = -1;
	_CMN::TVec3f point(x, y, z);
	scale.p0 = point;
	/*установка цвета шкалы*/
	_CMN::TCol4ub color(255, 0, 0);
	scale.col = color;
	/*передача параметров шкалы дл€ отрисовки*/
	LibThm::setScale(scale);
	/*установка канала отрисовки дл€ карты*/
	LibThm::setChannel(LibThm::Channel_1);
	/*вызов функции дл€ отрисовки карты*/
	LibThm::mainTHM(parThm);
}