#include <stdio.h>

/* Struct for the output stream */
typedef struct OutStream {
  FILE* stream; // Pointer to the underlying output stream (e.g., stdout)
} OutStream;

/* Function to create a new OutStream object associated with a FILE pointer */
OutStream* OutStream_create(FILE* stream) {
  OutStream* out = malloc(sizeof(OutStream)); // Allocate memory
  if (out == NULL) {
    return NULL; // Handle allocation failure
  }
  out->stream = stream;
  return out;
}

/* Function to write a string with a newline character */
void OutStream_writeln(OutStream* out, const char* str) {
  if (out == NULL || str == NULL) {
    return; // Handle invalid arguments
  }
  fprintf(out->stream, "%s\n", str);
}

/* Function to write a string without a newline character */
void OutStream_write(OutStream* out, const char* str) {
  if (out == NULL || str == NULL) {
    return; // Handle invalid arguments
  }
  fprintf(out->stream, "%s", str);
}

/* Function to destroy the OutStream object and free memory */
void OutStream_destroy(OutStream* out) {
  if (out == NULL) {
    return;
  }
  free(out);
}

int main() {
  /* Create an OutStream object associated with stdout */
  OutStream* myOut = OutStream_create(stdout);

  OutStream_writeln(myOut, "Hello, world!");
  OutStream_write(myOut, " This is another message. ");
  OutStream_writeln(myOut, "Goodbye!");

  /* Destroy the OutStream object */
  OutStream_destroy(myOut);

  return 0;
}
