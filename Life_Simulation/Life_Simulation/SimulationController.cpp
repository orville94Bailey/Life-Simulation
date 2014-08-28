#include "SimulationController.h"

void SimulationController::checkNeighbors()
{
    for(int height = 0; height<25; height++)
    {
        for(int width = 0;width<80;width++)
        {
            int liveNeighbors=0;
            if(height==0)
            {
                if(width==0)
                {
                    if(!windowArray[height+1][width].isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height+1][width+1].isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height][width+1].isDead())
                    {
                        liveNeighbors++;
                    }
                }
                else if(width==79)
                {
                    if(!windowArray[height+1][width].isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height+1][width-1].isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height][width-1].isDead())
                    {
                        liveNeighbors++;
                    }
                }
                else
                {
                    if(!windowArray[height][width-1].isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height][width+1].isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height+1][width].isDead())
                    {
                        liveNeighbors++;
                    }if(!windowArray[height+1][width+1].isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height+1][width-1].isDead())
                    {
                        liveNeighbors++;
                    }
                }
            }
            else if(height==24)
            {
                if (width==0)
                {
                    if(!windowArray[height-1][width].isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height-1][width+1].isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height][width+1].isDead())
                    {
                        liveNeighbors++;
                    }
                }
                else if(width==79)
                {
                    if(!windowArray[height-1][width].isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height-1][width-1].isDead())
                    {
                        liveNeighbors++;
                    }
                    if(!windowArray[height][width-1].isDead())
                    {
                        liveNeighbors++;
                    }
                }
            }
            else//check 8 cells around self
            {
                if(!windowArray[height+1][width].isDead())
                {
                    liveNeighbors++;
                }
                if(!windowArray[height+1][width+1].isDead())
                {
                    liveNeighbors++;
                }
                if(!windowArray[height][width+1].isDead())
                {
                    liveNeighbors++;
                }
                if(!windowArray[height][width-1].isDead())
                {
                    liveNeighbors++;
                }
                if(!windowArray[height][width+1].isDead())
                {
                    liveNeighbors++;
                }
                if(!windowArray[height-1][width+1].isDead())
                {
                    liveNeighbors++;
                }
                if(!windowArray[height-1][width].isDead())
                {
                    liveNeighbors++;
                }
                if(!windowArray[height][width-1].isDead())
                {
                    liveNeighbors++;
                }
            }

        switch(liveNeighbors)
        {
        case 0:
        case 1:
            killCell(width,height);
            break;
        case 2:
            if(!windowArray[height][width].isDead())
            {
                populateCell(width,height);
            }
            break;
        case 3:
            populateCell(width,height);
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            killCell(width,height);
            break;
        }
        }
    }
}

void SimulationController::populateCell(int width, int height)
{
    nextWindow[height][width].setLifeState(true);
}

void SimulationController::killCell(int width, int height)
{
    nextWindow[height][width].setLifeState(false);
}

void SimulationController::getFile()
{
    std::string fileName;
    std::cout<<"Enter the filename: ";
    std::cin>>fileName;
    input.readFile(fileName.c_str(), windowArray);
}

void SimulationController::arraySwap()
{
    for(int height=0;height<25;height++)
    {
        for(int width=0;width<80;width++)
        {
            windowArray[height][width]=nextWindow[height][width];
        }
    }
}

void SimulationController::run()
{
    cleanArray();
    getFile();
    for (int generations=0;generations<10;generations++)
    {
        output.displayMap(windowArray);
        checkNeighbors();
        arraySwap();
        system("pause");
    }
}

void SimulationController::cleanArray()
{
    cell deadCell;
    deadCell.setLifeState(0);
    for(int height=0;height<25;height++)
    {
        for(int width=0;width<80;width++)
        {
            windowArray[height][width]=deadCell;
            nextWindow[height][width]=deadCell;
        }
    }
}

