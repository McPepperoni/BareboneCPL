#include <iostream>
using namespace std;
int main()
{
    unsigned int y = 0;
    while (y != 10)
    {
        y++;
    }
    unsigned int x = 0;
    x++;
    while (x != 4)
    {
        unsigned int temp = 0;
        while (temp != 10)
        {
            unsigned int tempX = 0;
            while (tempX != y)
            {
                x++;
                tempX++;
            }
            temp++;
        }
    }
}
