//
//  Input.c
//  shell
//
//  Created by Christos Papadopoulos on 30/04/2023.
//

#include "Input.h"

char *getUserInput(void)
{
    char *input = NULL;
    char *ptr_input = NULL;
    char c;
    int step = 0;
    
    /* While the user hasn't pressed enter or sent an EOF, we read */
    while ((c = getchar()) != EOF && c != '\n') {
        /* If the input is bigger the buffer size, we reallocate memory.
         * In the First loop we enter here to allocate memory
         */
        
        if ((ptr_input - input) % INPUT_BUFFER_SIZE == 0) {
            input = (char*)realloc(input, sizeof(char)*INPUT_BUFFER_SIZE * (step + 1));
            if (input == NULL)
                return NULL;
            ptr_input = input + (INPUT_BUFFER_SIZE * step);
            step++;
        }
        *ptr_input++ = c; /* Fill in the buffer */
    };
    
    /* If the user didn't press ENTER without any input, then we actually check if
     * there is anough room for the END Char \0 in the buffer else, we relloc
     */
    
    if (ptr_input != NULL) {
        if ((ptr_input - input) % INPUT_BUFFER_SIZE == 0) {
            input = (char*)realloc(input, sizeof(char)*INPUT_BUFFER_SIZE * (step + 1));
            if (input == NULL)
                return NULL;
            ptr_input = input + (INPUT_BUFFER_SIZE * step);
            
        }
        *ptr_input = '\0'; /* Put the terminator character */
        
        /* Shrink down the uncessary unused memory from the previous realloc
         * Every byte is important :)) !!
         */
        input = (char*)realloc(input, strlen(input) + 1);
        if (input == NULL)
            return NULL;
    }
    
    return input;
}

void stripInput(char *input)
{
    char *tmp = input;
    
    if (tmp != NULL) {
        do {
            while (*tmp == '\t')
                tmp++;
        } while ((*input++ = *tmp++));
    }
    
}
