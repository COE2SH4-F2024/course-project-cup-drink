#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h" //added by Kerolos
#include "Player.h" //added by Kerolos
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000
GameMechs* mech;
Player* snake;
Food* apple;
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
    while(mech->getExitFlagStatus() == false)  
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

    apple = new Food();
    snake = new Player(mech,apple); 
    apple->generateFood(snake->getPlayerPos());
    
}

void GetInput(void)
{
    
    if(MacUILib_hasChar())
    {
        mech->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    snake->updatePlayerDir();
    snake->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    for(int i =0; i<snake->getPlayerPos()->getSize();i++)
    {
       std::cout<<"index: "<<i<<" x: "<<snake->getPlayerPos()->getElement(i).pos->x<<" y: "<<snake->getPlayerPos()->getElement(i).pos->y<<"\n";
    }
    char board[mech->getBoardSizeY()][mech->getBoardSizeX()];
    for(int i =0; i< mech->getBoardSizeY();i++)
    {
        for(int j = 0; j< mech->getBoardSizeX() ; j++)
        {
            if(i == 0 || j == 0 || i == (mech->getBoardSizeY()-1)|| j == (mech->getBoardSizeX()-1))
            {
                board[i][j]='#';
            }
            else{
                board[i][j]=' ';
            }
        }
    }
    int size=snake->getPlayerPos()->getSize();
    for(int i =0; i<size;i++)
    {
        board[snake->getPlayerPos()->getElement(i).pos->y][snake->getPlayerPos()->getElement(i).pos->x]=snake->getPlayerPos()->getElement(i).symbol;
    }
    board[apple->getFoodPos().pos->y][apple->getFoodPos().pos->x] = apple->getFoodPos().getSymbol();

    /*printf("%d %d %d\n",snake->getPlayerPos().pos->x,snake->getPlayerPos().pos->y,snake->getdir() );
    for(int i =0; i< mech->getBoardSizeY();i++)
    {
        for(int j = 0; j< mech->getBoardSizeX() ; j++)
        {
            if(i == 0 || j == 0 || i == (mech->getBoardSizeY()-1)|| j == (mech->getBoardSizeX()-1))
            {
                MacUILib_printf("#");
            }
            else if(j == snake->getPlayerPos().pos->x && i == snake->getPlayerPos().pos->y)
            {
                MacUILib_printf("%c",snake->getPlayerPos().symbol);
            }
            else if(j == apple->getFoodPos().pos->x && i == apple->getFoodPos().pos->y)
            {
                MacUILib_printf("%c",apple->getFoodPos().symbol);
            }
            else
            {
                MacUILib_printf(" ");
            }

        }
        MacUILib_printf("\n");
    }*/
   
    
    for(int i =0; i< mech->getBoardSizeY();i++)
    {
        for(int j = 0; j< mech->getBoardSizeX() ; j++)
        {
            cout<<board[i][j];
        }
        cout<<"\n";
    }
    cout<<"Score: "<<mech->getScore();
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    cout<<"\ngame ended"; 
    if (mech->getLoseFlagStatus())
    {
        cout<<"\nYou Lost!"; 
    }
    MacUILib_uninit();
    delete mech;
    snake->~Player();
    delete snake;
    delete apple;
}
