

#include "plt_kurs.h"
extern cls_plt_kurs  	plt_kurs;

void drawKurs(){
	/*Параметры для отрисовки фрагмента берутся из протокола. Для примера
	параметры заданы константами*/

	/*координата x центра фрагмента*/
	float x_c = 0;
	/*координата y центра фрагмента*/
	float y_c = 0;
	/*магнитный курс*/
	float M_cur = 0;
	/*истинный курс*/
	float true_cur = 50;
	/*параметр для выбора курса*/
	bool pr_M = 0;
	/*азимут РМ РСБН*/
	float AzRsbn = 90;
	/*угол сноса*/
	float TrackAngle = 30;
	/*заданный курс*/
	float CourseGiv = 60;
	/*заданный путевой курс*/
	float CourseGivTrack = 45;
	/*угол*/
	float parGrad = -10;
	/*горизонтальное отклонение*/
	float parOtklGor = -20;
	/*вертикальное отклонение*/
	float parOtklVert = 40;
	/*цвет*/
	_CMN::TCol3f color = YELLOW;
	/*инициализация объектов для формирования изображения в OpenGL и
	последующей отрисовки*/
	if (plt_kurs.init()){
		/*установка координат центра фрагмента*/
		plt_kurs.setXY(x_c, y_c);
		/*установка коэффициента шкалы*/
		plt_kurs.setKurs(M_cur, true_cur, pr_M);
		/*отрисовка шкалы*/
		plt_kurs.scale();
		/*отрисовка стрелочного указателя пеленга РМ РСБН*/
		plt_kurs.indexAzRsbn(AzRsbn);
		/*отрисовка указателя угла сноса*/
		plt_kurs.indexDriftAngle(TrackAngle);
		/*отрисовка текущего индекса*/
		plt_kurs.indexTek();
		/*отрисовка заданного индекса*/
		plt_kurs.indexZad(CourseGiv);
		/*отрисовказаданного ПУ*/
		plt_kurs.indexZadPU(CourseGivTrack);
		/*отрисовка углового индекса*/
		plt_kurs.indexAngle(parGrad, color);
		/*установка параметров для шкалы отклонений*/
		plt_kurs.setParamOtkl();
		/*отрисовка шкалы отклонений*/
		plt_kurs.scaleOtkl();
		/*отрисовка горизонтального индекса отклонений*/
		plt_kurs.indexOtklGor(parOtklGor);
		/*отрисовка вертикального индекса отклонений*/
		plt_kurs.indexOtklVert(parOtklVert);
	}
}