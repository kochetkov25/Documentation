/*
**  File        :   plt_ob_dvig.cpp
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :	plt_ob_dvig
*/

#include "plt_ob_dvig.h";

cls_plt_ob_dvig  	plt_ob_dvig;

/*****************************************************************************/
/*конструктор по умолчанию*/
cls_plt_ob_dvig::cls_plt_ob_dvig()
{
	_x_c = 0;
	_y_c = 0;
	_rad = 0;
}

/*инициализация объектов для формирования изображения в OpenGL
и последующей отрисовки*/
bool cls_plt_ob_dvig::init(){
	if (_init){
		/*инициализация интерфейса*/
		_pInterface = _pRender.getInterface();
		/*инициализация текстур*/
		if (!_pInterface)
			return false;
		_pInterface->readSymgen(_symgen, "./files/dat/yakPil152.dat");
		/*установка параметров отрисовки*/
		_pRender.BlendFunc(_CMN::TRender::SRC_ALPHA,
			_CMN::TRender::ONE_MINUS_SRC_ALPHA);
		_pRender.TexEnvMode(_CMN::TRender::MODULATE);
		/*инициализация шрифта*/
		_pRender.initFonts("./files/fonts/");
		/*инициализация полей для корректной отрисовки*/
		plt_ob_dvig.initCommon();
		_init = 0;
	}
}

/*инициализация полей класса для корректной отрисовки*/
void cls_plt_ob_dvig::initCommon(){
	/*задание смещения для корректной отрисовки*/
	_rad = 60;
	/*максимальное значение шкалы*/
	_max_par = 100;
	/*минимальное значение шкалы*/
	_min_par = 0;
}

/*****************************************************************************/
/*установка координат центра фрагмента*/
void cls_plt_ob_dvig::setXY(float x_c, float y_c)
{
	_x_c = x_c;
	_y_c = y_c;
}

/*****************************************************************************/
/*отрисовка шкалы в виде текстуры*/
void cls_plt_ob_dvig::scale()
{
	_pInterface->enableTexsym();
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(_x_c, _y_c), _symgen.sym_scale_obv);
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка указателя положения РУД в виде текстуры*/
void cls_plt_ob_dvig::indexRud(float pQ_PWL)
{
	float par = pQ_PWL;
	float x = _x_c + 120;
	float y = _y_c;
	float rad_index = _rad + 60;

	par = _CMN::clamp_(par, _min_par, _max_par);

	float par_grad = getPar(par);

	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(x, y, 0);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Translatef(0, rad_index, 0);
	_pRender.Color3fv(GREEN);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_triangle_d_new_2);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка индексов номинальных значений мощности двигателя*/
void cls_plt_ob_dvig::indexLimit(void)
{
	float x = _x_c + 120;
	float y = _y_c;
	float par = 80;
	float par_grad = getPar(par);
	float rad_lim = _rad + 55;

	//Рисуем риски в виде тексутры
	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(x, y, 0);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Translatef(0, rad_lim, 0);
	_pRender.Color3fv(BLUE);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_lim);
	_pRender.PopMatrix();

	par = 92;
	par_grad = getPar(par);

	//Рисуем риски в виде тексутры
	_pRender.PushMatrix();
	_pRender.Translatef(x, y, 0);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Translatef(0, rad_lim, 0);
	_pRender.Color3fv(BLUE);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_lim);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка стрелки в виде текстуры*/
