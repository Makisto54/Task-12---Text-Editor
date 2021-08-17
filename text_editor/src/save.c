#include "../headers/text_editor.h"

void file_save(char *filename)
{
    int y = 0;
    int handle = 0;
    char symbol = 0;
    int counter = 0;
    char buf_symbol = '\n';

    handle = open(filename, O_WRONLY);
    if (handle == -1)
    {
        perror("OPEN FILE ERROR!");
        sleep(1);
        endwin();
        exit(1);
    }

    for (int i = 0; i < LINES; i++) 
    {
        y = 0;
        counter = 0;

        do
        {
            move(i, y);
            symbol = (winch(stdscr) & A_CHARTEXT);
            if (-1 == write(handle, &symbol, sizeof(char)))
            {
                perror("WRITE FILE ERROR!");
                sleep(1);
                endwin();
                close(handle);
                exit(1); 
            }
            y++;
            counter++;
        } while (counter != 60);

        if (-1 == write(handle, &buf_symbol, sizeof(char)))
        {
            perror("WRITE FILE ERROR!");
            endwin();
            close(handle);
            exit(1); 
         }
    }
    clear();
    move(0, 0);

    close(handle);
}
