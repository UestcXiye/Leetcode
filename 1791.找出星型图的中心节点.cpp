/*
 * @lc app=leetcode.cn id=1791 lang=cpp
 *
 * [1791] 找出星型图的中心节点
 */

// @lc code=start
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        int n = edges.size();
        unordered_map<int, int> umap;
        for (auto &edge : edges)
            for (auto &node : edge)
                umap[node]++;
        int ans = 0;
        for (auto it = umap.begin(); it != umap.end(); it++)
            if (it->second == n)
            {
                ans = it->first;
                break;
            }
        return ans;
    }
};
// @lc code=end
