/*
**  File        :   ndvig_dat.h
**  Authors     :
**  Created on  :
**  Modified on :
**  Description :   ndvig_dat
*/

#pragma once

#include "lib_common/interface.h"

struct ndvig_dat
{
	~ndvig_dat()
	{
		_CMN::TInterface::deleteSymgen(symgen);
	}

	_CMN::TSym *getFirst(void)
	{
		return &sym_Ndvig_scale;
	}

	_CMN::TSym *getLast(void)
	{
		return &sym_lim_gor;
	}

	_CMN::TSymgen *symgen = 0;
	_CMN::TSym sym_Ndvig_scale = { 0, "Ndvig_scale" };
	_CMN::TSym sym_lim_gor = { 0, "lim_gor" };

};
