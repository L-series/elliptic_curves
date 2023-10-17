#include <stdio.h>
#include <string.h>
#include "pari/pari.h"

#define LINE_SIZE 1024

int main(int argc, char *argv[]) {
// Open the file for reading
	FILE *fp = fopen("testfile.txt", "r");
	if (fp == NULL) {
		printf("Error opening file\n");
	return 1;
	}

	// Initialize the PARI/GP library
	pari_init(100000000, 2);
	
	// Use PARI/GP functions in your code here...
	
// Read the file line by line
	char line[LINE_SIZE];
	while (fgets(line, LINE_SIZE, fp) != NULL) {
// Find the start and end indices of the inner square brackets
		int start = -1, end = -1;
		for (int i = 1; i < strlen(line); i++) {
			if (line[i] == '[') {
				start = i;
		}
			else if (line[i] == ']') {
				end = i;
			break;
			}
		}

// Print the contents of the inner square brackets
		if (start != -1 && end != -1) {
			for (int i = start + 1; i < end; i++) {
   				printf("%c", line[i]);
		 	 }	
  				printf("\n");
		}

	}

// Close the file
fclose(fp);

// Clean up the PARI/GP library
pari_close();


return 0;
}
