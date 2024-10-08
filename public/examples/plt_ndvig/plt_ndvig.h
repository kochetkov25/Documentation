/*
**  File        :   plt_ndvig.h
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :	plt_ndvig
*/

#ifndef HEADER_PLT_NDVIG_H_
#define HEADER_PLT_NDVIG_H_

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/math.h"
#include "lib_common/font.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "ndvig_dat.h"
#include <string>

class cls_plt_ndvig
{
public:
	/*����������� �� ���������*/
	cls_plt_ndvig(); 
	/*��������� ������ ���������*/
	void setXY(float x_c, float y_c);
	/*��������� ����� � ���� ��������*/
	void scale(void);
	/*��������� ������� ��������*/
	void index(float PropRev);
	/*��������� ���������� �������*/
	void indexT(float PropRev);
	/*��������� �������-������������ ����������� ���������� �������� ����� � ���� ��������*/
	void indexLimit(float PropRevLim);
	/*������������� �������� ��� ������������ ����������� � OpenGL
	� ����������� ���������*/
	bool init(void);
	/*������������� ����� ������ ��� ���������� ���������*/
	void initCommon(void);

private:
	/*������ ������������ ����� � ����������� �� ���������*/
	float getKoef(void);

	/*���������� x ������ ���������*/
	float _x_c;
	/*���������� y ������ ���������*/
	float _y_c;
	/*������ ��������*/
	float _length;
	const int _z = -1;
	/*���� ��� �������������*/
	int _init = 1;
	/*������� ����������� ����*/
	float _max_par;
	/*������ ����������� �����*/
	float _min_par;
	/*���������� ������� ������ TRender ��� ������������ ����������� � OpenGL*/
	_CMN::TRender _pRender;
	/*���������� ������� ������ TInterface ��� ��������� ����������� �������*/
	_CMN::TInterface *_pInterface;
	/*���������� ������� ������ TSymgen_yakPil152 ��� �������� �������*/
	ndvig_dat _symgen;
};


#endif /* HEADER_PLT_PLT_NDVIG_H_ */
