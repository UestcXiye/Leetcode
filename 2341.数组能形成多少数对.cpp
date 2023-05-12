/*
 * @lc app=leetcode.cn id=2341 lang=cpp
 *
 * [2341] 数组能形成多少数对
 */

// @lc code=start
class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        for (int num : nums)
        {
            if (umap.count(num))
                umap[num]++;
            else
                umap[num] = 1;
        }
        int numPairs = 0, remained = 0;
        for (auto it = umap.begin(); it != umap.end(); it++)
        {
            if (it->second % 2 == 1)
                remained++;
            numPairs += it->second / 2;
        }
        return {numPairs, remained};
    }
};
// @lc code=end
