#ifndef PROCESS_H
#define PROCESS_H
#include "parse.h"

// prints the number of unique vertex assignments which
// correspond to face colorings. If zero != 0, then the
// possible set is {-1, 0, 1}; else it is {-1, 1}
void process (plantri* tri, bool zero);

// prints the vertex assignments which correspond to face
// colorings. Similar to process.
void process_all (plantri* tri, bool zero);
#endif
