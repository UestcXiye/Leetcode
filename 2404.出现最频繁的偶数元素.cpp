/*
 * @lc app=leetcode.cn id=2404 lang=cpp
 *
 * [2404] 出现最频繁的偶数元素
 */

// @lc code=start
class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        for (int num : nums)
            if (num % 2 == 0)
            {
                if (umap.count(num))
                    umap[num]++;
                else
                    umap[num] = 1;
            }
        if (umap.empty())
            return -1;
        int maxCount = 0;
        int minNum = 0;
        for (auto it = umap.begin(); it != umap.end(); it++)
        {
            if (it->second > maxCount)
            {
                maxCount = it->second;
                minNum = it->first;
            }
            else if (it->second == maxCount)
                minNum = min(minNum, it->first);
        }
        return minNum;
    }
};
// @lc code=end
