#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>


int main(){
	struct stat buf;
	stat("makefile", &buf);
	long int size = buf.st_size;
	printf("File size: %ld GB, ", size / 1000000000);
	size = size % 1000000000;
	printf("%ld MB, ", size / 1000000);
	size = size % 1000000;
	printf("%ld KB, ", size / 1000);
	size = size % 1000;
	printf("%ld B\n", size);
	int mode = buf.st_mode;
	printf("File mode: %d\n", mode);
	printf("Time accessed: %s\n", ctime(&buf.st_atime));
	return 0;
}
