#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "parse.h"
#include "process.h"

struct plantri *get_plantri(int faces, char *str)
{
	struct plantri *ret = malloc(sizeof(struct plantri));
	int i = 0;
	int j;
	ret->faces = malloc(sizeof(int *) * faces);
	//printf("%d faces!\n", faces);
	while (faces--) {
		ret->faces[i] = malloc(sizeof(int *) * faces);
		for (j=0; j<3; j++) {
			ret->faces[i][j] = str[j]-'a';
			//printf("%d ", ret->faces[i][j]);
		}
		//printf("\n");
		i++;
		str = strchr(str, ',')+1;
	}
	return ret;
}

int main()
{
	int n;
	char *cmd = malloc(100);
	int fa;
	char *st = malloc(10000);
	int i;
	for (n=3; n<=10; n++) {
		sprintf(cmd, "./plantri -a %d > in.txt", n);
		// This is a hack!!!11!1!1! Proceed with caution..
		system(cmd);
		FILE *infile = fopen("in.txt", "r");
		while (fscanf(infile, "%d %s\n", &fa, st) == 2) {
			struct plantri *pt = get_plantri(fa, st);
			process(plantri);
			for (i=0; i<fa; i++)
				free(pt->faces[i]);
			free(pt->faces);
			free(pt);
		}
		fclose(infile);
	}
	free(cmd);
	free(st);
	return 0;
}
