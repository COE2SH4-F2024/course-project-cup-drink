#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;
class Food
{
    private:
        objPosArrayList* foodBucket;
        //added this so the game size is fully customizable 
        //(board size change will not break game))
        GameMechs* gamemechptr;
    public:
        Food(GameMechs* gamemechref);
        ~Food();
        void generateFood(objPosArrayList* blockOff);
        objPosArrayList* const getFoodPos();
};
#endif
