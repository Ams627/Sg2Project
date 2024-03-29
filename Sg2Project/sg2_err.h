/*
 * Copyright 2011 Philippe Blanc <philippe.blanc@mines-paristech.fr>
 *
 * This file is part of libsg2.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * Lesser GNU General Public License for more details.
 *
 * You should have received a copy of the Lesser GNU General Public
 * License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef SG2_ERR_H_
#define SG2_ERR_H_

#ifdef _MINGW_
#include <windows.h>
#endif

#ifdef EXPORT
#undef EXPORT
#endif

#ifdef _VISUAL_
#define EXPORT _declspec (dllexport)
#else
#define EXPORT
#endif

#define SG2_ERR_DATE_CREATE_JD_MALLOC_1 -100
#define SG2_ERR_DATE_CREATE_JD_MALLOC_2 -101
#define SG2_ERR_DATE_CREATE_JD_MALLOC_3 -102

#define SG2_ERR_DATE_CREATE_YMD_H_MALLOC_1 -200
#define SG2_ERR_DATE_CREATE_YMD_H_MALLOC_2 -201
#define SG2_ERR_DATE_CREATE_YMD_H_MALLOC_3 -202
#define SG2_ERR_DATE_CREATE_YMD_H_MALLOC_4 -203
#define SG2_ERR_DATE_CREATE_YMD_H_MALLOC_5 -204

#define SG2_ERR_DATE_CREATE_YDOY_H_MALLOC_1 -300
#define SG2_ERR_DATE_CREATE_YDOY_H_MALLOC_2 -301
#define SG2_ERR_DATE_CREATE_YDOY_H_MALLOC_3 -302
#define SG2_ERR_DATE_CREATE_YDOY_H_MALLOC_4 -303

#define SG2_ERR_DATE_JD_SET_JD_TT_MALLOC_1 -400
#define SG2_ERR_DATE_JD_SET_JD_TT_OUTOFPERIOD -401

#define SG2_ERR_HELIOCENTRIC_CREATE_HELIOC_MALLOC_1 -500
#define SG2_ERR_HELIOCENTRIC_CREATE_HELIOC_MALLOC_2 -501
#define SG2_ERR_HELIOCENTRIC_CREATE_HELIOC_MALLOC_3 -502
#define SG2_ERR_HELIOCENTRIC_SET_HELIOC_JDTTNOTSET -510
#define SG2_ERR_HELIOCENTRIC_SET_HELIOC_OUTOFPERIOD -511

#define SG2_ERR_GEOCENTRIC_CREATE_GEOC_MALLOC_1 -600
#define SG2_ERR_GEOCENTRIC_CREATE_GEOC_MALLOC_2 -601
#define SG2_ERR_GEOCENTRIC_CREATE_GEOC_MALLOC_3 -602
#define SG2_ERR_GEOCENTRIC_CREATE_GEOC_MALLOC_4 -603
#define SG2_ERR_GEOCENTRIC_CREATE_GEOC_MALLOC_5 -604
#define SG2_ERR_GEOCENTRIC_CREATE_GEOC_MALLOC_6 -605
#define SG2_ERR_GEOCENTRIC_CREATE_GEOC_MALLOC_7 -606
#define SG2_ERR_GEOCENTRIC_CREATE_GEOC_MALLOC_8 -607
#define SG2_ERR_GEOCENTRIC_SET_GEOC_JDTTNOTSET -610
#define SG2_ERR_GEOCENTRIC_SET_GEOC_OUTOFPERIOD -611

#define SG2_ERR_TOPOCENTRIC_CREATE_GEOPT_MALLOC_1 -700
#define SG2_ERR_TOPOCENTRIC_CREATE_GEOPT_MALLOC_2 -701
#define SG2_ERR_TOPOCENTRIC_CREATE_GEOPT_MALLOC_3 -702
#define SG2_ERR_TOPOCENTRIC_CREATE_GEOPT_MALLOC_4 -703
#define SG2_ERR_TOPOCENTRIC_CREATE_GEOPT_MALLOC_5 -704
#define SG2_ERR_TOPOCENTRIC_CREATE_GEOPT_MALLOC_6 -705
#define SG2_ERR_TOPOCENTRIC_CREATE_GEOPT_MALLOC_7 -706
#define SG2_ERR_TOPOCENTRIC_CREATE_GEOPT_MALLOC_8 -707
#define SG2_ERR_TOPOCENTRIC_CREATE_GEOPT_MALLOC_9 -708
#define SG2_ERR_TOPOCENTRIC_CREATE_GEOPT_MALLOC_10 -709
#define SG2_ERR_TOPOCENTRIC_CREATE_TOPOC_MALLOC_1 -710
#define SG2_ERR_TOPOCENTRIC_CREATE_TOPOC_MALLOC_2 -711
#define SG2_ERR_TOPOCENTRIC_CREATE_TOPOC_MALLOC_3 -712
#define SG2_ERR_TOPOCENTRIC_CREATE_TOPOC_MALLOC_4 -713
#define SG2_ERR_TOPOCENTRIC_CREATE_TOPOC_MALLOC_5 -714
#define SG2_ERR_TOPOCENTRIC_CREATE_TOPOC_MALLOC_6 -715
#define SG2_ERR_TOPOCENTRIC_CREATE_TOPOC_MALLOC_7 -716
#define SG2_ERR_TOPOCENTRIC_CREATE_TOPOC_MALLOC_8 -717
#define SG2_ERR_TOPOCENTRIC_CREATE_TOPOC_MALLOC_9 -718
#define SG2_ERR_TOPOCENTRIC_CREATE_TOPOC_MALLOC_10 -719
#define SG2_ERR_TOPOCENTRIC_CORRECTION_REFRACTION_METHOD -720

#define SG2_ERR_CREATE_SUNPOS_MALLOC_1 -800
#define SG2_ERR_CREATE_SUNPOS_MALLOC_2 -801
#define SG2_ERR_CREATE_SUNPOS_MALLOC_3 -802
#define SG2_ERR_CREATE_SUNPOS_MALLOC_4 -803
#define SG2_ERR_CREATE_SUNPOS_MALLOC_5 -804
#define SG2_ERR_CREATE_SUNPOS_MALLOC_6 -805
#define SG2_ERR_CREATE_SUNPOS_MALLOC_7 -806
#define SG2_ERR_CREATE_SUNPOS_MALLOC_8 -807
#define SG2_ERR_CREATE_SUNPOS_MALLOC_9 -808
#define SG2_ERR_CREATE_SUNPOS_MALLOC_10 -809
#define SG2_ERR_CREATE_SUNPOS_MALLOC_11 -810
#define SG2_ERR_CREATE_SUNPOS_MALLOC_12 -811
#define SG2_ERR_CREATE_SUNPOS_MALLOC_13 -812

#define SG2_ERR_CREATE_TABTILT_MALLOC_1 -900
#define SG2_ERR_CREATE_TABTILT_MALLOC_2 -901
#define SG2_ERR_CREATE_TABTILT_MALLOC_3 -902
#define SG2_ERR_CREATE_TOA_IRRAD_MALLOC_1 -910
#define SG2_ERR_CREATE_TOA_IRRAD_MALLOC_2 -911
#define SG2_ERR_CREATE_TOA_IRRAD_MALLOC_3 -912
#define SG2_ERR_CREATE_TOA_IRRAD_MALLOC_4 -913
#define SG2_ERR_CREATE_TOA_IRRAD_MALLOC_5 -914

#define SG2_ERR_SET_TOA_IRRAD_NTSNOTVALID -920


#ifdef  __cplusplus
extern "C"
{
#endif

#ifdef	__cplusplus
}
#endif

#endif /* SG2_ERR_H_ */
