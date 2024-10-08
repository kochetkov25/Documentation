/*
**  File        :   speed_dat.h
**  Authors     :
**  Created on  :
**  Modified on :
**  Description :   speed_dat
*/

#pragma once

#include "lib_common/interface.h"

struct speed_dat
{
	~speed_dat()
	{
		_CMN::TInterface::deleteSymgen(symgen);
	}

	_CMN::TSym *getFirst(void)
	{
		return &sym_Vbar_scale;
	}

	_CMN::TSym *getLast(void)
	{
		return &sym_triangle_d_new_2;
	}

	_CMN::TSymgen *symgen = 0;
	_CMN::TSym sym_Vbar_scale = { 0, "Vbar_scale" };
	_CMN::TSym sym_Vist = { 0, "Vist" };
	_CMN::TSym sym_Vbar_index = { 0, "Vbar_index" };
	_CMN::TSym sym_triangle_d_new_2 = { 0, "triangle_d_new_2" };
};
