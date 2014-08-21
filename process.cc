#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "parse.h"

int process_dfs (int at, int N, plantri* tri,
		 int* val, int* pos, int zero) {
  if (at == 2 * N - 4) {
    int moo = 0;
    for (int i = 0; i < N; i++) {
      moo *= 3;
      moo += val[i];
    }
    return pos[moo] ? 0 : (pos[moo] = 1);
  }
  else {
    int x[3] = {2, 1, 0};
    int tot = 0;
    for (int i = 0; i < 3 - !!zero; i++) {
      for (int j = 0; j < 3; j++) {
	val[tri -> faces[at][j]] += x[i];
	val[tri -> faces[at][j]] %= 3;
      }
      tot += process_dfs (at + 1, N, tri, val, pos, zero);
      for (int j = 0; j < 3; j++) {
	val[tri -> faces[at][j]] -= 3 - x[i];
	val[tri -> faces[at][j]] %= 3;
      }
    }
    return tot;
  }
}

void process (plantri* tri, int zero) {
  int N = tri -> N;
  int* val = (int*) calloc ((size_t) N, sizeof(int));
  int* pos = (int*) calloc ((size_t) (1 << (2*N)), sizeof(int));
  int ans = process_dfs (0, N, tri, val, pos, zero);
  free(pos);
  free(val);
  printf ("There are %d assignments which work.\n", ans);
}

void process_all(plantri* tri, int zero) {
  int N = tri -> N;
  int* val = (int*) calloc ((size_t) N, sizeof(int));
  int* pos = (int*) calloc ((size_t) (1 << (2*N)), sizeof(int));
  int ans = process_dfs (0, N, tri, val, pos, zero);
  for (int i = 0; i < (1 << (2*N)); i++) {
    if (pos[i] != 0) {
      int c = i;
      for (int j = 0; j < N; j++) {
	printf ("%d", c % 3);
	c /= 3;
      }
      printf (": %d\n", pos[i]);
    }
  }
  free(pos);
  free(val);
}
