#include <iostream>
#include <sstream>
using namespace std;
typedef long long ll;
int main()
{
    vector<vector<ll>> ranges;
    string inp;
    while (getline(cin, inp, ','))
    {
        string nums;
        stringstream ss(inp);
        vector<ll> currentRange;
        while (getline(ss, nums, '-'))
        {
            currentRange.push_back(stoll(nums));
        }
        ranges.push_back(currentRange);
    }

    ll sum = 0;
    for (auto x : ranges)
    {
        int digitCount = 0;
        ll divider = 1;

        while (x[0] / divider > 0)
        {
            digitCount++;
            divider *= 10;
        }
        ll firstNum = x[0];
        // odd numbers of digits cannot create twice repeated number
        if (digitCount % 2 == 1)
        {
            digitCount++;
            firstNum = pow(10 * 1ll, digitCount - 1);
        }
        divider = pow(10 * 1ll, digitCount / 2) + 1;
        // for a given number n, to find the first multiple of x greater than or equal to n:
        // int firstMultiple = ((n + x - 1) / x) * x;
        ll number = (firstNum + divider - 1) / divider * divider;
        while (number >= x[0] && number <= x[1])
        {
            // uncomment this to see what numbers are being added
            // cout << number << " ";
            sum += number;
            number += divider;
            if (number >= pow(10 * 1ll, digitCount))
            {
                digitCount += 2;
                divider = pow(10 * 1ll, digitCount / 2) + 1;
                number = (pow(10 * 1ll, digitCount) + divider - 1) / divider * divider;
            }
        }
    }
    cout << sum << endl;
    return 0;
}