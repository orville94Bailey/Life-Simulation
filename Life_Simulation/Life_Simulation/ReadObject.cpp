#include "ReadObject.h"

void ReadObject::readFile(std::string fileName,
                            cell *cellArray[][80])
{

    cell *holder;
    std::ifstream fileData;
    fileData.open(fileName.c_str());

    for (int height=0;height<25;height++)
    {
        for (int width=0;width<80;width++)
        {
            if (fileData.get() == '1')
            {
                holder = new cell;
                holder->setLifeState(true);
                cellArray[height][width] = holder;
                holder = NULL;
            }
            if(fileData.get()=='0')
            {
                holder = new cell;
                holder->setLifeState(false);
                cellArray[height][width]=holder;
                holder=NULL;
            }
        }
    }

    fileData.close();
}
