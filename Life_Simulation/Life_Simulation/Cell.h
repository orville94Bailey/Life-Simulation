#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include <ostream>
#include <iostream>

class cell
{
public:
    cell();
    void switchState();
    bool isDead();
    void setLifeState(bool );
    ~cell();


private:
    bool lifeState;
};

std::ostream& operator<<( std::ostream&,cell&);

#endif // CELL_H_INCLUDED
