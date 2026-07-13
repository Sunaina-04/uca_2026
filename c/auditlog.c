#include <stdio.h>
// for open() constants like O_RONLY, O_WONLY, O_APPEND, O_RDWR, O_CREATE
#include <fcntl.h> 
// for exit function 
#include <stdlib.h> 
// for system calls like read(), write(), close()
#include <unistd.h>

#include <string.h> 

// used to maintain the code for a production pov

#define LOG_FILE "audit.log"
#define BUF_SIZE 1024


void readFile(){
	// display log file's content with line number
	int inputFd ;
        ssize_t numRead;
	char buf[BUF_SIZE];


	inputFd = open(LOG_FILE, O_RDONLY);
        if (inputFd == -1){
       		printf("Error reading file" );
		exit(-1);
       	}	

	// start reading 
	while ((numRead = read(inputFd , buf , BUF_SIZE-1)) > 0){
		buf[numRead] = '\0';
		printf("%s" , buf);	
	}

	close(inputFd);
	return;
}

void writeFile(char * content){
	// appending text to log file 
		
	int openFlags, filePerms, writeFd;
	char ch;
       	
	openFlags = O_CREAT | O_RDWR | O_APPEND; 
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	writeFd = open(LOG_FILE, openFlags, filePerms);

	if (writeFd == -1){
		printf("Error finding or opening the file");
		exit(-1);
	}

	// 10 is the margin for extra symbols etc
	int newSize = strlen(content) + 10; 

	// create new buffer array to store added content 
	char buffer[newSize];
	
	// count line number 
	int line_no = 1;
	while ((read (writeFd, &ch , 1)) > 0){
		if (ch == '\n'){
			line_no++;
		}
	}

	// snprintf used to format and store series of characters and numbers into string buffer 
	snprintf(buffer, sizeof(buffer), "%d.%s\n", line_no, content);
	if (write(writeFd, buffer, strlen(buffer)) == -1 ){
		printf("Error writing to the file");
		exit (-1);
	}
	return;
}

int main(int argc, char *argv[]){
	if (argc < 2){
	// ie nothing is provided after add 
	 printf( "Usage: ./auditlog --add \"message\" or ./auditlog --view\n");
	}

	if (strcmp(argv[1],"--view") == 0){
		readFile();
	}else if(argc > 3) {
		writeFile(argv[2]);
	}else{
		printf("Wrong");
	}
	return 0;
}
