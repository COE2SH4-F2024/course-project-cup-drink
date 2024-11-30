#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h" //added by Kerolos
#include "Player.h" //added by Kerolos

using namespace std;

#define DELAY_CONST 100000
GameMechs* mech;
Player* snake;

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
    mech = new GameMechs();

    exitFlag = false;
    snake = new Player(mech); 
    
}

void GetInput(void)
{
    if(MacUILib_hasChar)
        mech->setInput(MacUILib_getChar());
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    printf("%d %d",snake->getPlayerPos().pos->x,snake->getPlayerPos().pos->y );
    MacUILib_clearScreen();
    for(int i =0; i< mech->getBoardSizeY();i++)
    {
        for(int j = 0; j< mech->getBoardSizeX() ; j++)
        {
            if(i == 0 || j == 0 || i == (mech->getBoardSizeY()-1)|| j == (mech->getBoardSizeX()-1))
            {
                MacUILib_printf("#");
            }
            else if(i == snake->getPlayerPos().pos->x && j == snake->getPlayerPos().pos->y)
            {
                MacUILib_printf("%c",snake->getPlayerPos().symbol);
            }
            else
            {
                MacUILib_printf(" ");
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
    delete mech;
    delete snake;
}
