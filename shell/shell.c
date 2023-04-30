//
//  shell.c
//  shell
//
//  Created by Christos Papadopoulos on 30/04/2023.
//

#include "shell.h"

struct shell_t {
    struct termios oldterm;
    struct termios newterm;
};

void switchToCanonical(Shell * shell_str)
{
    tcgetattr(STDIN_FILENO, &shell_str->oldterm);
    shell_str->newterm = shell_str->oldterm;
    cfmakeraw(&shell_str->newterm);
    tcsetattr(STDIN_FILENO, TCSANOW, &shell_str->newterm);
    setvbuf(stdout, NULL, _IONBF, 0);
    
}

void switchToNonCanonical(Shell *shell_str)
{
    tcsetattr(STDIN_FILENO, TCSANOW, &shell_str->oldterm);
}

int init_shell(Shell **shell_str)
{
    *shell_str = (Shell*)malloc(sizeof(Shell));
    if (*shell_str == NULL)
        return -1;
    return 0;
    
}
