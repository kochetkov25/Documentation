/*
**  File        :   plt_hbar.h
**  Authors     :   
**  Created on  :   
**  Modified on :  
**  Description :	plt_hbar
*/

#ifndef	_PLT_HBAR_H
#define	_PLT_HBAR_H

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/math.h"
#include "lib_common/font.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "hbar_dat.h"
#include <string>

class cls_plt_hbar
{
public:
	/*����������� �� ���������*/
	cls_plt_hbar();
	/*��������� ������ ���������*/
	void setXY(float x_c, float y_c);
	/*��������� ����� � ���� ��������*/
	void scale(void);
	/*��������� ������� � ���� ��������*/
	void indexHbar(float Hbar);
	/*��������� ���������� ������� ������*/
	void indexT(float Hbar);
	/*��������� ������� ������� ������ � ���� ��������*/
	void indexHdanger(float Hop);
	/*��������� ������� �������������� ������*/
	void indexHgeom(float Hg);
	/*��������� ������� �������������� �������������� ������ � ���� ��������*/
	void indexHprog(float H_prog);
	/*��������� ��������� ���������� �������������� ������*/
	void textHgeom(float Hg);
	/*��������� ������� ���������� ���������� �� �������� ������*/
	void indexDopOtklonHzad(float Hzad);
	/*��������� ������� �������� ������ � ���� ��������*/
	void indexHzad(float Hzad);
	/*������������� �������� ��� ������������ ����������� � OpenGL
	� ����������� ���������*/
	bool init(void);
	/*������������� ����� ������ ��� ���������� ���������*/
	void initCommon(void);

private:
	/*������ ������������ �����*/
	float getParam(float par);
	/*���������� x ������ ���������*/
	float _x_c;
	/*���������� y ������ ���������*/
	float _y_c;
	/*������ ��������*/
	float _rad;
	const int _z = -1;
	/*���� ��� �������������*/
	int _init = 1;
	/*���������� ������� ������ TRender ��� ������������ ����������� � OpenGL*/
	_CMN::TRender _pRender;
	/*���������� ������� ������ TInterface ��� ��������� ����������� �������*/
	_CMN::TInterface *_pInterface;
	/*���������� ������� ������ TSymgen_yakPil152 ��� �������� �������*/
	hbar_dat _symgen;
};

#endif	//_PLT_HBAR_H
