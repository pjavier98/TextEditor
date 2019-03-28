#ifndef _badness
#define _badness

#include "../utilities/header.h"

/*
 *
 */
lli print_text(vlli V_Print, vs Words, lli size, ofstream &f_out);

/*
 *
 */
vlli make_arrays(vvlli matrix, lli size);

/*
 *
 */
vvlli make_matrix(lli size, lli weight, vlli Length_Words);

/*
 *
 */
lli print_to_text(vlli V_Print, vs Words, lli size, ofstream &f_out);

/*
 *
 */
void badness();

#endif