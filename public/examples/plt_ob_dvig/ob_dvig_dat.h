/*
**  File        :   ob_dvig_dat.h
**  Authors     :
**  Created on  :
**  Modified on :
**  Description :   ob_dvig_dat
*/

#pragma once

#include "lib_common/interface.h"

struct ob_dvig_dat
{
	~ob_dvig_dat()
	{
		_CMN::TInterface::deleteSymgen(symgen);
	}

	_CMN::TSym *getFirst(void)
	{
		return &sym_scale_obv;
	}

	_CMN::TSym *getLast(void)
	{
		return &sym_index_obv;
	}

	_CMN::TSymgen *symgen = 0;
	_CMN::TSym sym_scale_obv = { 0, "scale_obv" };
	_CMN::TSym sym_triangle_d_new_2 = { 0, "triangle_d_new_2" };
	_CMN::TSym sym_lim = { 0, "lim" };
	_CMN::TSym sym_index_obv = { 0, "index_obv" };
};
