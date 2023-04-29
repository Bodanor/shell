//
//  Input.h
//  shell
//
//  Created by Christos Papadopoulos on 30/04/2023.
//

#ifndef Input_h
#define Input_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_BUFFER_SIZE 3

char *getUserInput(void);
void stripInput(char *input);
#endif /* Input_h */
