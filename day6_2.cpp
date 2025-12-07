#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    vector<string> input;
    string in;
    while (getline(cin, in))
    {
        input.push_back(in);
    }
    int maxCol = input[0].size();
    for (auto x : input)
    {
        if (x.size() > maxCol)
            maxCol = x.size();
    }
    ll result = 0;
    ll ans = 0;
    for (int i = 0; i < maxCol; i++)
    {
        string constructed = "";
        char currentOp;
        bool foundSomething = false;
        for (int j = 0; j < input.size(); j++)
        {
            if (i >= input[j].size())
                continue;
            char currentChar = input[j][i];
            if (isspace(currentChar))
                continue;
            if (isnumber(currentChar))
            {
                constructed += currentChar;
                foundSomething = true;
            }
            else
            {
                currentOp = currentChar;
                foundSomething = true;
            }
        }

        // if empty column, add result to ans and reset result
        if (!foundSomething)
        {
            ans += result;
            result = 0;
        }
        // if first number, set result to that number
        else if (result == 0)
        {
            result = stoll(constructed);
        }
        // else perform operation
        else
        {
            if (currentOp == '+')
            {
                result += stoll(constructed);
            }
            else if (currentOp == '*')
            {
                result *= stoll(constructed);
            }
        }
    }
    ans += result;
    cout << ans << endl;
    return 0;
}