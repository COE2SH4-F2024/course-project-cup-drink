#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.
#include <iostream>


// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[400];
    listSize=0;
    arrayCapacity=400;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        std::cout << "[WARNING] List is Full, No Insertion Allowed." << std::endl;
        return;
    }

    for(int i = listSize; i > 0; i--)
    {   
        aList[i] = aList[i - 1];  
    }
    aList[0].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    aList[listSize] = objPos(thisPos);
    listSize++;
}

void objPosArrayList::removeHead()
{
    if(listSize == 0)
    {
        std::cout << "[WARNING] List is Empty, No Removal Allowed" << std::endl;
        return;
    }
    for(int i = 0; i < listSize - 1; i++)   
        aList[i] = aList[i + 1]; 

    listSize--;
}

void objPosArrayList::removeTail()
{

    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    objPos temp (aList[0]);
    return temp;
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}