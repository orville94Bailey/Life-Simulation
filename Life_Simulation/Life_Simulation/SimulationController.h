#ifndef SIMULATIONCONTROLLER_H_INCLUDED
#define SIMULATIONCONTROLLER_H_INCLUDED

#include "ReadObject.h"
#include "DisplayObject.h"
#include "Cell.h"

class SimulationController
{
public:

private:
ReadObject      input;
DisplayObject   output;

void checkNeighbors();
void getFile();

cell *windowArray[25][80], *nextWindow[25][80];

};


#endif // SIMULATIONCONTROLLER_H_INCLUDED
