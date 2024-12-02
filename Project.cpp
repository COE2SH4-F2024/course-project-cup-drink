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
Food* foods;
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

    foods = new Food(mech);
    snake = new Player(mech,foods); 
    foods->generateFood(snake->getPlayerPos());
    
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
    std::cout<<"SNAKE GAME!!!"<<endl<<"The numbers are fruits, their numerical value determines the score and length you get"<<endl<<"You can wrap around the boarder! Have fun!"<<endl;
    
    for(int i =0; i<foods->getFoodPos()->getSize();i++)
    {
       //std::cout<<"index: "<<i<<" x: "<<foods->getFoodPos()->getElement(i).pos->x<<" y: "<<foods->getFoodPos()->getElement(i).pos->y<<"\n";
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
    for(int i =0; i<snake->getPlayerPos()->getSize();i++)
    {
        board[snake->getPlayerPos()->getElement(i).pos->y][snake->getPlayerPos()->getElement(i).pos->x]=snake->getPlayerPos()->getElement(i).symbol;
    }
    for(int i =0; i<foods->getFoodPos()->getSize();i++)
    {
        board[foods->getFoodPos()->getElement(i).pos->y][foods->getFoodPos()->getElement(i).pos->x]=foods->getFoodPos()->getElement(i).symbol;
    }

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
    cout<<"\nGame Over!"; 
    if (mech->getLoseFlagStatus())
    {
        cout<<"\nYou Lost! You collided with yourself!"; 
    }
    MacUILib_uninit();
    delete mech;
    snake->~Player();
    delete snake;
    foods->~Food();
    delete foods;
}
