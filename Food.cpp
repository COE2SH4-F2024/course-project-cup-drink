#include "GameMechs.h"
#include "MacUILib.h"
#include "Food.h"

Food::Food(GameMechs* gamemechref)
{
    foodBucket = new objPosArrayList();
    foodBucket->insertHead(objPos(0,0,'1'));
    foodBucket->insertHead(objPos(0,0,'2'));
    foodBucket->insertHead(objPos(0,0,'3'));
    foodBucket->insertHead(objPos(0,0,'4'));
    foodBucket->insertHead(objPos(0,0,'5'));
    gamemechptr=gamemechref;
}
Food::~Food()
{
    foodBucket->~objPosArrayList();
    delete foodBucket;
}
void Food::generateFood(objPosArrayList* blockOff)
{
    objPos temp;
    bool overlap = false; 
    int tempx;
    int tempy;
    objPos tempfood;
    for (int x =0;x<foodBucket->getSize();x++)
    {
        do
        {
            overlap=0;
            tempx=1+rand()%(gamemechptr->getBoardSizeX()-2);
            tempy=1+rand()%(gamemechptr->getBoardSizeY()-2);
            //the modulo parameter is hard coded as we have no way of refrencing the game mechanics with the UML described Food class as it
            //an improvement would be including a game mechanics refrence pointer within the Food class like in the Player class
            tempfood.setObjPos(tempx,tempy,49+x);
            for (int i = 0 ; i < blockOff->getSize() ; i++)
            {
                temp=blockOff->getElement(i);
                if (tempfood.isPosEqual(&(temp)))
                {
                    overlap=true;
                }
            }
        }while(overlap);
        foodBucket->insertTail(tempfood);
        foodBucket->removeHead();

    }
}
objPosArrayList* const Food::getFoodPos()
{
    return foodBucket;
}