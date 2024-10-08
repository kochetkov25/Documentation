<span style="color: green;">/*<br />
**  File        :   yakPil152.h<br />
**  Authors     :   <br />
**  Created on  :   <br />
**  Modified on :   <br />
**  Description :   yakPil152<br />
*/</span><br />
<br />
#pragma once<br />
<br />
#include <span style="color: #D69D85">"lib_common/interface.h"</span><br />
<br />
<span style='color:blue'>struct </span><span style="color: #44C9B0;"><span style='color:#44C9B0'>TSymgen</span>_yakPil152</span><br />
{<div style="padding-left: 60px;"><br />
    ~<span style="color: #44C9B0;"><span style='color:#44C9B0'>TSymgen</span>_yakPil152</span>()<br />
    {<div style="padding-left: 60px;"><br />
        _CMN::<span style="color: #44C9B0;">TInterface</span>::deleteSymgen(symgen);<br />
    </div>}<br />
<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>*getFirst(<span style='color:blue'>void</span>)<br />
    {<div style="padding-left: 60px;"><br />
        <span style='color:blue'>return</span> &sym_alfa;<br />
    </div>}<br />
<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>*getLast(<span style='color:blue'>void</span>)<br />
    {<div style="padding-left: 60px;"><br />
        <span style='color:blue'>return</span> &sym_Vbar_scale; <br />
    </div>}<br />
<br />
    _CMN::<span style='color:#44C9B0'>TSymgen</span> *symgen = 0;<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_alfa = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"alfa"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_alfa_ = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"alfa_"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_alfa_new = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"alfa_new"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_flap = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"flap"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_foot = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"foot"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_gPa = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"gPa"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Hbar_index_new = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Hbar_index_new"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Hbar_lim = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Hbar_lim"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_index_fpu = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"index_fpu"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_kurs_zadPU_2 = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"kurs_zadPU_2"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_kursZad = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"kursZad"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_LA_PU = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"LA_PU"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_lim = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"lim"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_lim_gor = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"lim_gor"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_message = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"message"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_metr = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"metr"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_mm_rt = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"mm_rt"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Ny = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Ny"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Ny_2 = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Ny_2"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Ny_2_ = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Ny_2_"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Ny_2t = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Ny_2t"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Ny_symb = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Ny_symb"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Ny_symb_new = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Ny_symb_new"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_object = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"object"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Otklon_scale = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Otklon_scale"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_otklon_scale_new = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"otklon_scale_new"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_otklon_scale_plan_new = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"otklon_scale_plan_new"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_ramka_h_f = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"ramka_h_f"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_ramka_h_f_zal = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"ramka_h_f_zal"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_ramka_h_m = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"ramka_h_m"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_ramka_h_m_zal = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"ramka_h_m_zal"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_ramka1 = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"ramka1"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_ramka2 = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"ramka2"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_scale_obv_minmax_new = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"scale_obv_minmax_new"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_sym_shassi = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"sym_shassi"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_sym_shassi_new_max = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"sym_shassi_new_max"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_sym_shassi_new_min = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"sym_shassi_new_min"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_sym_shassi_new2 = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"sym_shassi_new2"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_SymbLA_new = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"SymbLA_new"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_triangle_d = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"triangle_d"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_triangle_d_new = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"triangle_d_new"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_triangle_d_new_2 = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"triangle_d_new_2"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_triangle_u = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"triangle_u"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_triangle_u_new = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"triangle_u_new"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_triangle_u_new_2 = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"triangle_u_new_2"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Vbar_lim = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Vbar_lim"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_vertN_index_new = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"vertN_index_new"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_aer_gray = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"aer_gray"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_aer_green = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"aer_green"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Hbar_indexB = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Hbar_indexB"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Hbar_indexS = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Hbar_indexS"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Hbar_scale = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Hbar_scale"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_index_obv = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"index_obv"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_kren_scale = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"kren_scale"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_maska = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"maska"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Vbar_index = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Vbar_index"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_VertN_scale = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"VertN_scale"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Vvert_index = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Vvert_index"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Vvert_scale = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Vvert_scale"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_ramka_kurs = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"ramka_kurs"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_SK_index = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"SK_index"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_scale_obv = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"scale_obv"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Ndvig_scale = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Ndvig_scale"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_index_pelengRm_down = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"index_pelengRm_down"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_index_pelengRm_up = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"index_pelengRm_up"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_kurs_index_down = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"kurs_index_down"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_kurs_index_up = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"kurs_index_up"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Kurs_KUR = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Kurs_KUR"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Vist = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Vist"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_otklon_scale = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"otklon_scale"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_kurs_zadPU_plan_up = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"kurs_zadPU_plan_up"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_kurs_zadPU_plan_down = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"kurs_zadPU_plan_down"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_kurs_zadPU_z = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"kurs_zadPU_z"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Kurs_scale = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Kurs_scale"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_kurs_zadPU_cont2 = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"kurs_zadPU_cont2"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_kurs_zad = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"kurs_zad"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_AngelAtak_scale = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"AngelAtak_scale"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_AngelAtak_index = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"AngelAtak_index"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_SK_scale = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"SK_scale"</span> </div>};<br />
    _CMN::<span style='color:#44C9B0'>TSym </span>sym_Vbar_scale = {<div style="padding-left: 60px;"> 0, <span style="color: #D69D85">"Vbar_scale"</span> </div>};<br />
</div>};<br />