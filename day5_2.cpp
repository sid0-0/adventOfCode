
#include <iostream>
#include <sstream>
using namespace std;
typedef long long ll;
int main()
{
    vector<vector<ll>> ranges;
    string inp;
    while (getline(cin, inp))
    {
        if (inp.empty())
        {
            break;
        }
        string nums;
        stringstream ss(inp);
        vector<ll> currentRange;
        while (getline(ss, nums, '-'))
        {
            currentRange.push_back(stoll(nums));
        }
        ranges.push_back(currentRange);
    }
    sort(ranges.begin(), ranges.end());

    ll freshIngredients = 0;

    // merge overlapping ranges
    for (int i = 0; i < ranges.size(); i++)
    {
        ll start = ranges[i][0];
        ll end = ranges[i][1];
        while (i + 1 < ranges.size() && ranges[i + 1][0] <= end)
        {
            end = max(end, ranges[i + 1][1]);
            i++;
        }
        freshIngredients += (end - start + 1);
    }

    cout << freshIngredients << endl;

    return 0;
}