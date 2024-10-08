/*
**  File        :   plt_ob_dvig.h
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :	plt_ob_dvig
*/

#ifndef HEADER_PLT_OB_DVIG_H_
#define HEADER_PLT_OB_DVIG_H_

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/math.h"
#include "lib_common/font.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "ob_dvig_dat.h"
#include <string>

class cls_plt_ob_dvig
{
public:
	/*����������� �� ���������*/
	cls_plt_ob_dvig();
	/*��������� ��������� ������ ���������*/
	void setXY(float x_c, float y_c);
	/*��������� ����� � ���� ��������*/
	void scale(void);
	/*��������� ������� �������� � ���� ��������*/
	void index(float Power);
	/*��������� ���������� �������*/
	void indexT(float Power);
	/*��������� ��������� ��������� ���*/
	void indexRud(float pQ_PWL);
	/*��������� �������� ����������� �������� �������� ���������*/
	void indexLimit(void);
	/*������������� �������� ��� ������������ ����������� � OpenGL
	� ����������� ���������*/
	bool init(void);
	/*������������� ����� ������ ��� ���������� ���������*/
	void initCommon(void);

private:
	/*������ ������������ ���� ��������*/
	float getPar(float par);

	/*���������� x ������ ���������*/
	float _x_c;
	/*���������� y ������ ���������*/
	float _y_c;
	/*������ ��������*/
	float _rad;
	const int z = -1;
	/*���� ��� �������������*/
	int _init = 1;
	/*������� ����������� �����*/
	float _max_par;
	/*������ ����������� �����*/
	float _min_par;
	/*���������� ������� ������ TRender ��� ������������ ����������� � OpenGL*/
	_CMN::TRender _pRender;
	/*���������� ������� ������ TInterface ��� ��������� ����������� �������*/
	_CMN::TInterface *_pInterface;
	/*���������� ������� ������ TSymgen_yakPil152 ��� �������� �������*/
	ob_dvig_dat _symgen;
};


#endif /* HEADER_PLT_PLT_OB_DVIG_H_ */