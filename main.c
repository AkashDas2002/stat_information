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
	mode_t mode = buf.st_mode;
	printf("File Permissions: %o\n", mode);
	printf("Time last accessed: %s\n", ctime(&buf.st_atime));
	char arr[][3] = {"---","--x","-w-","-wx","r--","r-x","rw-","rwx"};
	printf("File Permissions: -%c%c%c", arr[mode % 8][0], arr[mode % 8][1], arr[mode % 8][2]);
	mode = mode / 8;
	printf("%c%c%c", arr[mode % 8][0], arr[mode % 8][1], arr[mode % 8][2]);
	mode = mode / 8;
	printf("%c%c%c\n", arr[mode % 8][0], arr[mode % 8][1], arr[mode % 8][2]);
	return 0;
}
