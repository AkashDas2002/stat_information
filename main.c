#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(){
	struct stat buf;
	stat("main.c", &buf);
	int size = buf.st_size;
	printf("%d\n", size);
	int mode = buf.st_mode;
	printf("%d\n", mode);
	return 0;
}
