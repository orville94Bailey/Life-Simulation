#include "Cell.h"

cell::cell()
{

}

void cell::switchState()
{
    lifeState= !lifeState;
}

void cell::setLifeState(bool newState)
{
    lifeState = newState;
}

std::ostream& operator<<( std::ostream& outStream,cell& cellCheck)
{
    if(!cellCheck.isDead())
    {
        outStream<<"1";
    }
    else
    {
        outStream<<"0";
    }
    return outStream;
}

bool cell::isDead()
{
    return !lifeState;
}

cell::~cell()
{

}
