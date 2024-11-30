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
    if(MacUILib_hasChar)
    {
        input = MacUILib_getChar(); //do we need to use this_input? , why can't we just do something like this??
    }
    
}

void GameMechs::clearInput()
{
    input = 0; //I assume assigning the null character would mean no input.
}

// More methods should be added here