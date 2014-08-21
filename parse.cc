#include <bits/stdc++.h>
#include "parse.h"
#include "process.h"

using namespace std;

plantri *get_plantri(int n, char *str)
{
	vector<vector<char> > edges(n);
	plantri *ret = new plantri();
	ret->N = n;
	int faces = n * 2 - 4;
	ret->faces.resize(faces);
	int at = 0;
	while (n--) {
		char *end = strchr(str, ',');
		if (!end) end = str+strlen(str);
		int len = end-str;
		for (int i=0; i<len; i++) {
			edges[at].push_back(str[i]-'a');
		}
		str = end+1;
		at++;
	}

	int curface = 0;
	set<tuple<int, int, int> > seen;
	for (int i=0; i<ret->N; i++) {
		for (int j=0; j<edges[i].size(); j++) {
			vector<int> cur;
			cur.push_back(i);
			cur.push_back(edges[i][j]);
			cur.push_back(edges[i][(j+1)%edges[i].size()]);
			sort(cur.begin(), cur.end());
			tuple<int, int, int> tup = make_tuple(cur[0], cur[1], cur[2]);
			if (!seen.count(tup)) {
				seen.insert(tup);
				ret->faces[curface].resize(3);
				ret->faces[curface][0] = cur[0];
				ret->faces[curface][1] = cur[1];
				ret->faces[curface][2] = cur[2];
				printf("found a face %d %d %d\n", cur[0], cur[1], cur[2]);
				curface++;
			}
		}
	}
	assert(curface == faces);
	return ret;
}

int main()
{
	int n;
	char *cmd = (char *)malloc(100);
	int nod;
	char *st = (char *)malloc(10000);
	int i;
	for (n=3; n<=10; n++) {
		sprintf(cmd, "./plantri -a %d > in.txt", n);
		// This is a hack!!!11!1!1! Proceed with caution..
		system(cmd);
		FILE *infile = fopen("in.txt", "r");
		while (fscanf(infile, "%d %s\n", &nod, st) == 2) {
			plantri *pt = get_plantri(nod, st);
			cout << "start process" << endl;
			process(pt, 0);
			cout << "start process" << endl;
			delete pt;
		}
		fclose(infile);
	}
	free(cmd);
	free(st);
	return 0;
}