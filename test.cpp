#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {3, 2, 3, 2, 2, 2};
    unordered_map<int, int> umap;
    for (int num : nums)
        umap[num]++;
    for (auto it = umap.begin(); it != umap.end(); it++)
        cout << it->first << " " << it->second << endl;
    
    system("pause");
    return 0;
}
