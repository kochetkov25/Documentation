/*
**  File        :   hbar_dat.h
**  Authors     :
**  Created on  :
**  Modified on :
**  Description :   hbar_dat
*/

#pragma once

#include "lib_common/interface.h"

struct hbar_dat
{
	~hbar_dat()
	{
		_CMN::TInterface::deleteSymgen(symgen);
	}

	_CMN::TSym *getFirst(void)
	{
		return &sym_Hbar_scale;
	}

	_CMN::TSym *getLast(void)
	{
		return &sym_Hbar_index_new;
	}
	_CMN::TSymgen *symgen = 0;
	_CMN::TSym sym_Hbar_scale = { 0, "Hbar_scale" };
	_CMN::TSym sym_Hbar_indexS = { 0, "Hbar_indexS" };
	_CMN::TSym sym_Hbar_indexB = { 0, "Hbar_indexB" };
	_CMN::TSym sym_Hbar_lim = { 0, "Hbar_lim" };
	_CMN::TSym sym_triangle_d = { 0, "triangle_d" };
	_CMN::TSym sym_ramka_h_m = { 0, "ramka_h_m" };
	_CMN::TSym sym_metr = { 0, "metr" };
	_CMN::TSym sym_triangle_u = { 0, "triangle_u" };
	_CMN::TSym sym_Hbar_index_new = { 0, "Hbar_index_new" };

};
