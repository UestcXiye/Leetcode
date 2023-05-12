#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

static bool cmp(const vector<int> A, const vector<int> B)
{
    return A[0] < B[0];
}

int main()
{
    vector<vector<int>> items1 = {{1, 1}, {4, 5}, {3, 8}};
    vector<vector<int>> items2 = {{3, 1}, {1, 5}};
    unordered_map<int, int> umap;
    for (vector<int> item : items1)
    {
        if (umap.count(item[0]))
            umap[item[0]] += item[1];
        else
            umap[item[0]] = item[1];
    }
    for (vector<int> item : items2)
    {
        if (umap.count(item[0]))
            umap[item[0]] += item[1];
        else
            umap[item[0]] = item[1];
    }

    vector<vector<int>> res;
    for (auto it = umap.begin(); it != umap.end(); it++)
        res.push_back({(*it).first, (*it).second});
    sort(res.begin(), res.end(), cmp);
    for (vector<int> v : res)
        cout << v[0] << " " << v[1] << endl;
    system("pause");
    return 0;
}
