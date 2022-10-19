#include <iostream>
#include <time.h>
#include <math.h>

namespace gd
{
    bool has8(int str[8])
    {
        bool is8 = false;
        for (int x = 0; x < 8; x++)
        {
            int tmp = abs(str[x]);
            while (tmp > 0)
            {
                if (tmp % 10 == 8)
                {
                    is8 = true;
                    break;
                }
                tmp /= 10;
            }
            if (is8)
                break;
        }
        return is8;
    }
}

