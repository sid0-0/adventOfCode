#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
    vector<string> numbers;
    string inp;
    while (cin >> inp)
    {
        numbers.push_back(inp);
    }
    int ans = 0;
    for (auto x : numbers)
    {
        int jolts = 0;
        int start = 0;
        for (int rep = 0; rep < 2; rep++)
        {
            int largest = 0;
            int multiplier = pow(10, 1 - rep);
            int end = x.size() - 2;
            if (rep == 1)
                end++;

            for (int i = start; i <= end; i++)
            {
                if (x[i] - '0' > largest)
                {
                    largest = x[i] - '0';
                    start = i + 1;
                }
            }
            jolts += largest * multiplier;
        }
        ans += jolts;
    }
    cout << ans << endl;
    return 0;
}
