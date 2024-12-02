#include "GameMechs.h"
#include "MacUILib.h"
#include "Food.h"

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
void Food::generateFood(objPosArrayList* blockOff)
{
    objPos temp;
    bool overlap = false; 
    int tempx;
    int tempy;
    do{
        overlap=0;
        tempx=1+rand()%28;
        tempy=1+rand()%13;
        //the modulo parameter is hard coded as we have no way of refrencing the game mechanics with the UML described Food class as it
        //an improvement would be including a game mechanics refrence pointer within the Food class like in the Player class
        foodPos.setObjPos(tempx,tempy,foodPos.symbol);
        for (int i = 0 ; i < blockOff->getSize() ; i++)
        {
            temp=blockOff->getElement(i);
            if (foodPos.isPosEqual(&(temp)))
            {
                overlap=true;
            }
        }
    }
    while(overlap);
}
objPos const Food::getFoodPos()
{
    objPos returnPos;
    returnPos.pos->x = foodPos.pos->x;
    returnPos.pos->y = foodPos.pos->y;
    returnPos.symbol = foodPos.symbol;
    
    return returnPos;
}