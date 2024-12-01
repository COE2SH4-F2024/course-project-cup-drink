#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(objPos(1,1,'*'));
    playerPosList->insertHead(objPos(1,1,'*'));
    playerPosList->insertHead(objPos(1,1,'*'));

    


    // more actions to be included
}


Player::~Player()
{
    playerPosList->~objPosArrayList();
    delete[] playerPosList;
    // delete any heap members here
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList; // Need to implement objpos for the player. 
}

void Player::updatePlayerDir()
{
    if(mainGameMechsRef->getInput() != 0)  // if not null character
    {
        switch(mainGameMechsRef->getInput())
        {                      
            case ' ':  // exit
                mainGameMechsRef->setExitTrue();
                break;

            // Add more key processing here
            // Add more key processing here
            // Add more key processing here    
            
            case 'w':  // exit
                if (myDir!=UP&&myDir!=DOWN)
                {
                    myDir=UP;
                }

               break;
            case 'a':  // exit
                if (myDir!=LEFT&&myDir!=RIGHT)
                    {
                    myDir=LEFT;
                    }
                break;
            case 's':  // exit
                if (myDir!=UP&&myDir!=DOWN)
                    {
                    myDir=DOWN;
                    }
                break;
            case 'd':  // exit
                if (myDir!=LEFT&&myDir!=RIGHT)
                    {
                    myDir=RIGHT;
                    }
                break;
            default:
                break;
        }
        mainGameMechsRef->clearInput();
    }
        // PPA3 input processing logic          
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    if(myDir == UP)
    {
        objPos temp = playerPosList->getHeadElement();
        temp.pos->y--;
        if (temp.pos->y==0)
        {
            temp.pos->y=mainGameMechsRef->getBoardSizeY()-2;
        }
        playerPosList->insertHead(objPos(temp));
    }
    else if(myDir == LEFT)
    {
        objPos temp = playerPosList->getHeadElement();
        temp.pos->x--;
        if (temp.pos->x==0)
        {
            temp.pos->x=mainGameMechsRef->getBoardSizeX()-2;
        }
        playerPosList->insertHead(objPos(temp));
    }
    else if(myDir == RIGHT)
    {
        objPos temp = playerPosList->getHeadElement();
        temp.pos->x++;
        if (temp.pos->x==mainGameMechsRef->getBoardSizeX()-1)
        {
            temp.pos->x=1;
        }
        playerPosList->insertHead(objPos(temp));
    }
    else if(myDir == DOWN)
    {
        objPos temp = playerPosList->getHeadElement();
        temp.pos->y++;
        if (temp.pos->y==mainGameMechsRef->getBoardSizeY()-1)
        {
            temp.pos->y=1;
        }
        playerPosList->insertHead(objPos(temp));
    }
    if (playerPosList->getHeadElement().pos->x == mainGameMechsRef->getBoardSizeX()-1)
    {
        playerPosList->getHeadElement().pos->x = 1;
    }
    else if (playerPosList->getHeadElement().pos->y == mainGameMechsRef->getBoardSizeY()-1)
    {
        playerPosList->getHeadElement().pos->y = 1;
    }
    else if (playerPosList->getHeadElement().pos->x == 0)
    {
        playerPosList->getHeadElement().pos->x = (mainGameMechsRef->getBoardSizeX()-2);
    }
    else if (playerPosList->getHeadElement().pos->y == 0)
    {
        playerPosList->getHeadElement().pos->y =  (mainGameMechsRef->getBoardSizeY()-2);
    }
    if (myDir!=STOP)
    {
        playerPosList->removeTail();
    }
    
}
int Player::getdir()
{
    return int(myDir);
}
// More methods to be added