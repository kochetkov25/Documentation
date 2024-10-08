/*
**  File        :   aviag_dat.h
**  Authors     :
**  Created on  :
**  Modified on :
**  Description :   aviag_dat
*/

#pragma once

#include "lib_common/interface.h"

struct aviag_dat
{
	~aviag_dat()
	{
		_CMN::TInterface::deleteSymgen(symgen);
	}

	_CMN::TSym *getFirst(void)
	{
		return &sym_maska;
	}

	_CMN::TSym *getLast(void)
	{
		return &sym_flap;
	}

	_CMN::TSymgen *symgen = 0;
	_CMN::TSym sym_maska = { 0, "maska" };
	_CMN::TSym sym_SymbLA_new = { 0, "SymbLA_new" };
	_CMN::TSym sym_kren_scale = { 0, "kren_scale" };
	_CMN::TSym sym_sym_shassi_new_max = { 0, "sym_shassi_new_max" };
	_CMN::TSym sym_sym_shassi_new_min = { 0, "sym_shassi_new_min" };
	_CMN::TSym sym_flap = { 0, "flap" };
};
