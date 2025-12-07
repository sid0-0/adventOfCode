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
    ll ans = 0;
    for (auto x : numbers)
    {
        ll jolts = 0;
        int start = 0;
        int digitsToPick = 12;
        for (int rep = 0; rep < digitsToPick; rep++)
        {
            int largest = -1;
            ll multiplier = pow(10 * 1ll, digitsToPick - 1 - rep);
            int end = x.size() - (digitsToPick - rep);

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
