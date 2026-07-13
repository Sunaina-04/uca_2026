#include <stdio.h>
#include <stdlib.h> // exit(), etc
#include <fcntl.h> // open() --> O_WRONLY etc
#include <unistd.h> // for open(), close(), write() etc 
	
#define BUF_SIZE 1024
// to make a copy function copy <file1> <file2>
int main (int argc, char* argv[]){

	// inputFd (file descriptor) and outputFd is used to store the integer identifier of the input and output fiels respectively. 
	// openFlags is used to specify how the OS should open/ create file
	int inputFd, outputFd, openFlags;
	// mode_t and ssize are data types 
	// fileParams specifies file permissions 
	mode_t fileParams;
	// numRead is used to store the number of bytes read during the current loop cycle 
	ssize_t numRead;
	// character buffer to store buffer size of characters to put in copy file. we use buffer to send small or set size of data only by one to copy file, ie bucket analogy to send fixed chunks of data.
	char buf[BUF_SIZE];

	// check if the arguments provided are complete 
	if (argc < 3 ){
		printf("Usage ./copy <file1> <file2>");
		exit(-1);
	}

	// specifying to open the first argument file in read only mode. 
	inputFd = open(argv[1], O_RDONLY);
	// if file not found print error and exit with code -1;
	if (inputFd == -1){
		printf("Error opening the file %s\n", argv[1]);
		exit(-1);
	}
	

	// openFlags | is used to combine flags into single integer 
	// create | write | truncate the previous information for the file2 
	openFlags = O_CREAT | O_WRONLY | O_TRUNC;

	// setting file permissions to 
	// read and write perm to user, read only perm to grp adn others 
	fileParams = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH ;

	// now open file for writing
	outputFd = open(argv[2], openFlags, fileParams);	
	
	if (outputFd == -1){
                printf("Error opening the file %s\n", argv[2]);
                exit(-1);
        }

	//reading code chunk by chunk
	//read cmd takes 3 args --> <fileName> , <buf where you store read content, maximum number of bytes that you want to keep from 0-1024 
	//returns greater than 0 is the number of bytes that we have read, which is stored in numRead  
	while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0 ){
		//write in outputFd from buf, numRead amt of lines 
		//write returns number of bytes written 
		//so if write != numRead ofc error
		if (write(outputFd, buf, numRead) != numRead){
			printf("Error while copying \n");
			exit(-1);
		}
	}

	// close the file descriptors 
	close (inputFd);
	close (outputFd);
	return 0;
}
