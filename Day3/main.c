#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // Open file
    FILE *file;
    file = fopen("input.txt", "rb");
    
    // Confirm that the file was open
    if (file != NULL) { 

    }
    else  { printf("The file could not be open!"); }
    return 0;
}