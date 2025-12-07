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
        for (ll n = x[0]; n <= x[1]; n++)
        {
            string num = to_string(n);
            int stringLen = num.length();

            for (int len = 1; len <= num.length() / 2; len++)
            {
                // the length of the string must be a multiple of the length of the substring
                if (stringLen % len != 0)
                    continue;

                string sub = num.substr(0, len);

                int count = 0;
                size_t pos = 0;

                // count occurrences of the substring in the string
                while ((pos = num.find(sub, pos)) != string::npos)
                {
                    count++;
                    pos += sub.length();
                }

                // if the substring repeated 'count' times equals the original string length
                // then we have found an invalid number
                if (count * len == stringLen)
                {
                    sum += n;
                    break;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}