void cls_plt_ob_dvig::index(float Power)
{
	float par = Power;
	float x = _x_c + 120;
	float y = _y_c;

	par = _CMN::clamp_(par, _min_par, _max_par);

	float par_grad = getPar(par);

	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(x, y, 0);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Translatef(0, _rad, 0);
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_index_obv);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка текстового индекса*/
void cls_plt_ob_dvig::indexT(float Power)
{
	float par = Power;
	float dx = 48;
	float dy = 30;
	float x = _x_c + 1;
	float y = _y_c + 110;

	par = _CMN::clamp_(par, _min_par, 130.f);

	_pRender.Color3fv(WHITE);
	_pInterface->enableLineSmooth();
	_CMN::TVec2f center(x, y);
	_pInterface->drawRectOval_tex(_CMN::TRect2f(center, dx, dy), 2, 2);
	_pInterface->disableLineSmooth();

	char str[8];
	auto *pFont = _pRender.getFont(_CMN::Font_mono24);
	if (!pFont)
		return;
	int sizeMono = pFont->getCharWidth('M');

	pFont->begin();
	_pRender.Color3fv(WHITE);
	pFont->drawText(x - sizeMono, y, -1, "P");

	sprintf(str, "%d", _CMN::round_(par));
	int len = strlen(str) / 2;
	pFont->drawText(x + dx / 2 - len, y, -1, str);

	_pRender.Color3fv(GRAY2);
	pFont->drawText(x + dx + 2, y, -1, "%");
	pFont->end();
}

/*****************************************************************************/
/*расчет коэффициента угла поворота*/
float cls_plt_ob_dvig::getPar(float par)
{
	float par_tmp;
	par = _CMN::clamp_(par, 0.f, 100.f);
	float arrAngle[11] = { 154, 147, 139, 132, 124, 117, 110, 90, 70, 50, 30 };
	float arrPar[11] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	float koeffPar[12] = { 
		_CMN::abs_(arrAngle[1] - arrAngle[0]) / (arrPar[1] - arrPar[0]),
		_CMN::abs_(arrAngle[2] - arrAngle[1]) / (arrPar[2] - arrPar[1]),
		_CMN::abs_(arrAngle[3] - arrAngle[2]) / (arrPar[3] - arrPar[2]),
		_CMN::abs_(arrAngle[4] - arrAngle[3]) / (arrPar[4] - arrPar[3]),
		_CMN::abs_(arrAngle[5] - arrAngle[4]) / (arrPar[5] - arrPar[4]),
		_CMN::abs_(arrAngle[6] - arrAngle[5]) / (arrPar[6] - arrPar[5]),
		_CMN::abs_(arrAngle[7] - arrAngle[6]) / (arrPar[7] - arrPar[6]),
		_CMN::abs_(arrAngle[8] - arrAngle[7]) / (arrPar[8] - arrPar[7]),
		_CMN::abs_(arrAngle[9] - arrAngle[8]) / (arrPar[9] - arrPar[8]),
		_CMN::abs_(arrAngle[10] - arrAngle[9]) / (arrPar[10] - arrPar[9]) };

	if (par >= arrPar[0] && par <= arrPar[1])
	{
		par_tmp = arrAngle[0] - par*koeffPar[0];
	}
	else if (par>arrPar[1] && par <= arrPar[2])
	{
		par_tmp = arrAngle[1] - (par - arrPar[1])*koeffPar[1];
	}
	else if (par>arrPar[2] && par <= arrPar[3])
	{
		par_tmp = arrAngle[2] - (par - arrPar[2])*koeffPar[2];
	}
	else if (par>arrPar[3] && par <= arrPar[4])
	{
		par_tmp = arrAngle[3] - (par - arrPar[3])*koeffPar[3];
	}
	else if (par>arrPar[4] && par <= arrPar[5])
	{
		par_tmp = arrAngle[4] - (par - arrPar[4])*koeffPar[4];
	}
	else if (par>arrPar[5] && par <= arrPar[6])
	{
		par_tmp = arrAngle[5] - (par - arrPar[5])*koeffPar[5];
	}
	else if (par>arrPar[6] && par <= arrPar[7])
	{
		par_tmp = arrAngle[6] - (par - arrPar[6])*koeffPar[6];
	}
	else if (par>arrPar[7] && par <= arrPar[8])
	{
		par_tmp = arrAngle[7] - (par - arrPar[7])*koeffPar[7];
	}
	else if (par>arrPar[8] && par <= arrPar[9])
	{
		par_tmp = arrAngle[8] - (par - arrPar[8])*koeffPar[8];
	}
	else if (par>arrPar[9] && par <= arrPar[10])
	{
		par_tmp = arrAngle[9] - (par - arrPar[9])*koeffPar[9];
	}
	else if (par>arrPar[10])
	{
		par_tmp = arrAngle[11];
	}

	return par_tmp;
}