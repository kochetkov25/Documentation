/*
**  File        : drawMapPrf
**  Authors		:
**  Created on	:
**  Modified on :
**  Description :
*/
#include "lib_map_bpf\lib_map_bpf.h"
#include "lib_common\interface.h"
#include "lib_common\render.h"

void drawMapPRF(void)
{
	/*создание объекта класса TRender для формирования изображения в OpenGL*/
	static _CMN::TRender render;
	/*создание объекта класса TInParams для задания параметров отрисовки карты*/
	LibMapBpf::TInParams parBpf;
	/*задание пути до необходимых файлов: текстур, шрифтов, DAT файлов.*/
	parBpf.pchFilesPath = "./files";
	/*задание пути до файлов базы данных*/
	parBpf.pchBD_Path = "D:/documentation/Proj_cpp/kai50/BPF";
	/*передача ссылки на созданный объект класса TRender в parMap2d*/
	parBpf.pRender = &render;
	/*задание высоты окна просмотра в пикселях*/
	parBpf.width = 950;
	/*задание ширины окна просмотра в пикселях*/
	parBpf.height = 950;
	/*задание курса летательного аппарата в градусах*/
	parBpf.psiVw_deg = 0;
	/*задание широты летательного аппарата в градусах*/
	parBpf.geoVw_deg.fi = 43.1;
	/*задание долготы летательного аппарата в градусах*/
	parBpf.geoVw_deg.lm = 44;
	/*задание масштаба*/
	parBpf.scale_m = 100;
	/*вызов функции для отрисовки карты*/
	LibMapBpf::mainBpf(parBpf);
}