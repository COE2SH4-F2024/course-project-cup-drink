#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos.setObjPos(1,1,'*');
    


    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    return playerPos; // Need to implement objpos for the player. 
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
        playerPos.pos->y--;
    }
    if(myDir == LEFT)
    {
       playerPos.pos->x--;  
    }
    if(myDir == RIGHT)
    {
        playerPos.pos->x++;
    }
    if(myDir == DOWN)
    {
        playerPos.pos->y++;
    }
    if (getPlayerPos().pos->x == mainGameMechsRef->getBoardSizeX()-1)
    {
        playerPos.pos->x = 1;
    }
    if (getPlayerPos().pos->y == mainGameMechsRef->getBoardSizeY()-1)
    {
        playerPos.pos->y = 1;
    }
    if (getPlayerPos().pos->x == 0)
    {
        playerPos.pos->x = (mainGameMechsRef->getBoardSizeX()-2);
    }
    if (getPlayerPos().pos->y == 0)
    {
        playerPos.pos->y =  (mainGameMechsRef->getBoardSizeY()-2);
    }

}

// More methods to be added