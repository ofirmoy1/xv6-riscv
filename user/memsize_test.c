#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int initial_size = memsize();
    printf("Initial memory usage: %d bytes\n", initial_size);
    
    // Allocate 20k bytes using malloc
    char *mem = malloc(1000 * 20); 
    if (mem == 0) {
        printf("malloc failed\n");
        exit(1);
    }
    
    int after_alloc_size = memsize();
    printf("Memory usage after allocation: %d bytes\n", after_alloc_size);
    printf("Difference: %d bytes\n", after_alloc_size - initial_size);
    
    // Free the allocated memory
    free(mem);
    
    int after_free_size = memsize();
    printf("Memory usage after free: %d bytes\n", after_free_size);
    printf("Difference from initial: %d bytes\n", after_free_size - initial_size);
    
    exit(0);
}