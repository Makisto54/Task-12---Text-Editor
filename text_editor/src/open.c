#include "../headers/text_editor.h"

void file_open(char *filename)
{
    int pos = 0;
    int bytes = 0;
    int handle = 0;
    char symbol = 0;

    move(0, 0);
    handle = open(filename, O_RDONLY);
    if (handle == -1)
    {
        perror("OPEN FILE ERROR!");
        sleep(1);
        endwin();
        close(handle);
        exit(1);
    }
 
    pos = lseek(handle, 0, SEEK_END);
    if (pos == -1)
    {
        perror("LSEEK ERROR!");
        sleep(1);
        endwin();
        close(handle);
        exit(1);
    } 

    if (lseek(handle, 0, SEEK_SET) == -1)
    {
        perror("LSEEK BACK ERROR!");
        sleep(1);
        endwin();
        close(handle);
        exit(1);        
    }

    do
    {
        bytes = read(handle, &symbol, sizeof(char));
        if(bytes == -1)
        {
            perror("READ FILE ERROR!");
            sleep(1);
            endwin();
            close(handle);
            exit(1);
        } 
        addch(symbol);
        pos--;
    } while (pos != 0);

    close(handle);
}
