#include <stdlib.h> // For memory allocation functions

/**
 * Allocates a block of memory of the specified size.
 *
 * @param size The size of the memory block to allocate in bytes.
 * @return A pointer to the allocated memory block, or NULL if allocation fails.
 */
void* allocate_memory(size_t size) {
  // Allocate memory using malloc
  void* ptr = malloc(size);

  // Handle allocation failure (return NULL)
  if (ptr == NULL) {
    // Optional: Add error logging or exception handling (consider adding a message here)
    //  e.g., fprintf(stderr, "Failed to allocate memory of size %zu\n", size);
    return NULL;
  }

  // Return the allocated memory pointer
  return ptr;
}

/**
 * Frees a previously allocated block of memory.
 *
 * @param ptr The pointer to the memory block to be freed.
 *         This pointer must have been previously returned by a successful call to allocate_memory.
 */
void free_memory(void* ptr) {
  // Free previously allocated memory using free
  if (ptr != NULL) {
    free(ptr);
  }

  // No need to return anything here (void function)
}
