/*
**  File        :   plt_kurs.h
**  Authors     :   
**  Created on  :  
**  Modified on :  
**  Description :	plt_kurs
*/

#ifndef	_PLT_KURS_H
#define	_PLT_KURS_H

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/math.h"
#include "lib_common/font.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "kurs_dat.h"
#include <string>

class cls_plt_kurs 
{
public:

	/*����������� �� ���������*/
	cls_plt_kurs();
	/*��������� ��������� ������ ���������*/
	void setXY(float x_c, float y_c);
	/*��������� ����� ����� � ���� ��������*/
	void scale(void);
	/*��������� �������� �������*/
	void indexTek(void);
	/*��������� ��������� �������*/
	void indexZad(float Course_giv);
	/*��������� ������� ��������� ��*/
	void indexZadPU(float Course_giv_track);
	/*��������� �������� �������*/
	void indexAngle(float par_grad, _CMN::TCol3f color);
	/*��������� ���������� ��� ����� ����������*/
	void setParamOtkl(void);
	/*��������� ����� ����������*/
	void scaleOtkl(void);
	/*��������� ������������� ������� ����������*/
	void indexOtklVert(float par_otkl_vert);
	/*��������� ��������������� ������� ����������*/
	void indexOtklGor(float par_otkl_gor);
	/*��������� ������������ �����*/
	void setKurs(float M_cur, float True_cur, bool _pr_M);
	/*��������� ��������� ���� ����� (���)*/
	void indexDriftAngle(float TrackAngle);
	/*��������� ����������� ��������� ������� �� ����*/
	void indexAzRsbn(float Az_rsbn);
	/*������������� �������� ��� ������������ ����������� � OpenGL
	� ����������� ���������*/
	bool init(void);
	/*������������� ����� ������ ��� ���������� ���������*/
	void initCommon(void);

private:
	/*������ ������������� ������������ ����� ����������*/
	float getKoeffVert(void);
	/*������ ��������������� ������������ ����� ����������*/
	float getKoeffGor(void);

	/*���������� � ������ ���������*/
	float _x_c;
	/*���������� � ������ ���������*/
	float _y_c;
	/*������ �������� ��� ���������� ���������*/
	float _rad;
	/*������������ �������� ����� ����������*/
	float _max_par;
	/*������ ����� ����������*/
	float _max_length_vert;
	/*������ ����� ����������*/
	float _max_length_gor;
	const int z = -1;
	/*���� ��� �������������*/
	int _init = 1;
	/*�������� �������� �����*/
	float _tekKurs;
	int _pr_M;

	/*���������� ������� ������ TRender ��� ������������ ����������� � OpenGL*/
	_CMN::TRender _pRender;
	/*���������� ������� ������ TInterface ��� ��������� ����������� �������*/
	_CMN::TInterface *_pInterface;
	/*���������� ������� ������ TSymgen_yakPil152 ��� �������� �������*/
	kurs_dat _symgen;
};

#endif	//_PLT_KURS_H
