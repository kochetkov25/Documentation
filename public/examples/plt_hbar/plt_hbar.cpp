/*
**  File        :   plt_hbar.cpp
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :   plt_hbar
*/

#include "plt_hbar.h"

cls_plt_hbar  	plt_hbar;

/******************************************************************************/
/*конструктор по умолчанию*/
cls_plt_hbar::cls_plt_hbar()
{
	_x_c = 0;
	_y_c = 0;
	_rad = 0;
}

/******************************************************************************/
/*установка начальных параметров*/
void cls_plt_hbar::setXY(float x_c, float y_c)
{
	_x_c = x_c;
	_y_c = y_c;
}

/*инициализация объектов для формирования изображения в OpenGL
и последующей отрисовки*/
bool cls_plt_hbar::init(){
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
		plt_hbar.initCommon();
		_init = 0;
	}
}

/*инициализация полей класса для корректной отрисовки*/
void cls_plt_hbar::initCommon(){
	/*задание смещения для корректной отрисовки*/
	_rad = 131;
}

/******************************************************************************/
/*отрисовка шкалы с размерностью метры в виде текстуры*/
void cls_plt_hbar::scale(void)
{
	_pInterface->enableTexsym();
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(_x_c, _y_c), _symgen.sym_Hbar_scale);
	_pInterface->disableTexsym();
}

/******************************************************************************/
/*отрисовка стрелки в виде текстуры*/
void cls_plt_hbar::indexHbar(float Hbar)
{
	float par = Hbar;

	float par_km = (par / 1000.f);
	float par_m = (par - (int)(par_km)* 1000) * 10;
	par_km = par_km * 1000;

	float par_grad = plt_hbar.getParam(par_m);

	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, -1);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_Hbar_indexS);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();


	par_grad = plt_hbar.getParam(par_km);

	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, -1);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_Hbar_indexB);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();

	_pInterface->enableLineSmooth();
	_pInterface->drawCircleLine_tex(_x_c, _y_c, 5, 2);
	_pInterface->disableLineSmooth();
	_pInterface->drawCircleFill(_x_c, _y_c, 5);
}

/******************************************************************************/
/*отрисовка индекса опасной высоты в виде текстуры*/
void cls_plt_hbar::indexHdanger(float Hop)
{
	float par = Hop * 10;

	float par_grad = plt_hbar.getParam(par);

	_pRender.Color3fv(WHITE);
	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, 0);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Translatef(0, _rad + 2, 0);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_Hbar_lim);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}

/******************************************************************************/
/*отрисовка индекса геометрической высоты*/
void cls_plt_hbar::indexHgeom(float Hg)
{
	float par = Hg * 10;
	int pr_ris = 0; //признак рисования второй дуги
	float rad_x = 0;//смещение указателя

	float par_grad = plt_hbar.getParam(par);

	if (par_grad<-360)
		pr_ris = 1;
	float ang_end_gr = 90;
	float ang_stt_gr = 90 + par_grad;
	if (ang_stt_gr<0)
		ang_stt_gr = ang_stt_gr + 360;

	_pRender.LineWidth(2);
	_pRender.Color3fv(GREEN);

	rad_x = _rad + 5;
	//одна дуга
	_pInterface->enableLineSmooth();
	_CMN::TVec2f center(_x_c, _y_c);
		if ((int)par_grad != 0)
			_pInterface->drawArc_tex(center, ang_stt_gr, ang_end_gr, rad_x, 4);
	_pInterface->disableLineSmooth();
	//треугольник в конце дуги
	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, 0);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Translatef(0, rad_x, 0);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_triangle_d);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();

}

