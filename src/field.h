 /*
 				field.h

*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*
*	Part of:	PSFEx
*
*	Author:		E.BERTIN (IAP)
*
*	Contents:	Include for field.c.
*
*	Last modify:	30/03/2009
*
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#ifndef _CONTEXT_H_
#include "context.h"
#endif

#ifndef _FITSWCS_H_
#include "fitswcs.h"
#endif

#ifndef _PSF_H_
#include "psf.h"
#endif

#ifndef _SAMPLE_H_
#include "sample.h"
#endif

#ifndef _PSFMEF_H_
#define _PSFMEF_H_

/*----------------------------- Internal constants --------------------------*/
#define	COUNT_LOADED	1		/* Count detections that are loaded */
#define	COUNT_ACCEPTED	2		/* Count detections that are accepted */

/*------------------------------ Type definitions ---------------------------*/
/*--------------------------- structure definitions -------------------------*/

typedef struct field
  {
  char		catname[MAXCHAR];	/* Input catalog filename */
  char		*rcatname;		/* "Reduced" catalog name */
  char		rtcatname[MAXCHAR];	/* "Reduced", no trail catalog name */
  char		ident[MAXCHAR];		/* Field identifier (read from FITS) */
  int		next;			/* Number of extensions */
  int		ndet;			/* Number of detections (info only) */
  psfstruct	**psf;			/* Array of PSFs */
  wcsstruct	**wcs;			/* Array of WCS structures */
  setstruct	*set;			/* Array of catalogues */
  catstruct	**ccat;			/* Pointers to check-image files */
  double	meanwcspos[NAXIS];	/* Mean pixel coordinate */
  double	meanwcsscale[NAXIS];	/* Mean pixel scale */
  double	maxradius;		/* Maxium radius */
  int		**lcount;		/* Count detections that are loaded */
  int		**acount;		/* Count detections that are accepted */
  }	fieldstruct;

/*---------------------------------- protos --------------------------------*/
extern fieldstruct	*field_init(char *catname);

extern double		dhmedian(double *ra, int n);

extern void		field_count(fieldstruct **fields, setstruct *set,
				int counttype),
			field_end(fieldstruct *field),
			field_locate(fieldstruct *field),
			field_psfsave(fieldstruct *field, char *filename);

void			context_apply(contextstruct *context, psfstruct *psf,
				fieldstruct **fields, int ext, int catindex,
				int ncat),
			context_end(contextstruct *context);

#endif

