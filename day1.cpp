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
        if (dir == 'L')
            pos -= mag;
        else if (dir == 'R')
            pos += mag;
        pos %= 100;
        if (pos == 0) countOfZeroes++;
    }
    cout << countOfZeroes << endl;
    return 0;
}