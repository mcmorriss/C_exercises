#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  // O_WRONLY - open the file only for writing
  // O_CREAT - create the file, if doesn't exit.
  // O_TRUNC means truncate the file if it already exists
  char file[] = "grades.txt";
  int file_descriptor = open(file, O_WRONLY | O_CREAT|O_TRUNC, 00600);
  if (file_descriptor < 0){
		fprintf(stderr, "Could not open %s\n", file);
		exit(1);
	}
	close(file_descriptor);
  return 0;
}
