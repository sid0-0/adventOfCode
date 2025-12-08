#include <iostream>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<double, pair<int, int>> Edge;

double getDistance(const vector<ll> &a, const vector<ll> &b)
{
    double dist = 0;
    for (int i = 0; i < a.size(); i++)
    {
        dist += pow(a[i] - b[i], 2);
    }
    return sqrt(dist);
}

int getParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
        return node;
    return parent[node] = getParent(parent[node], parent);
}

int main()
{
    string inp;
    vector<vector<ll>> points;
    vector<int> parent;
    while (getline(cin, inp))
    {
        vector<ll> point;
        size_t pos = 0;
        while ((pos = inp.find(',')) != string::npos)
        {
            point.push_back(stoll(inp.substr(0, pos)));
            inp.erase(0, pos + 1);
        }
        point.push_back(stoll(inp));
        points.push_back(point);
        parent.push_back(points.size() - 1);
    }

    vector<Edge> edges;
    int count = 0;

    for (int i = 0; i < points.size(); i++)
    {
        for (int j = i + 1; j < points.size(); j++)
        {
            count++;
            double dist = getDistance(points[i], points[j]);
            edges.push_back({dist, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());

    int connectionsMade = 0;
    while (!edges.empty() && connectionsMade < 1000)
    {
        Edge edge = edges.back();
        edges.pop_back();
        int u = edge.second.first;
        int v = edge.second.second;
        int pu = getParent(u, parent);
        int pv = getParent(v, parent);
        if (pu != pv)
        {
            parent[pu] = pv;
        }
        connectionsMade++;
    }

    map<int, int> circuitCount;
    for (int i = 0; i < points.size(); i++)
    {
        int p = getParent(i, parent);
        circuitCount[p]++;
    }

    set<int> seen;
    vector<ll> uniqueVals;
    for (auto x : circuitCount)
    {
        if (seen.find(x.second) == seen.end())
        {
            seen.insert(x.second);
            uniqueVals.push_back(x.second);
        }
    }

    sort(uniqueVals.begin(), uniqueVals.end(), greater<ll>());

    cout << uniqueVals[0] * uniqueVals[1] * uniqueVals[2] << endl;

    return 0;
}