/******************************************************************************/
/*отрисовка текстового индекса высоты*/
void cls_plt_hbar::indexT(float Hbar)
{
	float dy_sdvig = 50;
	char str[16];
	float par = Hbar;

	_pInterface->enableTexsym();
	_pRender.Color3fv(WHITE);
	_CMN::TVec2f center(_x_c, _y_c - dy_sdvig / 2 - 5);
	_pInterface->drawTexsym(center, _symgen.sym_ramka_h_m);

	_pRender.Color3fv(GRAY2);
	_pInterface->drawTexsym(_CMN::TVec2f(_x_c, _y_c - 65), _symgen.sym_metr);
	_pInterface->disableTexsym();

	auto *pFont = _pRender.getFont(_CMN::Font_mono32);
	if (!pFont)
		return;

	_pRender.Color3fv(WHITE);
	sprintf(str, "%d", _CMN::round_(par));
	pFont->begin();
	float x_s1 = strlen(str)*pFont->getCharWidth(' ') / 2;
	float x = _x_c - x_s1;
	float y = _y_c - dy_sdvig + 1;
	pFont->drawText(x, y, -0.9f, str);
	pFont->end();
}

/******************************************************************************/
/*отрисовка индекса прогнозируемой геометрической высоты в виде текстуры*/
void cls_plt_hbar::indexHprog(float H_prog)
{
	float par = H_prog * 10;

	float par_grad = plt_hbar.getParam(par);

	_pRender.Color3fv(WHITE);

	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, 0);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Translatef(0, _rad, 0);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_triangle_u);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}

/******************************************************************************/
/*отрисовка цифрового индикатора геометрической высоты*/
void cls_plt_hbar::textHgeom(float Hg)
{
	auto* pFont = _pRender.getFont(_CMN::Font_mono26);
	if (!pFont)
		return;
	float x = _x_c + 55;
	float y = _y_c + 118;

	float par = Hg;
	par = _CMN::clamp_(par, -10000.f, 10000.f);
	char str[8];
	pFont->begin();
	_pRender.Color3fv(GREEN);

	sprintf(str, "%5dp", _CMN::round_(par));
	pFont->drawText(x, y, -0.9f, str);
	pFont->end();

}

/******************************************************************************/
/*расчет коэффициента шкалы*/
float cls_plt_hbar::getParam(float par)
{
	double koeff = 0;
	float par_tmp;

	koeff = 360.f / 10000.f; //1000 фт в 360 градусах

	par_tmp = 0 + par*koeff;

	return -par_tmp;

}

/*****************************************************************************/
/*отрисовка индекса заданной высоты в виде текстуры*/
void cls_plt_hbar::indexHzad(float Hzad)
{
	float par = Hzad * 10;

	float par_grad = plt_hbar.getParam(par);
	_pRender.Color3fv(WHITE);

	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, 0);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Translatef(0, _rad + 5, 0);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_Hbar_index_new);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка сектора допустимых отклонений от заданной высоты*/
void cls_plt_hbar::indexDopOtklonHzad(float Hzad)
{
	float par = Hzad * 10;

	float par_delta = 1000;

	float ang_beg = plt_hbar.getParam((par + par_delta)) + 90;
	float ang_end = plt_hbar.getParam((par - par_delta)) + 90;
	float par_beg_grad = plt_hbar.getParam((par + par_delta));
	float par_end_grad = plt_hbar.getParam((par - par_delta));

	_pRender.Color3fv(GREEN);

	_pInterface->enableLineSmooth();
	_CMN::TVec2f center(_x_c, _y_c);
	_pInterface->drawArc_tex(center, ang_beg, ang_end, _rad - 8, 15);
	_pInterface->disableLineSmooth();

	_CMN::TVec2f v1, v2;
	v1.x = 0;
	v2.x = 0;
	v1.y = _rad;
	v2.y = _rad - 20;

	_pInterface->enableLineSmooth();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, 0);
	_pRender.Rotatef(par_beg_grad, 0, 0, 1);
	_pInterface->drawLine2d_tex(v1, v2, 8);
	_pRender.PopMatrix();

	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, 0);
	_pRender.Rotatef(par_end_grad, 0, 0, 1);
	_pInterface->drawLine2d_tex(v1, v2, 8);
	_pRender.PopMatrix();
	_pInterface->disableLineSmooth();

}

