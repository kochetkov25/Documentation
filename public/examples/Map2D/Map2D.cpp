/*
**  File        : drawMap2d.cpp
**  Authors		:
**  Created on	:
**  Modified on :
**  Description :
*/
#include "lib_common\interface.h"
#include "lib_map2d\lib_map2d.h"
#include "lib_common\render.h"

void drawMap2d(void)
{
	/*�������� ������� ������ TRender ��� ������������ ����������� � OpenGL*/
	static _CMN::TRender render;
	/*������������� �������*/
	render.initFonts("./files/fonts/");
	/*�������� ������� ������ TInParams ��� ������� ���������� ��������� �����*/
	LibMap2d::TInParams parMap2d;
	/*������� ������ ���� ��������� � ��������*/
	parMap2d.width = 950;
	/*������� ������ ���� ��������� � ��������*/
	parMap2d.height = 950;
	/*������� ���� �� ����������� ������: �������, �������, DAT ������.*/
	parMap2d.pchFilesPath = "./files";
	/*������� ���� �� ������ ���� ������*/
	parMap2d.pchBD_Path = "D:/documentation/Proj_cpp/kai50/BMF";
	/*�������� ������ �� ��������� ������ ������ TRender � parMap2d*/
	parMap2d.pRender = &render;
	/*������� ������� ������� ������*/
	parMap2d.scrPixel_mm = 0.15f;
	/*������� ������ ������������ �������� � ��������*/
	parMap2d.geoVw_deg.fi = 50;
	/*������� ������� ������������ �������� � ��������*/
	parMap2d.geoVw_deg.lm = 50;
	/*������� ����� ������������ �������� � ��������*/
	parMap2d.psiVw_deg = 0;
	/*���� ����������� �����*/
	/*�������� �������*/
	parMap2d.layers.relief = 1;
	/*�����������*/
	parMap2d.layers.gidro = 1;
	/*������*/
	parMap2d.layers.towns = 1;
	/*������������ �������*/
	parMap2d.layers.industry = 1;
	/*������*/
	parMap2d.layers.roads = 1;
	/*��������������*/
	parMap2d.layers.forest = 1;
	/*�������*/
	parMap2d.layers.bound = 1;
	/*�������*/
	parMap2d.layers.scripts = 1;
	/*�������������� ������*/
	parMap2d.layers.mat = 1;
	/*��������������� ������� ����� �� 0 �� 100*/
	parMap2d.bright_perc = 100;
	/*��������������� ����� ����� ����� �� 0 �� 100*/
	parMap2d.graysc_perc = 0;
	/*������� ��������� ����������� � ��������*/
	parMap2d.scrPosVw_pix = _CMN::TVec2f(0, 0);
	/*������� ������������ ��� ���� ����� �� 0 �� 100*/
	parMap2d.alphaFone_perc = 100;
	/*������� ������������ ��� �������� ����� �� 0 �� 100*/
	parMap2d.alphaObj_perc = 100;
	/*������� ��������*/
	parMap2d.scale_m = 180;
	/*���� ���������� true, ����� ����� ����������*/
	parMap2d.isDraw = 1;
	/*��������� ������ ��������� ��� �����*/
	LibMap2d::setChannel(LibMap2d::Channel_1);

	/*�������� ������� ������ TParScale ��� ��������� ���������� �����*/
	LibMap2d::TParScale scale;
	/*��������� ���������� ���������� � ������ �����*/
	scale.flagM = 1;
	/*��������� �������������� ��������*/
	scale.flagS = 1;
	/**/
	scale.flagZ = 0;
	/*������� ������ �����*/
	float length = 400;
	scale.dx = length;
	/*��������� ����� ��������� (����� ������� ����� �����)*/
	float x = 0;
	float y = -410;
	float z = -1;
	_CMN::TVec3f point(x,y,z);
	scale.p0 = point;
	/*��������� ����� �����*/
	_CMN::TCol4ub color(255, 0, 0);
	scale.col = color;
	/*�������� ���������� ����� ��� ���������*/
	LibMap2d::setScale(scale);
	/*����� ������� ��� ��������� �����*/
	LibMap2d::main2D(parMap2d);
}