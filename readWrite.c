#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main(void){
	int file_descriptor;
	char* newFilePath = "./newFile.txt";
	char* giveEm = "THE BUSINESS\n";
	
	ssize_t nread, nwritten;
	char readBuffer[32];
	
  // Open the file using the open system call
  // The flag O_RDWR means the file should be opened for reading and writing
  // The flag O_CREAT means that if the file doesn't exist, open should create it
  // The flag O_TRUNC means that if the file already exits, open should truncate it.
	file_descriptor = open(newFilePath, O_RDWR | O_CREAT | O_TRUNC, 00600);
	if (file_descriptor == -1){
		printf("open() failed on \"%s\"\n", newFilePath);
		perror("In main()");
		exit(1);
	}
	
  // Write to the file using the write system call
	nwritten = write(file_descriptor, giveEm, strlen(giveEm) * sizeof(char));
  // Clear out the array before using it
	memset(readBuffer, '\0', sizeof(readBuffer)); 
  // Reset the file pointer to the beginning of the file
	lseek(file_descriptor, 0, SEEK_SET); 
  // Read from the file using the read system call
	nread = read(file_descriptor, readBuffer, sizeof(readBuffer));
	printf("nread = %zd, nwritten = %zd\n", nread, nwritten);
	
	printf("File contents:\n%s", readBuffer);
	
	return 0;
}
