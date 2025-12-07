
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
    vector<ll> ingredients;
    ll inpIngredient;
    while (cin >> inpIngredient)
    {
        ingredients.push_back(inpIngredient);
    }
    sort(ranges.begin(), ranges.end());
    sort(ingredients.begin(), ingredients.end());

    int freshIngredients = 0;

    for (auto x : ingredients)
    {
        for (auto r : ranges)
        {
            if (x >= r[0] && x <= r[1])
            {
                freshIngredients++;
                break;
            }
        }
    }

    cout << freshIngredients << endl;

    return 0;
}