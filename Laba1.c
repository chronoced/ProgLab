#include <stdio.h>

int main(int argc, char *argv[]){

struct stc  {
int n;
char s[255];
float f; } str;

char fn [50];
FILE *file;
file = fopen(argv[1], "rb");

while (file == NULL){

	printf(" Error opening file\n Enter a new filename or file path (Example: file.dat or C:\\\\Users\\\\Desktop\\\\file.dat):");
	scanf("%s", fn);
	file = fopen(fn, "rb");
}

int size = 0;
while ( fread(&str, sizeof(struct stc), 1, file) ){

	printf("%d\t %s\t %f\t\n",str.n, str.s, str.f);
	size = size+sizeof(struct stc);
}

fclose(file);

printf("File size: %d bytes", size);

return 0;
}
