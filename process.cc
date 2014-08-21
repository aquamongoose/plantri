#include <bits/stdc++.h>
#include "process.h"
#include "parse.h"

// a ^ b
int pow (int a, int b) {
  if (b == 0) return 1;
  int x = pow (a, b / 2);
  if (b % 2 == 1) return a * x * x;
  else return x * x;
}

int process_dfs (int at, int N, plantri* tri,
		 vector<int> &val, vector<int> &pos, bool zero) {
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
    for (int i = 0; i < 3 - !zero; i++) {
      for (int j = 0; j < 3; j++) {
	val[tri -> faces[at][j]] += x[i];
	val[tri -> faces[at][j]] %= 3;
      }
      tot += process_dfs (at + 1, N, tri, val, pos, zero);
      for (int j = 0; j < 3; j++) {
	val[tri -> faces[at][j]] += 3 - x[i];
	val[tri -> faces[at][j]] %= 3;
      }
    }
    return tot;
  }
}

int process (plantri* tri, bool zero) {
  int N = tri -> N;
  assert (tri -> faces.size() == 2 * N - 4);
  vector<int> val(N);
  vector<int> pos(pow (3, N));
  int ans = process_dfs (0, N, tri, val, pos, zero);
  printf ("There are %d of %d assignments which work.\n", ans, pow(3, N));
  return ans;
}

void process_all(plantri* tri, bool zero) {
  int N = tri -> N;
  vector<int> val(N);
  vector<int> pos(pow (3, N));
  int ans = process_dfs (0, N, tri, val, pos, zero);
  for (int i = 0; i < pow(3, N); i++) {
    if (pos[i] != 0) {
      int c = i;
      for (int j = 0; j < N; j++) {
	printf ("%d", c % 3);
	c /= 3;
      }
      printf (": %d\n", pos[i]);
    }
  }
}
