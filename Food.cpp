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