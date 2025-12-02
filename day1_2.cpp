#include <string>
#include <iostream>
using namespace std;
int main()
{
    string inp;
    int pos = 50, countOfZeroes = 0;
    while (cin >> inp)
    {
        char dir = inp[0];
        int mag = stoi(inp.substr(1));
        // count full rotations
        countOfZeroes += mag / 100;
        // find the final displacement
        mag %= 100;
        int oldPos = pos;
        if (dir == 'L')
        {
            pos = (pos - mag + 100) % 100;
            // if oldPos is 0, then it was counted last time
            // criteria for count:
            // new position is 0 OR
            // new position > old position i.e. crossed 0
            if (oldPos != 0 && (pos == 0 || pos > oldPos))
                countOfZeroes++;
        }
        else if (dir == 'R')
        {
            pos = (pos + mag + 100) % 100;
            // if oldPos is 0, then it was counted last time
            // criteria for count:
            // new position is 0 OR
            // new position < old position i.e. crossed 0
            if (oldPos != 0 && (pos == 0 || pos < oldPos))
                countOfZeroes++;
        }
    }
    cout << countOfZeroes << endl;
    return 0;
}