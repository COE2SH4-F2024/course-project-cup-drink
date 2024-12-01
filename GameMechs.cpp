#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    if (boardX < 0 || boardY < 0)
    {
        return;
    }
    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs() //for now no destructor needed.
{
    
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = 1;
}

void GameMechs::setLoseFlag()
{
    loseFlag = 1;
}

void GameMechs::setInput(char this_input)
{
    input = this_input; 
}

void GameMechs::clearInput()
{
    input = 0; //I assume assigning the null character would mean no input.
}
Food::Food()
{
    foodPos.pos->x=0;
    foodPos.pos->y=0;
    foodPos.symbol='X';
}
Food::~Food()
{
    foodPos.~objPos();
}
void Food::generateFood(objPos blockOff)
{
    do{
        foodPos.setObjPos(1+rand()%28,1+rand()%13,foodPos.symbol);
    }
    while(foodPos.isPosEqual(&blockOff));
}
objPos const Food::getFoodPos()
{
    objPos returnPos;
    returnPos.pos->x = foodPos.pos->x;
    returnPos.pos->y = foodPos.pos->y;
    returnPos.symbol = foodPos.symbol;
    
    return returnPos;
}
// More methods should be added here