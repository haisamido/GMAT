/* getqav.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__14 = 14;

/* $Procedure      GETQAV ( Compute/not-compute Q and AV ) */
/* Subroutine */ int getqav_(logical *check, char *fframe, char *tframe, 
	doublereal *epoch, integer *n, logical *avflg, doublereal *q, 
	doublereal *av, logical *ok, char *error, ftnlen fframe_len, ftnlen 
	tframe_len, ftnlen error_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int chkin_(char *, ftnlen), repmc_(char *, char *,
	     char *, char *, ftnlen, ftnlen, ftnlen, ftnlen), repmf_(char *, 
	    char *, doublereal *, integer *, char *, char *, ftnlen, ftnlen, 
	    ftnlen, ftnlen), reset_(void), xf2rav_(doublereal *, doublereal *,
	     doublereal *);
    extern logical failed_(void);
    static doublereal pm[9]	/* was [3][3] */, xm[36]	/* was [6][6] 
	    */;
    extern /* Subroutine */ int erract_(char *, char *, ftnlen, ftnlen);
    static char savact[80];
    extern /* Subroutine */ int getmsg_(char *, char *, ftnlen, ftnlen), 
	    chkout_(char *, ftnlen);
    static char longms[1840];
    extern /* Subroutine */ int pxform_(char *, char *, doublereal *, 
	    doublereal *, ftnlen, ftnlen), errprt_(char *, char *, ftnlen, 
	    ftnlen);
    static char savrpt[80];
    extern logical return_(void);
    extern /* Subroutine */ int sxform_(char *, char *, doublereal *, 
	    doublereal *, ftnlen, ftnlen), m2q_(doublereal *, doublereal *);

/* $ Abstract */

/*     This routine either computes attitude quaternions and, */
/*     optionally, angular velocities for given ``from'' and ``to'' */
/*     frames at given epochs or verifies that they cannot be computed. */

/* $ Disclaimer */

/*     THIS SOFTWARE AND ANY RELATED MATERIALS WERE CREATED BY THE */
/*     CALIFORNIA INSTITUTE OF TECHNOLOGY (CALTECH) UNDER A U.S. */
/*     GOVERNMENT CONTRACT WITH THE NATIONAL AERONAUTICS AND SPACE */
/*     ADMINISTRATION (NASA). THE SOFTWARE IS TECHNOLOGY AND SOFTWARE */
/*     PUBLICLY AVAILABLE UNDER U.S. EXPORT LAWS AND IS PROVIDED "AS-IS" */
/*     TO THE RECIPIENT WITHOUT WARRANTY OF ANY KIND, INCLUDING ANY */
/*     WARRANTIES OF PERFORMANCE OR MERCHANTABILITY OR FITNESS FOR A */
/*     PARTICULAR USE OR PURPOSE (AS SET FORTH IN UNITED STATES UCC */
/*     SECTIONS 2312-2313) OR FOR ANY PURPOSE WHATSOEVER, FOR THE */
/*     SOFTWARE AND RELATED MATERIALS, HOWEVER USED. */

/*     IN NO EVENT SHALL CALTECH, ITS JET PROPULSION LABORATORY, OR NASA */
/*     BE LIABLE FOR ANY DAMAGES AND/OR COSTS, INCLUDING, BUT NOT */
/*     LIMITED TO, INCIDENTAL OR CONSEQUENTIAL DAMAGES OF ANY KIND, */
/*     INCLUDING ECONOMIC DAMAGE OR INJURY TO PROPERTY AND LOST PROFITS, */
/*     REGARDLESS OF WHETHER CALTECH, JPL, OR NASA BE ADVISED, HAVE */
/*     REASON TO KNOW, OR, IN FACT, SHALL KNOW OF THE POSSIBILITY. */

/*     RECIPIENT BEARS ALL RISK RELATING TO QUALITY AND PERFORMANCE OF */
/*     THE SOFTWARE AND ANY RELATED MATERIALS, AND AGREES TO INDEMNIFY */
/*     CALTECH AND NASA FOR ALL THIRD-PARTY CLAIMS RESULTING FROM THE */
/*     ACTIONS OF RECIPIENT IN THE USE OF THE SOFTWARE. */

/* $ Required_Reading */

/*     None. */

/* $ Keywords */

/*     None. */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     CHECK      I   Run mode: .TRUE. for check, .FALSE. for compute */
/*     FFRAME     I   Name of the ``from'' frame. */
/*     TFRAME     I   Name of the ``to'' frame. */
/*     EPOCH      I   Buffer of epochs (ETs). */
/*     N          I   Number of epochs. */
/*     AVFLG      I   AV flag: .TRUE. to compute, .FALSE. to not compute */
/*     Q          O   Output quaternion buffer */
/*     AV         O   Output AV buffer */
/*     OK         O   Success flag */
/*     ERROR      O   Error message */

/* $ Detailed_Input */

/*     CHECK       is the run mode: .TRUE. for check, .FALSE. for */
/*                 compute. */

/*     FFRAME      is the name of the ``from'' frame. */

/*     TFRAME      is the name of the ``to'' frame. */

/*     EPOCH       is the buffer of epochs (ETs). */

/*     N           is the number of epochs. */

/*     AVFLG       is the angular velocity flag: .TRUE. for computing */
/*                 AVs, .FALSE. for not computing AVs. */

/* $ Detailed_Output */

/*     Q           is the array of output quaternions rotating from the */
/*                 ``from'' frame to the ``to'' frames at each of the */
/*                 epochs. Undefined if routine is run in check mode. */

/*     AV          is the array of output angular velocities of the */
/*                 ``to'' frame w.r.t. the ``from'' frame, in the */
/*                 ``from'' frame. */

/*     OK          is the success flag: .TRUE. for success, .FALSE. for */
/*                 failure. */

/*     ERROR       is the error message. Blank if OK is .TRUE. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/*     The routine uses error/report mode RETURN/NONE and returns */
/*     success/failure flag and error message as outputs. */

/* $ Files */

/*     All applicable kernels must be loaded prior to calling this */
/*     routine. */

/* $ Particulars */

/*     This routine resets error handling to RETURN and error report to */
/*     NONE and attempts to compute a 3x3 or 6x6 rotation from the */
/*     ``from'' frame to the ``to'' frame using PXFORM or SXFORM for */
/*     each of the input epochs. */

/*     If this routine is called in check mode, it verifies that this */
/*     attempt failed for all epochs. If PXFORM/SXFORM call succeeded for */
/*     even one point, the routine returns failure status and */
/*     description of the error. */

/*     If this routine is called in compute mode, it verifies that this */
/*     attempt succeeded for all epochs. If yes, it returns with success */
/*     status and Q and AV buffers filled with rotations and AVs. If */
/*     PXFORM/SXFORM did not succeed for even one point, the routine */
/*     returns failure status and description of the error. */

/*     In either case, before returning the routine resets error handing */
/*     mode and report type to what they were before the call. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     All applicable kernels must loaded prior to calling this routine. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    Version 1.0.0, 22-AUG-2008 (BVS) */

/* -& */

/*     Local parameters. */


/*     Local variables. */


/*     Save everything to prevent potential memory problems in f2c'ed */
/*     version. */


/*     SPICELIB functions. */


/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else {
	chkin_("GETQAV", (ftnlen)6);
    }

/*     Save previous error and report modes and reset them to RETURN and */
/*     NONE. */

    erract_("GET", savact, (ftnlen)3, (ftnlen)80);
    erract_("SET", "RETURN", (ftnlen)3, (ftnlen)6);
    errprt_("GET", savrpt, (ftnlen)3, (ftnlen)80);
    errprt_("SET", "NONE", (ftnlen)3, (ftnlen)4);

/*     Loop over epochs and compute rotation for each of them. */

    *ok = TRUE_;
    s_copy(error, " ", error_len, (ftnlen)1);
    i__ = 1;
    while(i__ <= *n && *ok) {

/*        Try to compute rotation. */

	if (*avflg) {
	    sxform_(fframe, tframe, &epoch[i__ - 1], xm, fframe_len, 
		    tframe_len);
	} else {
	    pxform_(fframe, tframe, &epoch[i__ - 1], pm, fframe_len, 
		    tframe_len);
	}

/*        Did SXFORM/PXFORM fail or succeed? Are we checking or */
/*        computing? */

	if (*check && ! failed_()) {

/*           Bad: we are checking and it did not fail. Set OK flag to */
/*           failure and put together an error description. */

	    *ok = FALSE_;
	    s_copy(error, "# transformation from '#' frame to '#' frame coul"
		    "d be computed at ET #", error_len, (ftnlen)70);
	    if (*avflg) {
		repmc_(error, "#", "State (6x6)", error, error_len, (ftnlen)1,
			 (ftnlen)11, error_len);
	    } else {
		repmc_(error, "#", "Position (3x3)", error, error_len, (
			ftnlen)1, (ftnlen)14, error_len);
	    }
	    repmc_(error, "#", fframe, error, error_len, (ftnlen)1, 
		    fframe_len, error_len);
	    repmc_(error, "#", tframe, error, error_len, (ftnlen)1, 
		    tframe_len, error_len);
	    repmf_(error, "#", &epoch[i__ - 1], &c__14, "E", error, error_len,
		     (ftnlen)1, (ftnlen)1, error_len);
	} else if (! (*check) && failed_()) {

/*           Bad: we are computing and it failed. Set OK flag to failure */
/*           and put together an error description. Reset error handling. */

	    *ok = FALSE_;
	    s_copy(error, "# transformation from '#' frame to '#' frame coul"
		    "d not be computed at ET #. # error was: #", error_len, (
		    ftnlen)90);
	    if (*avflg) {
		repmc_(error, "#", "State (6x6)", error, error_len, (ftnlen)1,
			 (ftnlen)11, error_len);
	    } else {
		repmc_(error, "#", "Position (3x3)", error, error_len, (
			ftnlen)1, (ftnlen)14, error_len);
	    }
	    repmc_(error, "#", fframe, error, error_len, (ftnlen)1, 
		    fframe_len, error_len);
	    repmc_(error, "#", tframe, error, error_len, (ftnlen)1, 
		    tframe_len, error_len);
	    repmf_(error, "#", &epoch[i__ - 1], &c__14, "E", error, error_len,
		     (ftnlen)1, (ftnlen)1, error_len);
	    if (*avflg) {
		repmc_(error, "#", "SXFORM", error, error_len, (ftnlen)1, (
			ftnlen)6, error_len);
	    } else {
		repmc_(error, "#", "PXFORM", error, error_len, (ftnlen)1, (
			ftnlen)6, error_len);
	    }
	    getmsg_("LONG", longms, (ftnlen)4, (ftnlen)1840);
	    repmc_(error, "#", longms, error, error_len, (ftnlen)1, (ftnlen)
		    1840, error_len);
	    reset_();
	} else if (*check && failed_()) {

/*           Good: we are checking and it failed. Reset error handling */
/*           and move on to the next epoch. */

	    reset_();
	} else if (! (*check) && ! failed_()) {

/*           Good: we are computing and it did not fail. Compute and */
/*           buffer quaternion and AV and move on to the next epoch. */

	    if (*avflg) {

/*              Decompose 6x6 matrix into 3x3 matrix and AV. */

		xf2rav_(xm, pm, &av[i__ * 3 - 3]);
	    }

/*           Buffer quaternion. */

	    m2q_(pm, &q[(i__ << 2) - 4]);
	}

/*        Move on to the next epoch. */

	++i__;
    }

/*     Restore original error and report modes. */

    erract_("SET", savact, (ftnlen)3, (ftnlen)80);
    errprt_("SET", savrpt, (ftnlen)3, (ftnlen)80);

/*     All done. */

    chkout_("GETQAV", (ftnlen)6);
    return 0;
} /* getqav_ */

