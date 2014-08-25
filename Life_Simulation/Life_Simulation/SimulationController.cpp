#include "SimulationController.h"

void SimulationController::checkNeighbors()
{
    int liveNeighbors=0;
    for(int height = 0; height<25; height++)
    {
        for(int width = 0;width<80;width++)
        {
            if(height==0)
            {
                if(width==0)
                {
                    if(!windowArray[height+1][width]->isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height+1][width+1]->isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height][width+1]->isDead())
                    {
                        liveNeighbors++;
                    }
                }
                else if(width==79)
                {
                    if(!windowArray[height+1][width]->isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height+1][width-1]->isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height][width-1]->isDead())
                    {
                        liveNeighbors++;
                    }
                }
                else
                {
                    if(!windowArray[height][width-1]->isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height][width+1]->isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height+1][width]->isDead())
                    {
                        liveNeighbors++;
                    }if(!windowArray[height+1][width+1]->isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height+1][width-1]->isDead())
                    {
                        liveNeighbors++;
                    }
                }
            }
            else if(height==24)
            {
                if (width==0)
                {
                    if(!windowArray[height-1][width]->isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height-1][width+1]->isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height][width+1]->isDead())
                    {
                        liveNeighbors++;
                    }
                }
                else if(width==79)
                {
                    if(!windowArray[height-1][width]->isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height-1][width-1]->isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height][width-1]->isDead())
                    {
                        liveNeighbors++;
                    }
                }
            }
            else//check 8 cells around self
            {
                if(!windowArray[height+1][width]->isDead())
                {
                    liveNeighbors++;
                }
                if(!windowArray[height+1][width+1]->isDead())
                {
                    liveNeighbors++;
                }
                if(!windowArray[height][width+1]->isDead())
                {
                    liveNeighbors++;
                }
                if(!windowArray[height][width-1]->isDead())
                {
                    liveNeighbors++;
                }
                if(!windowArray[height][width+1]->isDead())
                {
                    liveNeighbors++;
                }
                if(!windowArray[height-1][width+1]->isDead())
                {
                    liveNeighbors++;
                }
                if(!windowArray[height-1][width]->isDead())
                {
                    liveNeighbors++;
                }
                if(!windowArray[height11][width-1]->isDead())
                {
                    liveNeighbors++;
            }
        }
    }
}

void SimulationController::getFile()
{
    std::string fileName;
    std::cout<<"Enter the filename: ";
    std::cin>>fileName;
    input.readFile(fileName, windowArray);
}
