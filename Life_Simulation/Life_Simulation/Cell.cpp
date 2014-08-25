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

void cell::operator<<(const std::ostream&,const cell&)
{
    if(lifeState)
    {
        std::cout<<'0';
    }
    else
    {
        std::cout<<'1';
    }
}

bool cell::isDead()
{
    return lifeState;
}

cell::~cell()
{

}
