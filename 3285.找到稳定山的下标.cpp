/*
 * @lc app=leetcode.cn id=3285 lang=cpp
 *
 * [3285] 找到稳定山的下标
 */

// @lc code=start
class Solution
{
public:
    vector<int> stableMountains(vector<int> &height, int threshold)
    {
        vector<int> ans;
        for (int i = 1; i < height.size(); i++)
            if (height[i - 1] > threshold)
                ans.push_back(i);
        return ans;
    }
};
// @lc code=end
