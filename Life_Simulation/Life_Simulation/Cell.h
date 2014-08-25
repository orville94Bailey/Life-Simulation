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

    void friend operator<<(const std::ostream&,const cell&);
private:
    bool lifeState;
};

#endif // CELL_H_INCLUDED
