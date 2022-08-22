#include <stdio.h>
#include <syslog.h>
int main(int argc, char **argv){
	if(argc != 3){
		syslog(LOG_ERR, "Invalid number of arguments");
		return 1;
	}
	FILE *ptr = fopen(argv[1], "w");
	if(ptr == NULL){
		syslog(LOG_ERR, "File can not be opened");
		return 1;
	}
	fprintf(ptr, "%s", argv[2]);
	syslog(LOG_DEBUG, "Written string %s to file %s", argv[2], argv[1]);
	fclose(ptr);
	return 0;
}
