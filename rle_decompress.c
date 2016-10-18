#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *inputfp, *outputfp;
	char ch;
	long int charcount = 0;
	inputfp = fopen(argv[1], "r");
	if(inputfp == NULL) {
		perror("E:cannot open file");
		return 1;
	}
	outputfp = fopen(argv[2], "w");
	if(outputfp == NULL) {
		perror("E:cannot create file");
		return 1;
	}
	if(argc != 3) {
		perror("usage: <a.out> <input file> <output file>");
		return 1;
	}
	while(!feof(inputfp)) {
		fread(&ch, sizeof(char), 1, inputfp);
		fwrite(&ch, sizeof(char), 1, outputfp);
		fread(&charcount, sizeof(long int), 1, inputfp);
		charcount--;
		while(charcount > 0) {
			printf("1\n");
			fwrite(&ch, sizeof(char), 1, outputfp);
			charcount--;
		}
	}
	fclose(inputfp);
	fclose(outputfp);
	return 0;
}