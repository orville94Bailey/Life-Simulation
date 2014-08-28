#ifndef SIMULATIONCONTROLLER_H_INCLUDED
#define SIMULATIONCONTROLLER_H_INCLUDED

#include "ReadObject.h"
#include "DisplayObject.h"
#include "Cell.h"
#include <cstdlib>

class SimulationController
{
public:
void run();
private:
ReadObject      input;
DisplayObject   output;

void checkNeighbors();
void getFile();
void arraySwap();
void populateCell(int width,int height);
void killCell(int width,int height);
void cleanArray();

cell windowArray[25][80], nextWindow[25][80];

};


#endif // SIMULATIONCONTROLLER_H_INCLUDED
