/*
**  File        : drawMap2d.cpp
**  Authors		:
**  Created on	:
**  Modified on :
**  Description :
*/
#include "lib_common\interface.h"
#include "lib_map2d\lib_map2d.h"
#include "lib_common\render.h"

void drawMap2d(void)
{
	/*создание объекта класса TRender дл€ формировани€ изображени€ в OpenGL*/
	static _CMN::TRender render;
	/*инициализаци€ шрифтов*/
	render.initFonts("./files/fonts/");
	/*создание объекта класса TInParams дл€ задани€ параметров отрисовки карты*/
	LibMap2d::TInParams parMap2d;
	/*задание высоты окна просмотра в пиксел€х*/
	parMap2d.width = 950;
	/*задание ширины окна просмотра в пиксел€х*/
	parMap2d.height = 950;
	/*задание пути до необходимых файлов: текстур, шрифтов, DAT файлов.*/
	parMap2d.pchFilesPath = "./files";
	/*задание пути до файлов базы данных*/
	parMap2d.pchBD_Path = "D:/documentation/Proj_cpp/kai50/BMF";
	/*передача ссылки на созданный объект класса TRender в parMap2d*/
	parMap2d.pRender = &render;
	/*задание размера пиксел€ экрана*/
	parMap2d.scrPixel_mm = 0.15f;
	/*задание широты летательного аппарата в градусах*/
	parMap2d.geoVw_deg.fi = 50;
	/*задание долготы летательного аппарата в градусах*/
	parMap2d.geoVw_deg.lm = 50;
	/*задание курса летательного аппарата в градусах*/
	parMap2d.psiVw_deg = 0;
	/*слои отображени€ карты*/
	/*изолинии рельефа*/
	parMap2d.layers.relief = 1;
	/*гидрографи€*/
	parMap2d.layers.gidro = 1;
	/*города*/
	parMap2d.layers.towns = 1;
	/*промышленные объекты*/
	parMap2d.layers.industry = 1;
	/*дороги*/
	parMap2d.layers.roads = 1;
	/*растительность*/
	parMap2d.layers.forest = 1;
	/*границы*/
	parMap2d.layers.bound = 1;
	/*подписи*/
	parMap2d.layers.scripts = 1;
	/*математическа€ основа*/
	parMap2d.layers.mat = 1;
	/*устанавливаетс€ €ркость карты от 0 до 100*/
	parMap2d.bright_perc = 100;
	/*устанавливаютс€ серые цвета карты от 0 до 100*/
	parMap2d.graysc_perc = 0;
	/*задание координат наблюдател€ в пиксел€х*/
	parMap2d.scrPosVw_pix = _CMN::TVec2f(0, 0);
	/*задание прозрачности дл€ фона карты от 0 до 100*/
	parMap2d.alphaFone_perc = 100;
	/*задание прозрачности дл€ объектов карты от 0 до 100*/
	parMap2d.alphaObj_perc = 100;
	/*задание масштаба*/
	parMap2d.scale_m = 180;
	/*если установлен true, карта будет отрисована*/
	parMap2d.isDraw = 1;
	/*установка канала отрисовки дл€ карты*/
	LibMap2d::setChannel(LibMap2d::Channel_1);

	/*создание объекта класса TParScale дл€ отрисовки масштабной шкалы*/
	LibMap2d::TParScale scale;
	/*отрисовка количества километров в длинне шкалы*/
	scale.flagM = 1;
	/*отрисовка установленного масштаба*/
	scale.flagS = 1;
	/**/
	scale.flagZ = 0;
	/*задание длинны шкалы*/
	float length = 400;
	scale.dx = length;
	/*установка точки отрисовки (лева€ верхн€€ точка шкалы)*/
	float x = 0;
	float y = -410;
	float z = -1;
	_CMN::TVec3f point(x,y,z);
	scale.p0 = point;
	/*установка цвета шкалы*/
	_CMN::TCol4ub color(255, 0, 0);
	scale.col = color;
	/*передача параметров шкалы дл€ отрисовки*/
	LibMap2d::setScale(scale);
	/*вызов функции дл€ отрисовки карты*/
	LibMap2d::main2D(parMap2d);
}