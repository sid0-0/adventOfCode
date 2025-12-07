#include <iostream>
using namespace std;
typedef long long ll;

ll evaluateSplits(vector<string> &diag, vector<vector<ll>> &memo, int row, int col)
{
    if (col < 0 || col >= diag[0].size())
        return 0;
    if (row >= diag.size())
        return 1;
    if (memo[row][col] != -1)
        return memo[row][col];
    if (diag[row][col] == '^')
    {
        memo[row][col] = evaluateSplits(diag, memo, row + 1, col - 1) + evaluateSplits(diag, memo, row + 1, col + 1);
    }
    else
    {
        memo[row][col] = evaluateSplits(diag, memo, row + 1, col);
    }
    return memo[row][col];
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
    vector<vector<ll>> memo(diag.size(), vector<ll>(diag[0].size(), -1));
    cout << evaluateSplits(diag, memo, 0, startCol) << endl;
    return 0;
}