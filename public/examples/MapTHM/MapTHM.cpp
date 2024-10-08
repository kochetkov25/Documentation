/*
**  File        : drawMapThm.cpp
**  Authors		:
**  Created on	:
**  Modified on :
**  Description :
*/
#include "lib_common\interface.h"
#include "lib_common\render.h"
#include "lib_thm\lib_thm.h"

void drawTHM(void)
{
	/*�������� ������� ������ TRender ��� ������������ ����������� � OpenGL*/
	static _CMN::TRender render;
	/*������������� �������*/
	render.initFonts("./files/fonts/");
	/*�������� ������� ������ TInParams ��� ������� ���������� ��������� �����*/
	LibThm::TInParams parThm;
	/*������� ������ ���� ��������� � ��������*/
	parThm.width = 950;
	/*������� ������ ���� ��������� � ��������*/
	parThm.height = 950;
	/*������� ���� �� ����������� ������: �������, �������, DAT ������.*/
	parThm.pchFilesPath = "./files";
	/*������� ���� �� ������ ���� ������*/
	parThm.pchBD_Path = "D:/documentation/Proj_cpp/kai50/BSF";
	/*�������� ������ �� ��������� ������ ������ TRender � parMap2d*/
	parThm.pRender = &render;
	/*������� ������ ������������ �������� � ��������*/
	parThm.geoVw_deg.fi = 40.05;
	/*������� ������� ������������ �������� � ��������*/
	parThm.geoVw_deg.lm = 40;
	/*������� ����� ������������ �������� � ��������*/
	parThm.psiVw_deg = 0;
	/*������� ������ ������������ ��������*/
	parThm.htVw_m = 10000;
	/*��������������� ������� ����� �� 0 �� 100*/
	parThm.bright_perc = 100;
	/*��������������� ����� ����� ����� �� 0 �� 100*/
	parThm.graysc_perc = 0;
	/*������� ������������ ��� ���� ����� �� 0 �� 100*/
	parThm.alphaFone_perc = 100;
	/*������� ��������� ����������� � ��������*/
	parThm.scrPosVw_pix = _CMN::TVec2f(0, 0);
	/*������� ��������*/
	parThm.scale_m = 80;
	/*��������������� ������� ������������ ���� ������*/
	parThm.rotation_deg = 0;
	/*���� ���������� true, ����� ����� ����������*/
	parThm.isDraw = 1;
	/*�������� ������� ������ TParScale ��� ��������� ���������� �����*/
	LibThm::TParScale scale;
	/*��������� ���������� ���������� � ������ �����*/
	scale.flagM = 1;
	/*������� ������ �����*/
	float length = 400;
	scale.dx = length;
	/*��������� ����� ��������� (����� ������� ����� �����)*/
	float x = 0;
	float y = -410;
	float z = -1;
	_CMN::TVec3f point(x, y, z);
	scale.p0 = point;
	/*��������� ����� �����*/
	_CMN::TCol4ub color(255, 0, 0);
	scale.col = color;
	/*�������� ���������� ����� ��� ���������*/
	LibThm::setScale(scale);
	/*��������� ������ ��������� ��� �����*/
	LibThm::setChannel(LibThm::Channel_1);
	/*����� ������� ��� ��������� �����*/
	LibThm::mainTHM(parThm);
}