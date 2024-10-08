/*
**  File        :   vspeed_dat.h
**  Authors     :
**  Created on  :
**  Modified on :
**  Description :   vspeed_dat
*/

#pragma once

#include "lib_common/interface.h"

struct vspeed_dat
{
	~vspeed_dat()
	{
		_CMN::TInterface::deleteSymgen(symgen);
	}

	_CMN::TSym *getFirst(void)
	{
		return &sym_Vvert_index;
	}

	_CMN::TSym *getLast(void)
	{
		return &sym_Vvert_scale;
	}

	_CMN::TSymgen *symgen = 0;
	_CMN::TSym sym_Vvert_index = { 0, "Vvert_index" };
	_CMN::TSym sym_Vvert_scale = { 0, "Vvert_scale" };
};
