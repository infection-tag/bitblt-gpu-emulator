#include <stdio.h>

/* Struct for the input stream */
typedef struct InputStream {
  FILE* stream; /* Pointer to the underlying input stream (e.g., stdin) */
} InputStream;

/* Function to create a new InputStream object associated with stdin */
InputStream* InputStream_create() {
  InputStream* in = malloc(sizeof(InputStream)); /* Allocate memory */
  if (in == NULL) {
    return NULL; /* Handle allocation failure */
  }
  in->stream = stdin;
  return in;
}

/* Function to create a new InputStream object associated with a FILE pointer */
InputStream* InputStream_create_from_file(const char* filename) {
  FILE* stream = fopen(filename, "r"); /* Open file for reading */
  if (stream == NULL) {
    return NULL; /* Handle file open failure */
  }
  InputStream* in = malloc(sizeof(InputStream));
  if (in == NULL) {
    fclose(stream); /* Close file on allocation failure */
    return NULL;
  }
  in->stream = stream;
  return in;
}

/* Function to read a line of text from the input stream */
char* InputStream_readline(InputStream* in) {
  if (in == NULL) {
    return NULL; /* Handle invalid argument */
  }
  /* Define maximum line length */
  #define MAX_LINE_LENGTH 256
  char buffer[MAX_LINE_LENGTH];
  fgets(buffer, MAX_LINE_LENGTH, in->stream);

  /* Remove trailing newline if present */
  char* newline = strchr(buffer, '\n');
  if (newline) {
    *newline = '\0';
  }

  /* Allocate memory and copy the string (avoid memory leak from fgets) */
  char* line = malloc(strlen(buffer) + 1);
  if (line == NULL) {
    return NULL; /* Handle allocation failure */
  }
  strcpy(line, buffer);
  return line;
}

/* Function to destroy the InputStream object and free memory */
void InputStream_destroy(InputStream* in) {
  if (in == NULL) {
    return;
  }
  if (in->stream != stdin) { /* Close file stream if not stdin */
    fclose(in->stream);
  }
  free(in);
}

int main() {
  /* Create an InputStream object associated with stdin */
  InputStream* myIn = InputStream_create();

  printf("Enter your name: ");
  char* name = InputStream_readline(myIn);
  if (name != NULL) {
    printf("Hello, %s!\n", name);
    free(name); /* Free memory allocated by InputStream_readline */
  } else {
    printf("Error reading input.\n");
  }

  /* Example: Create an InputStream object from a file */
  InputStream* fileIn = InputStream_create_from_file("data.txt");
  if (fileIn != NULL) {
    /* Read lines from the file... */
    InputStream_destroy(fileIn);
  } else {
    printf("Error opening file.\n");
  }

  InputStream_destroy(myIn);

  return 0;
}
