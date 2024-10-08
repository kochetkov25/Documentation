/*
**  File        :   plt_speed.cpp
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :   plt_speed
*/

#include "plt_speed.h"

cls_plt_speed  	plt_speed;

/*****************************************************************************/
/*конструктор по умолчанию*/
cls_plt_speed::cls_plt_speed()
{
	_x_c = 0;
	_y_c = 0;
	_rad = 0;
}

/*инициализация объектов для формирования изображения в OpenGL
  и последующей отрисовки*/
bool cls_plt_speed::init(){
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
		plt_speed.initCommon();
		_init = 0;
	}
}

/*инициализация полей класса для корректной отрисовки*/
void cls_plt_speed::initCommon(){
	/*задание смещения для корректной отрисовки*/
	_rad = 131;
}

/*****************************************************************************/
/*установка начальных параметров*/
void cls_plt_speed::setXY(float x_c, float y_c)
{
	_x_c = x_c;
	_y_c = y_c;
}

/*****************************************************************************/
/*отрисовка шкалы в виде тексутры*/
void cls_plt_speed::scale()
{
	_pInterface->enableTexsym();
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(_x_c, _y_c), _symgen.sym_Vbar_scale);
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка стрелки истинной скорости в виде текстуры*/
void cls_plt_speed::indexVist(float Vist)
{
	float par_grad = getParam(Vist);
	/*сдвиг для отрисовки стрелки из-за точки привязки текстуры*/
	float rad = 46;

	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, 0);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Translatef(0, rad, 0);
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_Vist);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка стрелки приборной скорости в виде текстуры*/
void cls_plt_speed::indexVprib(float Vpr)
{
	float par_grad = getParam(Vpr);
	/*сдвиг для отрисовки стрелки из-за точки привязки текстуры*/
	float rad = 46;

	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, 0);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Translatef(0, rad, 0);
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_Vbar_index);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка индекса прогнозируемой скорости в виде текстуры*/
void cls_plt_speed::indexVprog(float Vpr_prog)
{
	float par_grad = getParam(Vpr_prog);
	_pRender.Color3fv(WHITE);

	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, 0);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Translatef(0, _rad, 0);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_triangle_d_new_2);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка текстового индекса*/
void cls_plt_speed::indexT(float Vpr)
{
	float dx = 75;
	float dy = 40;
	float dy_sdvig = 0;
	char str[32];
	/*отрисовка рамки*/
	_pRender.LineWidth(2);
	_pRender.Color3fv(GRAY);
	_pRender.Color3fv(WHITE);
	_pInterface->enableLineSmooth();
	_CMN::TVec2f center(_x_c - dx / 2, _y_c - dy_sdvig + dy / 2 - dy);
	_pInterface->drawRectOval_tex(_CMN::TRect2f(center, dx, dy), 2, 4);
	_pInterface->disableLineSmooth();
	/*создание текста*/
	sprintf(str, "%d", _CMN::round_(Vpr));

	auto pFont = _pRender.getFont(_CMN::Font_mono24);
	auto pFontBIG = _pRender.getFont(_CMN::Font_mono34);

	if (!pFont || !pFontBIG)
		return;
	/*отрисовка текста*/
	_pRender.Color3fv(WHITE);
	pFontBIG->begin();
	float x_s1 = (strlen(str)*pFontBIG->getCharWidth(' ')) / 2;
	float x = _x_c - x_s1;
	float y = _y_c - dy_sdvig - dy / 2;
	pFontBIG->drawText(x, y, -0.9f, str);
	pFontBIG->end();
	/*отрисовка единиц измерения*/
	pFont->begin();
	_pRender.Color3fv(GRAY2);
	sprintf(str, "км/ч");
	int sizeMono = pFont->getCharWidth('M');
	x_s1 = (strlen(str)*pFont->getCharWidth(' ')) / 2;
	pFont->drawText(_x_c - x_s1, _y_c + dy / 2 + 2, -0.9f, str);
	pFont->drawText(_x_c - sizeMono / 2, _y_c + dy + 4, -0.9f, "V");
	pFont->end();
}

