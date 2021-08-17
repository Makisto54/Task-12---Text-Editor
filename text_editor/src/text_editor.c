#include "../headers/text_editor.h"

int main(int argc, char **argv)
{
    int x1 = 0;
    int y1 = 0;
    int ch = 0;
    int handle = 0;
    MEVENT event = {0};
    char name[255] = {0};

    initscr();
    curs_set(1);
    keypad(stdscr, TRUE);
    mousemask(BUTTON1_CLICKED, NULL);

    printw("F1 - OPEN FILE\n");
    printw("F3 - EXIT\n");
    while(ch != KEY_F(3))
    {
        ch = wgetch(stdscr);
        getyx(stdscr, x1, y1);
        switch(ch)
        {
            case KEY_UP:
                move(x1 - 1, y1);
                break;
            case KEY_DOWN:
                move(x1 + 1, y1);
                break;
            case KEY_LEFT:
                move(x1, y1 - 1);
                break;
            case KEY_RIGHT:
                move(x1, y1 + 1);
                break;
            case KEY_F(1):
                printw("Input path to filename from this directory\n");
                wgetnstr(stdscr, name, 15);
                printw("OPENING FILE:\n");
                printw("F2 - SAVE FILE\n");
                refresh();
                sleep(2);
                clear();
                file_open(name);
                break; 
            case KEY_F(2):
                file_save(name);
                printw("F1 - OPEN FILE\n");
                printw("F3 - EXIT\n");
                break; 
            case KEY_BACKSPACE:
                getyx(stdscr, x1, y1);
                mvwaddch(stdscr, x1, y1, ' ');
                refresh();
                move(x1, y1);
                break; 
            case KEY_MOUSE:
                getmouse(&event);
                move(event.y, event.x);  
                break;       
        }
        refresh();
    }
    endwin();
    
    return 0;
}
