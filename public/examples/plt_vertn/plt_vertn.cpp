/*
** File : plt_vertn.cpp
** Authors :
** Created on :
** Modified on :
** Description : plt_vertn
*/


#include "plt_vertn.h"

cls_plt_vertn plt_vertn;

/****************************************************************************/
/*конструктор по умолчанию*/
cls_plt_vertn::cls_plt_vertn()
{
	_length = 0;
	_x_c = 0;
	_y_c = 0;
}

/*инициализация объектов для формирования изображения в OpenGL
и последующей отрисовки*/
bool cls_plt_vertn::init(){
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
		plt_vertn.initCommon();
		_init = 0;
	}
}

/*инициализация полей класса для корректной отрисовки*/
void cls_plt_vertn::initCommon(){
	/*максимальное значение шкалы*/
	_max_par = 8;
	/*минимальное значение шкалы*/
	_min_par = 5;
	/*смещение для корректной отрисовки фрагмента*/
	_length = 315;
}

/****************************************************************************/
/*установка координат центра фрагмента*/
void cls_plt_vertn::setXY(float x_c, float y_c)
{
	_x_c = x_c;
	_y_c = y_c;
}

/****************************************************************************/
/*отрисовка шкалы в виде текстуры*/
void cls_plt_vertn::scale()
{
	_pInterface->enableTexsym();
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(_x_c, _y_c), _symgen.sym_VertN_scale);
	_pInterface->disableTexsym();
}

/****************************************************************************/
/*отрисовка текстового индекса со стрелкой */
void cls_plt_vertn::indexT(float Ny)
{

	_CMN::TVec2f v[7];
	char str[10];
	float koef = getKoef();
	float par = Ny;
	par = _CMN::clamp_(par, -_min_par, _max_par);

	float y = par*koef;

	float x0 = _x_c - 2;
	float y0 = _y_c + y;
	float dx1 = 15;
	float dx2 = 30;

	_pInterface->enableTexsym();
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(x0, y0), _symgen.sym_vertN_index_new);
	_pInterface->disableTexsym();


	auto *pFontBig = _pRender.getFont(_CMN::Font_mono26);
	auto *pFontSmall = _pRender.getFont(_CMN::Font_mono22);
	if (!pFontBig || !pFontSmall)
		return;

	int parBig = (int)(abs(par));
	int parSmall = (((fabs)(par)-parBig) * 10);
	_pRender.Color3fv(WHITE);

	pFontBig->begin();
	int sizemono = pFontBig->getCellWidth();
	sprintf(str, "%d", (int)(par));
	float x_tmp = 0;
	if (par<0)
		x_tmp = x0 - dx1 - dx2 - 4;
	else
		x_tmp = x0 - dx1 - dx2 - 4 + sizemono;
	pFontBig->drawText(x_tmp, y0 + 5, -1, str);
	pFontBig->end();

	pFontSmall->begin();
	sizemono = pFontSmall->getCharWidth(' ');
	sprintf(str, ".%d", parSmall);
	if (par<0)
		x_tmp = x_tmp + 2 * sizemono;
	else
		x_tmp = x_tmp + sizemono;
	pFontSmall->drawText(x_tmp, y0 + 7, -1, str);
	pFontSmall->end();
}

/****************************************************************************/
/*отрисовка символа ny*/
void cls_plt_vertn::NySym()
{
	float x = _x_c + 25;
	float y = _y_c + 8 * getKoef();

	_pRender.Color3fv(WHITE);
	_pInterface->enableLineSmooth();
	_pInterface->drawTexsym(_CMN::TVec2f(x, y), _symgen.sym_Ny_symb_new);
	_pInterface->disableTexsym();
}

/****************************************************************************/
/*отрисовка сектора критических положительных перегрузок*/
void cls_plt_vertn::NyMaxLim(float Ny_max)
{

	float dx = 10;
	float x = _x_c;

	float koef_par = getKoef();
	float par = Ny_max;
	par = _CMN::clamp_(par, -_min_par, _max_par);

	par = _max_par - par;

	float dy = par*koef_par;

	float y = _y_c + _max_par*koef_par;

	_pRender.Color3fv(RED);
	_pInterface->drawBar(_CMN::TRect2f(_CMN::TVec2f(x, y - dy), dx, dy));
}

/****************************************************************************/
/*отрисовка сектора критических отрицательных перегрузок*/
void cls_plt_vertn::NyMinLim(float Ny_min)
{

	float dx = 10;
	float x = _x_c;

	float koef_par = getKoef();
	float par = Ny_min;
	par = _CMN::clamp_(par, -_min_par, _max_par);

	par = par + _min_par;

	float dy = par*koef_par;
	float y = _y_c - _min_par*koef_par + dy;

	_pRender.Color3fv(RED);
	_pInterface->drawBar(_CMN::TRect2f(_CMN::TVec2f(x, y - dy), dx, dy));
}


/****************************************************************************/
/*отрисовка максимально достигнутого значения положительной перегрузки*/
void cls_plt_vertn::NyMaxFlight(float Ny)
{
	float par = Ny;
	float dx = 12;
	float dy = 12;
	float x = _x_c - 2;

	float koef_par = getKoef();
	par = _CMN::clamp_(par, -_min_par, _max_par);
	float par_tmp = par*koef_par;

	float y = _y_c + par_tmp;

	_pRender.Color3fv(GREEN);
	_pInterface->drawTriangleRight(_CMN::TVec2f(x, y), dx, dy);
}

/****************************************************************************/
/*отрисовка максимально достигнутого значения отрицательной перегрузки*/
void cls_plt_vertn::NyMinFlight(float Ny)
{
	float par = Ny;
	float dx = 12;
	float dy = 12;
	float x = _x_c - 2;

	float koef_par = getKoef();

	par = _CMN::clamp_(par, -_min_par, _max_par);
	float par_tmp = par*koef_par;

	float y = _y_c + par_tmp;

	_pRender.Color3fv(GREEN);
	_pInterface->drawTriangleRight(_CMN::TVec2f(x, y), dx, dy);
}

/****************************************************************************/
/*отрисовка предела аэродинамических ограничений*/
void cls_plt_vertn::NyDisp(float Ny_disp)
{

	float dx = 40;
	float dy = 3;
	float x = _x_c + 5;

	float koef_par = getKoef();

	float par = Ny_disp;

	par = _CMN::clamp_(par, -_min_par, _max_par);

	float par_tmp = par*koef_par;

	float y = _y_c + par_tmp;

	_pRender.Color3fv(YELLOW);
	_CMN::TVec2f center(x - dx / 2, y - dy / 2);
	_pInterface->drawBar(_CMN::TRect2f(center, dx, dy));
}

/****************************************************************************/
/*расчет коэффициента шкалы*/
float cls_plt_vertn::getKoef(void)
{

	return _length / (_max_par + _min_par);
}