#include "DisplayObject.h"

void DisplayObject::displayMap(cell window[][80])
{
    for(int height = 0; height<25; height++)
    {
        for(int width = 0;width<80;width++)
        {
            std::cout << window[height][width];
        }
    }
}
