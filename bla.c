#include <stdio.h>
#include <string.h>
#include "pari/pari.h" // Include the PARI/GP header file

#define LINE_SIZE 1024
#define BRACKET_SIZE 128

int main(int argc, char *argv[]) {
// Initialize the PARI/GP library
pari_init(100000000, 2);

// Open the file for reading
FILE *fp = fopen("testfile.txt", "r");
if (fp == NULL) {
printf("Error opening file\n");
return 1;
}

// Read the file line by line
char line[LINE_SIZE];
while (fgets(line, LINE_SIZE, fp) != NULL) {
// Find the start and end indices of the inner square brackets
int start = -1, end = -1;
for (int i = 0; i < strlen(line); i++) {
if (line[i] == '[') {
start = i;
} else if (line[i] == ']') {
end = i;
break;
}
}

// Store the contents of the inner square brackets to a string
if (start != -1 && end != -1) {
  char bracket_str[BRACKET_SIZE];
  int j = 0;
  bracket_str[j++] = '[';
  for (int i = start + 1; i < end; i++) {
    bracket_str[j++] = line[i];
  }
  bracket_str[j++] = ']';
  bracket_str[j] = '\0';

for (int i = 0; i < BRACKET_SIZE; i++) {
printf("%d", bracket_str[i]);
if (i < BRACKET_SIZE - 1) {
printf(", ");
}
}
  // Parse the string as a PARI/GP element
//  GEN coeffs = gp_read_str(bracket_str);

  // Initialize the elliptic curve
//  GEN E = ellinit(coeffs,strtoGENstr("E"));

  // Use the elliptic curve object in your code here...
}

}

// Close the file
fclose(fp);

// Clean up the PARI/GP library
pari_close();

return 0;
}
