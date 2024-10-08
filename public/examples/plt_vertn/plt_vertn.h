/*
** File : plt_vertn.h
** Authors :
** Created on :
** Modified on :
** Description : plt_vertn
*/

#ifndef HEADER_PLT_VERTN_H_
#define HEADER_PLT_VERTN_H_

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/math.h"
#include "lib_common/font.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "vertn_dat.h"
#include <string>

class cls_plt_vertn
{

public:

	/*����������� �� ���������*/
	cls_plt_vertn();
	/*��������� ��������� ������ ���������*/
	void setXY(float x_c, float y_c);
	/*��������� ����� � ���� ��������*/
	void scale(void);
	/*��������� ���������� ������� � �������*/
	void indexT(float Ny);
	/*��������� ������� ny*/
	void NySym(void);
	/*��������� ������� ����������� ������������� ����������*/
	void NyMaxLim(float Ny_max);
	/*��������� ������� ����������� ������������� ����������*/
	void NyMinLim(float Ny_min);
	/*��������� ����������� ������������ �������� �������������
	����������*/
	void NyMaxFlight(float Ny);
	/*��������� ����������� ������������ �������� �������������
	����������*/
	void NyMinFlight(float Ny);
	/*��������� ������� ���������������� �����������*/
	void NyDisp(float Ny_disp);
	/*������������� �������� ��� ������������ ����������� � OpenGL
	� ����������� ���������*/
	bool init(void);
	/*������������� ����� ������ ��� ���������� ���������*/
	void initCommon(void);

private:
	/*������ ������������ ��������*/
	float getKoef(void);
	/*���������� x ������ ��������*/
	float _x_c;
	/*���������� y ������ ���������*/
	float _y_c;
	/*������ ��������*/
	float _length;
	const int _z = -1;
	/*���� ��� �������������*/
	int _init = 1;
	/*����������� ����� ������*/
	float _max_par;
	/*����������� ����� �����*/
	float _min_par;
	/*���������� ������� ������ TRender ��� ������������ ����������� � OpenGL*/
	_CMN::TRender _pRender;
	/*���������� ������� ������ TInterface ��� ��������� ����������� �������*/
	_CMN::TInterface *_pInterface;
	/*���������� ������� ������ TSymgen_yakPil152 ��� �������� �������*/
	vertn_dat _symgen;
};


#endif /* HEADER_PLT_PLT_VERTN_H_ */