/*
**  File        :   angle_ataka_dat.h
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :   angle_ataka_dat
*/

#pragma once

#include "lib_common/interface.h"

struct angle_ataka_dat
{
	~angle_ataka_dat()
	{
		_CMN::TInterface::deleteSymgen(symgen);
	}

	_CMN::TSym *getFirst(void)
	{
		return &sym_alfa_new;
	}

	_CMN::TSym *getLast(void)
	{
		return &sym_AngelAtak_index;
	}

	_CMN::TSymgen *symgen = 0;
	_CMN::TSym sym_alfa_new = { 0, "alfa_new" };
	_CMN::TSym sym_AngelAtak_scale = { 0, "AngelAtak_scale" };
	_CMN::TSym sym_AngelAtak_index = { 0, "AngelAtak_index" };
};
