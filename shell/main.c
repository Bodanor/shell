//
//  main.c
//  shell
//
//  Created by Christos Papadopoulos on 30/04/2023.
//

#include <stdio.h>
#include "Input.h"

int main(int argc, const char * argv[]) {
    char *input = getUserInput();
    stripInput(input);
    printf("%s", input);
}
