//
//  main.c
//  shell
//
//  Created by Christos Papadopoulos on 30/04/2023.
//

#include <stdio.h>
#include "Input.h"
#include "shell.h"

int main(int argc, const char * argv[]) {
    
    Shell *shell_structure;
    char *input;
    
    if (init_shell(&shell_structure) != 0) {
        printf("Could not initialize the shell !\n");
        return -1;
    }
    
    switchToCanonical(shell_structure);
    while (1) {
        if((input = getUserInput()) == NULL) {
            switchToNonCanonical(shell_structure);
            return 0;
        }
    }
}
