#include <stdio.h>

int main (int argc, char* argv){
	if (argc < 2) {
		printf("Usage format: '.removeComments filepath.c' ");
		exit(-1);
	}

	char* filepath;
	int openFile;
	int fd;

        filepath = argv[1];
	openFile = O_RDONLY;
	fd = open(filepath, openFile);

	if (fd == -1) {
		printf("Error reading the file");
		exit(-1);	
	}

	remove_comments(fd);
	
	close (fd);
        return 0;
}
