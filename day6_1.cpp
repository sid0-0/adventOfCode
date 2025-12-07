#include <iostream>
#include <sstream>
using namespace std;
typedef long long ll;
int main()
{
    vector<vector<ll>> numbers;
    vector<char> ops;
    string inp;
    while (getline(cin, inp))
    {
        string inpLine;
        stringstream ss(inp);
        vector<ll> currentNumbers;
        while (getline(ss, inpLine, ' '))
        {
            if (inpLine.empty())
                continue;
            if (inpLine[0] >= '0' && inpLine[0] <= '9')
            {
                currentNumbers.push_back(stoll(inpLine));
            }
            else
            {
                ops.push_back(inpLine[0]);
            }
        }
        if (currentNumbers.size() > 0)
            numbers.push_back(currentNumbers);
    }
    ll result = 0;
    for(int i=0;i<numbers[0].size();i++)
    {
        ll current = numbers[0][i];
        for(int j=1;j<numbers.size();j++)
        {
            if(ops[i]=='+')
            {
                current += numbers[j][i];
            }
            else if(ops[i]=='*')
            {
                current *= numbers[j][i];
            }
        }
        result += current;
    }
    cout << result << endl;
}