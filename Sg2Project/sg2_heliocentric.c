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

#define SG2_HELIOCENTRIC_C_

#include "sg2.h"
#include "sg2_precomputed_heliocentric.h"
#include "sg2_err.h"
#include "sg2_date.h"
#include "sg2_heliocentric.h"
#include "sg2_geocentric.h"
#include "sg2_topocentric.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

S_SG2_HELIOC_DATA *SG2_heliocentric_create_helioc_data(unsigned long nd, int *p_err) {
	S_SG2_HELIOC_DATA *p_helioc;


	p_helioc = (S_SG2_HELIOC_DATA *) malloc(sizeof(S_SG2_HELIOC_DATA));
	if (p_helioc == NULL) {
		*p_err = SG2_ERR_HELIOCENTRIC_CREATE_HELIOC_MALLOC_1;
		return NULL;
	}

	p_helioc->nd = nd;
	p_helioc->L = NULL;
	p_helioc->R = NULL;
	p_helioc->p_jd = NULL;

	p_helioc->R = (double *) malloc(nd * sizeof(double));
	if (p_helioc->R == NULL) {
		*p_err = SG2_ERR_HELIOCENTRIC_CREATE_HELIOC_MALLOC_2;
		free(p_helioc);
		return NULL;
	}
	p_helioc->L = (double *) malloc(nd * sizeof(double));
	if (p_helioc->L == NULL) {
		*p_err = SG2_ERR_HELIOCENTRIC_CREATE_HELIOC_MALLOC_3;
		free(p_helioc->R);
		free(p_helioc);
		return NULL;
	}

	return p_helioc;
}

void SG2_heliocentric_delete_helioc_data(S_SG2_HELIOC_DATA *p_helioc, int *p_err) {
	free(p_helioc->R);
	free(p_helioc->L);
	free(p_helioc);
}

void SG2_heliocentric_set_helioc_data(S_SG2_DATE_TABJD *p_jd, S_SG2_HELIOC_DATA *p_helioc,
		int *p_err) {
	short idx0;
	double x, x0, dx;

	if (p_jd->jd_tt_set != 1) {
		*p_err = SG2_ERR_HELIOCENTRIC_SET_HELIOC_JDTTNOTSET;
		return;
	}

	p_helioc->p_jd = p_jd;

	for (unsigned k = 0; k < p_jd->nd; k++) {

		x = (p_jd->jd_tt[k] - SG2_precomputed_heliocentric_R_j0)
				/ SG2_precomputed_heliocentric_R_dj;
		/*
		idx0 = (short) floor(x + 0.5);
		if ((idx0 < 0) || (idx0 > SG2_precomputed_heliocentric_R_nj)) {
			*p_err = SG2_ERR_HELIOCENTRIC_SET_HELIOC_OUTOFPERIOD;
			return;
		}
		p_helioc->R[k] = SG2_precomputed_heliocentric_R[idx0];
		*/
		x0 = floor(x);
		dx = x - x0;

		idx0 = (short) x0;
		if ((idx0 < 0) || (idx0 > (long)SG2_precomputed_heliocentric_R_nj - 1)) {
			*p_err = SG2_ERR_HELIOCENTRIC_SET_HELIOC_OUTOFPERIOD;
			return;
		}
		p_helioc->R[k] = (1.0 - dx) * SG2_precomputed_heliocentric_R[idx0] + dx
				* SG2_precomputed_heliocentric_R[idx0 + 1];
		
		x = (p_jd->jd_tt[k] - SG2_precomputed_heliocentric_L_j0)
				/ SG2_precomputed_heliocentric_L_dj;
		x0 = floor(x);
		dx = x - x0;

		idx0 = (short) x0;
		if ((idx0 < 0) || (idx0 > (long)SG2_precomputed_heliocentric_L_nj - 1)) {
			*p_err = SG2_ERR_HELIOCENTRIC_SET_HELIOC_OUTOFPERIOD;
			return;
		}

		p_helioc->L[k] = (1.0 - dx) * SG2_precomputed_heliocentric_L[idx0] + dx
				* SG2_precomputed_heliocentric_L[idx0 + 1];

	}
}
