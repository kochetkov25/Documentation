/*
**  File        :   kurs_dat.h
**  Authors     :
**  Created on  :
**  Modified on :
**  Description :   kurs_dat
*/

#pragma once

#include "lib_common/interface.h"

struct kurs_dat
{
	~kurs_dat()
	{
		_CMN::TInterface::deleteSymgen(symgen);
	}

	_CMN::TSym *getFirst(void)
	{
		return &sym_Kurs_scale;
	}

	_CMN::TSym *getLast(void)
	{
		return &sym_otklon_scale_new;
	}
	_CMN::TSymgen *symgen = 0;
	_CMN::TSym sym_Kurs_scale = { 0, "Kurs_scale" };
	_CMN::TSym sym_Kurs_KUR = { 0, "Kurs_KUR" };
	_CMN::TSym sym_kurs_zad = { 0, "kurs_zad" };
	_CMN::TSym sym_kurs_zadPU_plan_up = { 0, "kurs_zadPU_plan_up" };
	_CMN::TSym sym_kurs_zadPU_plan_down = { 0, "kurs_zadPU_plan_down" };
	_CMN::TSym sym_index_fpu = { 0, "index_fpu" };
	_CMN::TSym sym_index_pelengRm_down = { 0, "index_pelengRm_down" };
	_CMN::TSym sym_index_pelengRm_up = { 0, "index_pelengRm_up" };
	_CMN::TSym sym_kurs_index_down = { 0, "kurs_index_down" };
	_CMN::TSym sym_kurs_index_up = { 0, "kurs_index_up" };
	_CMN::TSym sym_ramka_kurs = { 0, "ramka_kurs" };
	_CMN::TSym sym_otklon_scale_new = { 0, "otklon_scale_new" };
};
