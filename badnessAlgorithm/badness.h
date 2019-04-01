#ifndef _badness
#define _badness

#include "../utilities/header.h"

/* 
 * With the cost matrix created, we will have a vector for the total cost
 * the best arrangement and one to write in the solution file. Thereby
 * Initialize the current cost with infinity and the first position with 0,
 * because we have not added anything yet, so we checked using the table
 * the best choices of subproblems to get the optimal solution.
 */
vlli make_arrays(vvlli matrix, lli size);

/* 
 * We create the cost matrix of the remaining space on each line.
 * With this, we calculate the costs of putting the maximum of words
 * in a row, we raise the cost to the cube for greater accuracy,
 * except in the last line because the last one may have more spaces.
 */
vvlli make_matrix(lli size, lli weight, vlli Length_Words);

/*
 * To print the output, we search for which words go on which lines,
 * using the vector print built in the make_matrix function. This vector
 * points to where each cost value came from.
 */
void print_to_text(vlli V_Print, vs Words, lli size, ofstream &f_out);

/* 
 * Main function where we receive the text and put in a vector the words read
 * and their respective sizes. We receive the user what the width of the line will be.
 * With this, we create the matrix with the costs. 
 */
void badness();

#endif
