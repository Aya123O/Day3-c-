/*#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <termios.h>
#endif

#define UP 65
#define DOWN 66

// ANSI color codes
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"
#define BLUE_COLOR "\033[34m"

// Function to move the cursor to a specific position
void gotoxy(int x, int y) {
#ifdef _WIN32
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    printf("\033[%d;%dH", y, x);
#endif
}

// Function to get a single character without echoing it to the console
int getch(void) {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

// Function to display the menu
void DisplayMenu(int currentPostion, int row, int col) {
    printf("\033[H\033[J"); // Clear screen

    // For "New" option (row 5)
    gotoxy(col / 2 -10 , 5); // Move to the correct column for the box
    printf("*----------------------*");
    gotoxy(col / 2 - 10 , 6);
    if (currentPostion == 0) {
        printf("* %s->New%s          *", GREEN_COLOR, RESET_COLOR);
    } else {
        printf("* %sNew%s            *", BLUE_COLOR, RESET_COLOR);
    }
    gotoxy(col / 2 - 10 , 7);
    printf("*----------------------*");

    // For "Modify" option (row 10)
    gotoxy(col / 2 - 10 , 10); // Move to the correct column for the box
    printf("*----------------------*");
    gotoxy(col / 2 - 10 , 11);
    if (currentPostion == 1) {
        printf("* %s->Modify%s        *", GREEN_COLOR, RESET_COLOR);
    } else {
        printf("* %sModify%s          *", BLUE_COLOR, RESET_COLOR);
    }
    gotoxy(col / 2 - 10 , 12);
    printf("*----------------------*");

    // For "Exit" option (row 15)
    gotoxy(col / 2 - 10 , 15); // Move to the correct column for the box
    printf("*----------------------*");
    gotoxy(col / 2 - 10 , 16);
    if (currentPostion == 2) {
        printf("* %s->Exit%s          *", GREEN_COLOR, RESET_COLOR);
    } else {
        printf("* %sExit%s            *", BLUE_COLOR, RESET_COLOR);
    }
    gotoxy(col / 2 - 10 , 17);
    printf("*----------------------*");
}

int main (void) {
    int row = 80, col = 100, currentPostion = 0, ch;

    DisplayMenu(currentPostion, row, col);

    while(1) {
        ch = getch();
        if (ch == 27) {
            ch = getch();
            if (ch == 91) {
                ch = getch();
                if (ch == UP) {
                    currentPostion = (currentPostion - 1 + 3) % 3;
                } else if (ch == DOWN) {
                    currentPostion = (currentPostion + 1) % 3;
                }
            }
        }


        if (currentPostion == 2 && ch == 10) {
            break;
        }

        DisplayMenu(currentPostion, row, col);
    }

    return 0;
}
*/
