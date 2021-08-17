#ifndef _TEXT_EDITOR_
#define _TEXT_EDITOR_

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <sys/types.h>

void file_open(char *);
void file_save(char *);

#endif
