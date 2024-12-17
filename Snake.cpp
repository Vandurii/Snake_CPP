#include <iostream>
#include <Windows.h>
#include <thread>
#include <list>
using namespace std;

int nScreenWidth = 120;
int nScreenHeight = 80;

struct sSnakeSegment
{
    int x;
    int y;
};

void clearScreen(int len, char* screen);
void draw_border_and_stats(int* len);
void draw_snake(list<sSnakeSegment>, char* screen);

int main(){
    //Create Screen Buffer
    int len = nScreenWidth * nScreenHeight;
    char *screen = new char[len];
    screen[len -1] = '\0';

    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    list<sSnakeSegment> snake = {{60, 15}, {61, 15}, {62, 15}, {63, 15}, {64, 15}, {65, 15}, {66, 15}, {67, 15}, {68, 15}, {69, 15}};
    int nFoodX = 30;
    int nFoodY = 15;
    int nScore = 0;
    int nSnakeDirection = 3;
    bool bDead = false;

    // game loop
    int i = 0;
    while(1){   
        // Timing  & input
        this_thread::sleep_for(20ms);

        // Game Logic

        // Display
        clearScreen(len, screen);
        // Draw Stats & Border
        draw_snake(snake, screen);
        i++;
        if(i > nScreenWidth * nScreenHeight) i = 0;
        screen[i] = '@';


        WriteConsoleOutputCharacter(hConsole, screen, len, {0, 0}, &dwBytesWritten); 
    }

    return 0;
}

void clearScreen(int len, char* screen)
{
    for(int i = 0; i < len; i++) screen[i]= ' ';
};

void draw_border_and_stats(){

};

void draw_snake(list<sSnakeSegment> snake, char* screen){

    for(auto a: snake){
        screen[(a.y * nScreenWidth) + a.x] = '0';
    }

}



