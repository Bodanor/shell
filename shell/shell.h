//
//  shell.h
//  shell
//
//  Created by Christos Papadopoulos on 30/04/2023.
//

#ifndef shell_h
#define shell_h

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

typedef struct shell_t Shell;

int init_shell(Shell **);
void switchToCanonical(Shell *);
void switchToNonCanonical(Shell *);
#endif /* shell_h */
