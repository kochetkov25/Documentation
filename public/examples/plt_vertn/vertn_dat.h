/*
**  File        :   vertn_dat.h
**  Authors     :
**  Created on  :
**  Modified on :
**  Description :   vertn_dat
*/

#pragma once

#include "lib_common/interface.h"

struct vertn_dat
{
	~vertn_dat()
	{
		_CMN::TInterface::deleteSymgen(symgen);
	}

	_CMN::TSym *getFirst(void)
	{
		return &sym_VertN_scale;
	}

	_CMN::TSym *getLast(void)
	{
		return &sym_Ny_symb_new;
	}

	_CMN::TSymgen *symgen = 0;
	_CMN::TSym sym_VertN_scale = { 0, "VertN_scale" };
	_CMN::TSym sym_vertN_index_new = { 0, "vertN_index_new" };
	_CMN::TSym sym_Ny_symb_new = { 0, "Ny_symb_new" };
};
