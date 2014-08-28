#include "ReadObject.h"

void ReadObject::readFile(std::string fileName,
                            cell cellArray[][80])
{

    cell holder;
    std::ifstream fileData;
    fileData.open(fileName.c_str());

    for (int height=0;height<25;height++)
    {
        for (int width=0;width<80;width++)
        {
            if (fileData.get() == '1')
            {
                holder.setLifeState(true);
                cellArray[height][width] = holder;
            }
            if(fileData.get()=='0')
            {
                holder.setLifeState(false);
                cellArray[height][width]=holder;
            }
        }
        fileData.get();
    }

    fileData.close();
}
