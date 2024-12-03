#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
    The levels are either all increasing or all decreasing.
    Any two adjacent levels differ by at least one and at most three.
*/
int *strToArr(char *str, int* len) {
    // Alocate memory for the array
    int *arr = (int*)malloc(strlen(str) * sizeof(int));
    *len = 0;
    
    // Parse a string based on a token
    char* token = strtok(str, " ");
    while (token != NULL){
        arr[*len] = atoi(token); // Convert string of digits into a integer
        (*len)++;
        token = strtok(NULL, " "); // Parse the string for the next number
    }
    return arr;
}

int main()
{
    // Open file
    FILE *file;
    file = fopen("input.txt", "rb");
    
    // Confirm that the file was open
    if (file != NULL) { 
        int y;
        char line[256];
        int increase = 0, decrease = 0, safe = 0;
        while(fgets(line, sizeof(line), file)) {
            
            int len = 0;
            int *arr = strToArr(line, &len);
            for (int i = 0; i < len - 1; i++) {
                //printf("\n%i, %i ", arr[i], arr[i + 1]);
                
                if (arr[i] > arr[i + 1] && (arr[i] - arr[i + 1]) <= 3) {
                    decrease++;
                } else if(arr[i] < arr[i + 1] && (arr[i + 1] - arr[i]) <= 3) { 
                    increase++;
                } else { increase = decrease = 0; break; }

                // Check if lines increase or decrease consistently
                if (increase == len - 1 || decrease == len - 1) { safe++; increase = decrease = 0; break; }
                else if (increase > 0 && decrease > 0) {increase = decrease = 0; break;}
            }
            printf("\ntest:%i, inc:%i, dec:%i, safe:%i", y, increase, decrease, safe);
            y++;
            free (arr); // Free dynamically allocated memory
        }
        fclose(file);
        printf("\nSAFE: %i", safe); // 526
        return 0;
    }
    else  { printf("The file could not be open!"); }
    return 0;
}