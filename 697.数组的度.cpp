/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> umap;
        for (int i = 0; i < n; i++)
        {
            if (umap.count(num))
            {
                umap[nums[i]][0]++;
                umap[nums[i]][2] = i;
            }
            else
                umap[nums[i]] = {1, i, i};
        }
        int maxTimes = 0;
        int minLen = 0;
        for (auto it = umap.begin(); it != umap.end(); it++)
        {
            if (it->second[0] > maxTimes)
            {
                maxTimes = it->second[0];
                minLen = it->second[2] - it->second[1] + 1;
            }
            else if (it->second[0] == maxTimes)
                minLen = min(minLen, it->second[2] - it->second[1] + 1);
        }
        return minLen;
    }
};
// @lc code=end
