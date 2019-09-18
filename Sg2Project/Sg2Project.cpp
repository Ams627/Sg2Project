#include "stdafx.h"

/*
 * sg2_calc.c
 *
 *  Created on: 4 f?vr. 2011
 *      Author: pblanc
 */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sg2.h"

int main(int argc, char **argv) {

	S_SG2_DATE_TABJD *p_jd, *p_jd_check;
	S_SG2_DATE_TABYMDH *p_ymdh, *p_ymdh_check;
	S_SG2_DATE_TABYDOYH *p_ydoyh;
	S_SG2_HELIOC_DATA *p_helioc;
	S_SG2_GEOC_DATA *p_geoc;
	S_SG2_TABGEOPOINT *p_gp;
	S_SG2_TOPOC_DATA *p_topoc;
	int err = 0;
	int *p_err = &err;
	int nd;
	int kd;
	int np;
	int kp;
	double lon, lat, elevation;
	double jd, jd0, djd;
	unsigned int count;

	if (argc != 7) {
		fprintf(stderr, "usage : %s lat lon z jd0 number_of_data delta_jd\n", argv[0]);
		return -1;
	}

	lat = atof(argv[1]);
	lon = atof(argv[2]);
	elevation = atof(argv[3]);
	jd0 = atof(argv[4]);
	count = atoi(argv[5]);
	djd = atof(argv[6]);

	nd = count;

	p_jd = SG2_date_create_tabjd(nd, p_err);
	if (*p_err < 0)
		return *p_err;

	jd = jd0;
	p_jd->jd_ut[0] = jd0;
	for (kd = 1; kd < nd; kd++) {
		p_jd->jd_ut[kd] = p_jd->jd_ut[kd - 1] + djd;
	}

	np = 1;
	p_gp = SG2_topocentric_create_tabgeopoint(np, SG2_ELLPSTYPE_SPA, NULL, p_err);
	if (*p_err < 0)
		return *p_err;
	SG2_topocecentric_set_tabgeopoint(&lon, &lat, &elevation, p_gp, p_err);
	if (*p_err < 0)
		return *p_err;


	p_jd_check = SG2_date_create_tabjd(nd, p_err);
	if (*p_err < 0)
		return *p_err;
	p_ymdh = SG2_date_create_tabymdh(nd, p_err);
	if (*p_err < 0)
		return *p_err;
	p_ymdh_check = SG2_date_create_tabymdh(nd, p_err);
	if (*p_err < 0)
		return *p_err;
	p_ydoyh = SG2_date_create_tabydoyh(nd, p_err);
	if (*p_err < 0)
		return *p_err;

	SG2_date_tabjd_to_tabymdh(p_jd, p_ymdh, p_err);
	if (*p_err < 0)
		return *p_err;
	SG2_date_tabymdh_to_tabydoyh(p_ymdh, p_ydoyh, p_err);
	if (*p_err < 0)
		return *p_err;
	SG2_date_tabymdh_to_tabjd(p_ymdh, p_jd_check, p_err);
	if (*p_err < 0)
		return *p_err;
	SG2_date_tabydoyh_to_tabymdh(p_ydoyh, p_ymdh_check, p_err);
	if (*p_err < 0)
		return *p_err;


	SG2_date_set_tabjd_tt(NULL, p_jd, p_err);
	if (*p_err < 0)
		return *p_err;

	p_helioc = SG2_heliocentric_create_helioc_data(p_jd->nd, p_err);
	if (*p_err < 0)
		return *p_err;
	SG2_heliocentric_set_helioc_data(p_jd, p_helioc, p_err);
	if (*p_err < 0)
		return *p_err;
	p_geoc = SG2_geocentric_create_geoc_data(p_jd->nd, p_err);
	if (*p_err < 0)
		return *p_err;
	SG2_geocentric_set_geoc_data(p_jd, p_helioc, p_geoc, p_err);
	if (*p_err < 0)
		return *p_err;
	p_topoc = SG2_topocentric_create_topoc_data(np, nd, p_err);
	if (*p_err < 0)
		return *p_err;
	SG2_topocentric_set_topoc_data(p_geoc, p_gp, p_topoc, p_err);
	if (*p_err < 0)
		return *p_err;


	printf(
		"# Solar Geometry 2\n"
		"# Fast and accurate Solar Position Algorithm\n"
		"# MINES ParisTech / ARMINES\n"
		"# The research leading to these results of the ENDORSE project that has received funding from the European Union’s Seventh Framework Programme (FP7/2007-2013) under Grant Agreement no. 262892 (www.endorse-fp7.eu)\n"
		"#\n"
		"# JDUT: universal julian date (day)\n"
		"# YYYY: year\n"
		"# MM: month of the year\n"
		"# DD: day of the month\n"
		"# H: hour of the day (decimal hour)\n"
		"# DOY: day of the year\n"
		"# DELTA: topocentric declination (radian)\n"
		"# OMEGA: topocentric hour angle (radian)\n"
		"# GAMMA_S0: topocentric Sun elevation angle without refraction correction (radian)\n"
		"# ALPHA_S: topocentric Sun azimuth angle Eastward from North (radian)\n"
		"#\n");

	printf("# latitude: %f; longitude: %f\n", lat, lon);
	printf("# JDUT;YYYY;MM;DD;H;DOY;DELTA;OMEGA;GAMMA_S0;ALPHA_S\n");

	for (kd = 0; kd < nd; kd++) {

		printf("%16.8f;%d;%d;%d;%7.4f;%d;",
			p_jd->jd_ut[kd],
			p_ymdh->y[kd],
			p_ymdh->m[kd],
			p_ymdh->d[kd],
			p_ymdh->h[kd],
			p_ydoyh->doy[kd]);

		kp = 0;
		printf("%14.12f;%14.12f;%14.12f;%14.12f\n",
			p_topoc->delta[kp][kd],
			p_topoc->omega[kp][kd],
			p_topoc->gamma_S0[kp][kd],
			p_topoc->alpha_S[kp][kd]);
	}

	SG2_date_delete_tabjd(p_jd, p_err);
	SG2_date_delete_tabymdh(p_ymdh, p_err);
	SG2_date_delete_tabymdh(p_ymdh_check, p_err);
	SG2_date_delete_tabydoyh(p_ydoyh, p_err);
	SG2_date_delete_tabjd(p_jd_check, p_err);

	SG2_geocentric_delete_geoc_data(p_geoc, p_err);
	SG2_heliocentric_delete_helioc_data(p_helioc, p_err);
	SG2_topocentric_delete_tabgeopoint(p_gp, p_err);
	SG2_topocentric_delete_topoc_data(p_topoc, p_err);

	return 0;

}


