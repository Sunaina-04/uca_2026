#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for ctime()
#include <sys/stat.h> // for stat() 

char* getFileType(mode_t mode){
	
	if (S_ISREG(mode)){
		return "Regular File";
	}
	if (S_ISDIR(mode)){
                return "Directory";
        }
	if (S_ISLNK(mode)){
                return "Symbolic Link";
        }
	if (S_ISCHR(mode)){
                return "Character Device";
        }
	if (S_ISBLK(mode)){
                return "Block Device";
        }
	if (S_ISFIFO(mode)){
                return "FIFO (pipe)";
        }
	if (S_ISSOCK(mode)){
                return "Socket";
        }

	return "Unkown";
}
void printFileProperties(struct stat sb, char* filepath){
//	struct stat sb;

                // expected output
                // === File Attributes for: file.txt ===
		//File Type:            Regular File
		//Permissions:          0644
		//File Size:            256 bytes
		//Hard Links Count:     1
		//Owner (UID):          1000
		//Group (GID):          1000
		//Last Access Time:     Tue Jul 21 12:30:15 2026
		//Last Modification:    Tue Jul 21 11:45:02 2026
		//Status Change Time:   Tue Jul 21 11:45:02 2026

                //%-Ns --> right alligning, where N is the number
          printf("=== File Attributes for: %s ===\n", filepath);
	  printf("%-22s %s\n", "File Type: ", getFileType(sb.st_mode));
	  printf("%-22s %d\n","Permissions: ",(sb.st_mode & 0777));
	  printf("%-22s %ld bytes\n","File Size: ",(long)sb.st_size);
	  printf("%-22s %ld\n", "Hard Links Count: ",sb.st_nlink);
	  printf("%-22s %d\n","Owner (UID): ",sb.st_uid);
	  printf("%-22s %d\n","Group (GID): ",sb.st_gid);
	  // \n not needed ctime adds it automatically 
	  printf("%-22s %s","Last Access Time: ",(ctime)(&sb.st_atime));
	  printf("%-22s %s","Last Modification: ",(ctime)(&sb.st_mtime));
	  printf("%-22s %s","Status Change Time: ",(ctime)(&sb.st_ctime));
}


int main(int argc, char* argv[]){
	char* filepath;
	struct stat sb;
	if (argc < 1){
		printf("Please pass filepath \n");
		exit(-1);
	}
	filepath = argv[1];

	if (stat (filepath, &sb) != -1){
		printFileProperties(sb, filepath);
	}else{
		// perror automatically prints your custom string followed by the OS error reason
		perror("Error getting file stats");
  		//EXIT_FAILURE is a standard macro defined in the C library header <stdlib.h>. 
		//It represents a status code (typically 1) that signals to the operating system that a program 
		//terminated abnormally or encountered an error.
		exit(EXIT_FAILURE);
	}
return 0;
}
