/*
 * @lc app=leetcode.cn id=2206 lang=cpp
 *
 * [2206] 将数组划分成相等数对
 */

// @lc code=start
class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        for (int num : nums)
            umap[num]++;
        for (auto it = umap.begin(); it != umap.end(); it++)
            if (it->second % 2 != 0)
                return false;
        return true;
    }
};
// @lc code=end
