/* parcml.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;

/* $Procedure      PARCML ( Parse command line) */
/* Subroutine */ int parcml_(char *line, integer *maxkey, char *clkeys, 
	logical *clflag, char *clvals, logical *found, ftnlen line_len, 
	ftnlen clkeys_len, ftnlen clvals_len)
{
    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    static char hkey[1024];
    static integer i__;
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    static char hline[1024];
    extern /* Subroutine */ int ucase_(char *, char *, ftnlen, ftnlen);
    static integer clidx;
    static char uline[1024], lngwd[1024];
    extern integer rtrim_(char *, ftnlen);
    extern /* Subroutine */ int ljust_(char *, char *, ftnlen, ftnlen);
    extern integer isrchc_(char *, integer *, char *, ftnlen, ftnlen);
    static integer begpos, pclidx;
    static char hlngwd[1024];
    static integer endpos;
    extern /* Subroutine */ int chkout_(char *, ftnlen), nextwd_(char *, char 
	    *, char *, ftnlen, ftnlen, ftnlen);
    extern logical return_(void);
    extern integer pos_(char *, char *, integer *, ftnlen, ftnlen);

/* $ Abstract */

/*     This routine parses "command-line" looking line and returns */
/*     values of requested keys. */

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
/*     LINE       I   Input line. */
/*     MAXKEY     I   Number of keys. */
/*     CLKEYS     I   Keys. */
/*     CLFLAG     O   "Key-found" flags. */
/*     CLVALS     O   Key values. */
/*     FOUND      O   Flag indicating that at least one key was found. */

/* $ Detailed_Input */

/*     LINE        Input line in a format "-key value -key value ..." */

/*     MAXKEY      Total number of keys to look for. */

/*     CLKEYS      Keys to look for; uppercased. */

/* $ Detailed_Output */

/*     CLFLAG      Flags set TRUE if corresponding key was found. */

/*     CLVALS      Values key; if key wasn't found, value set to */
/*                 blank string. */

/*     FOUND       .TRUE. if at least one key was found. */
/*                 Otherwise -- .FALSE. */

/* $ Parameters */

/*     TBD. */

/* $ Exceptions */

/*     TBD */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     TBD */

/* $ Examples */

/*     Let CLKEYS be */

/*        CLKEYS(1) = '-SETUP' */
/*        CLKEYS(2) = '-TO' */
/*        CLKEYS(3) = '-FROM' */
/*        CLKEYS(4) = '-HELP' */

/*     then: */

/*     line '-setup my.file -from utc -to sclk' */
/*     will be parsed as */

/*        CLFLAG(1) = .TRUE.       CLVALS(1) = 'my.file' */
/*        CLFLAG(2) = .TRUE.       CLVALS(2) = 'utc' */
/*        CLFLAG(3) = .TRUE.       CLVALS(3) = 'sclk' */
/*        CLFLAG(4) = .FALSE.      CLVALS(4) = ' ' */
/*        FOUND = .TRUE. */

/*     line '-setup my.file -setup your.file' */
/*     will be parsed as */

/*        CLFLAG(1) = .TRUE.       CLVALS(1) = 'your.file' */
/*        CLFLAG(2) = .FALSE.      CLVALS(2) = ' ' */
/*        CLFLAG(3) = .FALSE.      CLVALS(3) = ' ' */
/*        CLFLAG(4) = .FALSE.      CLVALS(4) = ' ' */
/*        FOUND = .TRUE. */

/*     line '-setup my.file -SeTuP your.file' */
/*     will be parsed as */

/*        CLFLAG(1) = .TRUE.       CLVALS(1) = 'your.file' */
/*        CLFLAG(2) = .FALSE.      CLVALS(2) = ' ' */
/*        CLFLAG(3) = .FALSE.      CLVALS(3) = ' ' */
/*        CLFLAG(4) = .FALSE.      CLVALS(4) = ' ' */
/*        FOUND = .TRUE. */

/*     line '-help' */
/*     will be parsed as */

/*        CLFLAG(1) = .FALSE.      CLVALS(1) = ' ' */
/*        CLFLAG(2) = .FALSE.      CLVALS(2) = ' ' */
/*        CLFLAG(3) = .FALSE.      CLVALS(3) = ' ' */
/*        CLFLAG(4) = .TRUE.       CLVALS(4) = ' ' */
/*        FOUND = .TRUE. */

/*     and so on. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     B.V. Semenov    (JPL) */

/* $ Version */

/* -    Alpha Version 1.0.0, 12-SEP-2008 (BVS) */


/* -& */

/*     Save everything to prevent potential memory problems in f2c'ed */
/*     version. */


/*     SPICELIB functions. */


/*     Standard SPICE error handling. */

    if (return_()) {
	return 0;
    } else {
	chkin_("PARCML", (ftnlen)6);
    }

/*     Command line parse loop. Set initial values to blanks. */

    i__1 = *maxkey;
    for (i__ = 1; i__ <= i__1; ++i__) {
	clflag[i__ - 1] = FALSE_;
	s_copy(clvals + (i__ - 1) * clvals_len, " ", clvals_len, (ftnlen)1);
    }
    *found = FALSE_;
    s_copy(hline, line, (ftnlen)1024, line_len);
    pclidx = 0;
    clidx = 0;
    while(s_cmp(hline, " ", (ftnlen)1024, (ftnlen)1) != 0) {

/*        Get next word, uppercase it. */

	nextwd_(hline, lngwd, hline, (ftnlen)1024, (ftnlen)1024, (ftnlen)1024)
		;
	ucase_(lngwd, hlngwd, (ftnlen)1024, (ftnlen)1024);
	clidx = isrchc_(hlngwd, maxkey, clkeys, (ftnlen)1024, clkeys_len);

/*        Is the token that we found a command line key? */

	if (clidx != 0) {

/*           Is it the first key that we have found? */

	    if (pclidx != 0) {

/*              It's not. Save value of the previous key. Compute begin */
/*              and end position of substring that contains this */
/*              value. */

		ucase_(line, uline, line_len, (ftnlen)1024);
		begpos = pos_(uline, clkeys + (pclidx - 1) * clkeys_len, &
			c__1, (ftnlen)1024, rtrim_(clkeys + (pclidx - 1) * 
			clkeys_len, clkeys_len)) + rtrim_(clkeys + (pclidx - 
			1) * clkeys_len, clkeys_len);
/* Writing concatenation */
		i__2[0] = 1, a__1[0] = " ";
		i__2[1] = rtrim_(clkeys + (clidx - 1) * clkeys_len, 
			clkeys_len), a__1[1] = clkeys + (clidx - 1) * 
			clkeys_len;
		s_cat(hkey, a__1, i__2, &c__2, (ftnlen)1024);
		endpos = pos_(uline, hkey, &begpos, (ftnlen)1024, rtrim_(hkey,
			 (ftnlen)1024) + 1);

/*              Extract the value, left-justify and RTRIM it. Set */
/*              "value present" flag to .TRUE. */

		s_copy(clvals + (pclidx - 1) * clvals_len, line + (begpos - 1)
			, clvals_len, endpos - (begpos - 1));
		ljust_(clvals + (pclidx - 1) * clvals_len, clvals + (pclidx - 
			1) * clvals_len, clvals_len, clvals_len);
		s_copy(clvals + (pclidx - 1) * clvals_len, clvals + (pclidx - 
			1) * clvals_len, clvals_len, rtrim_(clvals + (pclidx 
			- 1) * clvals_len, clvals_len));
		clflag[pclidx - 1] = TRUE_;

/*              Check whether we already parsed the whole line. */

		if (s_cmp(hline, " ", (ftnlen)1024, (ftnlen)1) != 0) {

/*                 We are not at the end of the command line. There is */
/*                 more stuff to parse and we put this stuff to */
/*                 the HLINE. */

		    i__1 = endpos + 1 + rtrim_(clkeys + (clidx - 1) * 
			    clkeys_len, clkeys_len) - 1;
		    s_copy(hline, line + i__1, (ftnlen)1024, line_len - i__1);
		}

/*              Now reset our line and previous index. */

		i__1 = endpos;
		s_copy(line, line + i__1, line_len, line_len - i__1);
	    }

/*           Save current key index in as previous. */

	    pclidx = clidx;
	}
    }

/*     We need to save the last value. */

    if (pclidx != 0) {
	*found = TRUE_;

/*        Save the last value. */

	clflag[pclidx - 1] = TRUE_;
	if (rtrim_(line, line_len) > rtrim_(clkeys + (pclidx - 1) * 
		clkeys_len, clkeys_len)) {

/*           Compute begin position of, extract, left justify and */
/*           RTRIM the last value. */

	    ucase_(line, uline, line_len, (ftnlen)1024);
	    begpos = pos_(uline, clkeys + (pclidx - 1) * clkeys_len, &c__1, (
		    ftnlen)1024, rtrim_(clkeys + (pclidx - 1) * clkeys_len, 
		    clkeys_len)) + rtrim_(clkeys + (pclidx - 1) * clkeys_len, 
		    clkeys_len);
	    s_copy(clvals + (pclidx - 1) * clvals_len, line + (begpos - 1), 
		    clvals_len, line_len - (begpos - 1));
	    ljust_(clvals + (pclidx - 1) * clvals_len, clvals + (pclidx - 1) *
		     clvals_len, clvals_len, clvals_len);
	    s_copy(clvals + (pclidx - 1) * clvals_len, clvals + (pclidx - 1) *
		     clvals_len, clvals_len, rtrim_(clvals + (pclidx - 1) * 
		    clvals_len, clvals_len));
	} else {

/*           The key is the last thing on the line. So, it's value */
/*           is blank. */

	    s_copy(clvals + (pclidx - 1) * clvals_len, " ", clvals_len, (
		    ftnlen)1);
	}
    }
    chkout_("PARCML", (ftnlen)6);
    return 0;
} /* parcml_ */

