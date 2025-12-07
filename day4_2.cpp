#include <iostream>

using namespace std;

int main()
{
    vector<string> rollsGrid;
    string inp;
    int ans = 0;
    while (cin >> inp)
    {
        rollsGrid.push_back(inp);
    }

    bool changed = true;
    while (changed)
    {
        changed = false;
        for (int i = 0; i < rollsGrid.size(); i++)
        {
            string row = rollsGrid[i];
            for (int j = 0; j < row.size(); j++)
            {
                char c = row[j];
                if (c == '.')
                    continue;
                int countSorrounding = 0;
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        if (di == 0 && dj == 0)
                            continue;
                        int Di = i + di, Dj = j + dj;
                        if (Di < 0 || Di >= rollsGrid.size() || Dj < 0 || Dj >= row.size())
                            continue;
                        if (rollsGrid[Di][Dj] == '@')
                        {
                            countSorrounding++;
                        }
                    }
                }
                if (countSorrounding < 4)
                {
                    ans++;
                    rollsGrid[i][j] = '.';
                    changed = true;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}