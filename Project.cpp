#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000
GameMechs mech;
bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;
    
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    for(int i =0; i< mech.getBoardSizeX();i++)
    {
        for(int j = 0; j< mech.getBoardSizeY() ; j++)
        {
            if(i == 0 || j == 0 || i == (mech.getBoardSizeX()-1)|| j == (mech.getBoardSizeY()-1))
            {
                MacUILib_printf("#");
            }

        }
        MacUILib_printf("\n");
    }    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
