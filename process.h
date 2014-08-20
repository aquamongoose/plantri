#ifndef PROCESS_H
#define PROCESS_H
#include "parse.h"

// returns the number of unique vertex assignments which
// correspond to face colorings. If zero != 0, then the
// possible set is {-1, 0, 1}; else it is {-1, 1}
int process (struct plantri* tri, int zero);
#endif
