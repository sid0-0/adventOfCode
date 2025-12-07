#include <iostream>
using namespace std;

int evaluateSplits(vector<string> &diag, int row, int col)
{
    int splits = 0;
    if (row >= diag.size())
        return splits;
    if (diag[row][col] == '^')
    {
        splits++;
        if (col - 1 >= 0 && diag[row][col - 1] != '|')
        {
            diag[row][col - 1] = '|';
            splits += evaluateSplits(diag, row + 1, col - 1);
        }
        if (col + 1 < diag[0].size() && diag[row][col + 1] != '|')
        {
            diag[row][col + 1] = '|';
            splits += evaluateSplits(diag, row + 1, col + 1);
        }
    }
    else if (diag[row][col] != '|')
    {
        diag[row][col] = '|';
        splits += evaluateSplits(diag, row + 1, col);
    }
    return splits;
}

int main()
{
    vector<string> diag;
    string inp;
    while (cin >> inp)
    {
        diag.push_back(inp);
    }
    int startCol = 0;
    while (diag[0][startCol] != 'S')
        startCol++;
    cout << evaluateSplits(diag, 0, startCol) << endl;
    return 0;
}