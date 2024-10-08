/*
**  File        : drawMapPrf
**  Authors		:
**  Created on	:
**  Modified on :
**  Description :
*/
#include "lib_map_bpf\lib_map_bpf.h"
#include "lib_common\interface.h"
#include "lib_common\render.h"

void drawMapPRF(void)
{
	/*�������� ������� ������ TRender ��� ������������ ����������� � OpenGL*/
	static _CMN::TRender render;
	/*�������� ������� ������ TInParams ��� ������� ���������� ��������� �����*/
	LibMapBpf::TInParams parBpf;
	/*������� ���� �� ����������� ������: �������, �������, DAT ������.*/
	parBpf.pchFilesPath = "./files";
	/*������� ���� �� ������ ���� ������*/
	parBpf.pchBD_Path = "D:/documentation/Proj_cpp/kai50/BPF";
	/*�������� ������ �� ��������� ������ ������ TRender � parMap2d*/
	parBpf.pRender = &render;
	/*������� ������ ���� ��������� � ��������*/
	parBpf.width = 950;
	/*������� ������ ���� ��������� � ��������*/
	parBpf.height = 950;
	/*������� ����� ������������ �������� � ��������*/
	parBpf.psiVw_deg = 0;
	/*������� ������ ������������ �������� � ��������*/
	parBpf.geoVw_deg.fi = 43.1;
	/*������� ������� ������������ �������� � ��������*/
	parBpf.geoVw_deg.lm = 44;
	/*������� ��������*/
	parBpf.scale_m = 100;
	/*����� ������� ��� ��������� �����*/
	LibMapBpf::mainBpf(parBpf);
}