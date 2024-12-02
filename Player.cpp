#include "Player.h"

Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    foodRef = thisFoodRef;
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(objPos(1,2,'*'));
    playerPosList->insertHead(objPos(1,3,'*'));
    playerPosList->insertHead(objPos(1,4,'*'));

    

    


    // more actions to be included
}


Player::~Player()
{
    playerPosList->~objPosArrayList();
    delete playerPosList;
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
    if (myDir!=STOP)
    {
        if (checkSelfCollision())
        {
            mainGameMechsRef->setExitTrue();
            mainGameMechsRef->setLoseFlag();
        }
        if (checkFoodConsumption())
        {
            foodRef->generateFood(playerPosList);
        }
        else
        {
            playerPosList->removeTail();
        }
        
    }
    
}
int Player::getdir()
{
    return int(myDir);
}
bool Player::checkFoodConsumption()
{
    objPos tempfood;
    objPos head = playerPosList->getHeadElement();
    bool result;
    for (int i = 0 ; i < foodRef->getFoodPos()->getSize(); i++)
    {
        tempfood = foodRef->getFoodPos()->getElement(i);
        if (head.isPosEqual(&(tempfood)))
        {
            result=true;

            for (int j=0;j<int(tempfood.getSymbol())-48;j++)
            {
                playerPosList->insertTail(playerPosList->getTailElement());
                mainGameMechsRef->incrementScore();
            }

        }
    }
    return result;
}
bool Player::checkSelfCollision()
{
    objPos temp;
    objPos head = playerPosList->getHeadElement();
    bool collide = false; 
    //the modulo parameter is hard coded as we have no way of refrencing the game mechanics with the UML described Food class as it
    //an improvement would be including a game mechanics refrence pointer within the Food class like in the Player class
    for (int i = 1 ; i < playerPosList->getSize(); i++)
    {
        temp = playerPosList->getElement(i);
        if (head.isPosEqual(&(temp)))
        {
            collide=true;
        }
    }
    return collide;
}

// More methods to be added