/*****************************************************************************/
/*отрисовка индекса ограничения минимальной скорости*/
void cls_plt_speed::indexVprMin(float Vpr_min)
{
	float ang_stt_gr = 90 + plt_speed.getParam(Vpr_min-25);
	float ang_end_gr = 90 + plt_speed.getParam(Vpr_min);

	_pRender.Color3fv(RED);
	_pInterface->enableLineSmooth();
	_CMN::TVec2f center(_x_c, _y_c);
	_pInterface->drawArc_tex(center, ang_end_gr, ang_stt_gr, _rad - 6, 22);
	_pInterface->disableLineSmooth();
}

/*****************************************************************************/
/*отрисовка индекса ограничения максимальной скорости*/
void cls_plt_speed::indexVprMax(float Vpr_max)
{
	float ang_stt_gr = 90 + plt_speed.getParam(Vpr_max);
	float ang_end_gr = 90 + plt_speed.getParam(Vpr_max + 25);

	_pRender.Color3fv(RED);
	_pInterface->enableLineSmooth();
	_CMN::TVec2f center(_x_c, _y_c);
	_pInterface->drawArc_tex(center, ang_end_gr, ang_stt_gr, _rad - 6, 22);
	_pInterface->disableLineSmooth();
}

/*****************************************************************************/
/*расчет коэффициента шкалы в зависимости от диапазона*/
float cls_plt_speed::getParam(float par)
{
	if (par<0)
		par = 0;

	float par_tmp;
	float dGrad0 = -14; //2 градуса - начальная риска
	//км/ч
	const float arrRange[7] = { 0, 100, 200, 300, 400, 500, 550 };
	//градусы для диапазонов
	const float arrGrad[7] = { dGrad0,
		dGrad0 - 60,
		dGrad0 - 120,
		dGrad0 - 181,
		dGrad0 - 242,
		dGrad0 - 302,
		dGrad0 - 331 };
	const float arrKoeff[6] = { 
		(arrGrad[1] - arrGrad[0]) / (arrRange[1] - arrRange[0]),
		(arrGrad[2] - arrGrad[1]) / (arrRange[2] - arrRange[1]),
		(arrGrad[3] - arrGrad[2]) / (arrRange[3] - arrRange[2]),
		(arrGrad[4] - arrGrad[3]) / (arrRange[4] - arrRange[3]),
		(arrGrad[5] - arrGrad[4]) / (arrRange[5] - arrRange[4]),
		(arrGrad[6] - arrGrad[5]) / (arrRange[6] - arrRange[5]) };

	//определяем цену деления для разных отрезков шкалы
	if (par >= arrRange[0] && par < arrRange[1])
	{
		par_tmp = arrGrad[0] + par*arrKoeff[0];
	}
	else if (par >= arrRange[1] && par < arrRange[2])
	{
		par_tmp = arrGrad[1] + (par - arrRange[1])*arrKoeff[1];
	}
	else if (par >= arrRange[2] && par < arrRange[3])
	{
		par_tmp = arrGrad[2] + (par - arrRange[2])*arrKoeff[2];
	}
	else if (par >= arrRange[3] && par < arrRange[4])
	{
		par_tmp = arrGrad[3] + (par - arrRange[3])*arrKoeff[3];
	}
	else if (par >= arrRange[4] && par <= arrRange[5])
	{
		par_tmp = arrGrad[4] + (par - arrRange[4])*arrKoeff[4];
	}
	else if (par >= arrRange[5] && par <= arrRange[6])
	{
		par_tmp = arrGrad[5] + (par - arrRange[5])*arrKoeff[5];
	}
	else if (par >= arrRange[6])
		par_tmp = arrGrad[6];

	return par_tmp;
}
