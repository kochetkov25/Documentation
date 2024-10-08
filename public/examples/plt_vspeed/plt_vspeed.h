/*
**  File        :   plt_vspeed.h
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :	plt_vspeed
*/

#ifndef	_PLT_VSPEED_H
#define	_PLT_VSPEED_H

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/font.h"
#include "lib_common/math.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "vspeed_dat.h"
#include <string>

class cls_plt_vspeed
{
public:
	/*����������� �� ���������*/
	cls_plt_vspeed();
	/*��������� ����������*/
	void setXY(float x_c, float y_c);
	/*��������� ����� � ���� ��������*/
	void scale(void);
	/*��������� ������� ������������ ��������*/
	void index(float Vvert);
	/*��������� ���������� �������*/
	void indexT(float Vvert);
	/*������������� �������� ��� ������������ ����������� � OpenGL
	� ����������� ���������*/
	bool init(void);
	/*������������� ����� ������ ��� ���������� ���������*/
	void initCommon(void);

private:
	/*������ ������������ ��������*/
	float getKoef(void);
	/*���������� x ������ ���������*/
	float _x_c;
	/*���������� y ������ ���������*/
	float _y_c;
	const int _z = -1;
	/*������� ����������� �����*/
	float _par_min;
	/*������ ����������� �����*/
	float _par_max;
	/*���� ��� �������������*/
	int _init = 1;
	/*���������� ������� ������ TRender ��� ������������ ����������� � OpenGL*/
	_CMN::TRender _pRender;
	/*���������� ������� ������ TInterface ��� ��������� ����������� �������*/
	_CMN::TInterface *_pInterface;
	/*���������� ������� ������ TSymgen_yakPil152 ��� �������� �������*/
	vspeed_dat _symgen;
};
#endif