/*
 * @lc app=leetcode.cn id=1437 lang=cpp
 *
 * [1437] 是否所有 1 都至少相隔 k 个元素
 */

// @lc code=start
class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        vector<int> indexOfOne;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 1)
                indexOfOne.push_back(i);
        if (indexOfOne.size() < 2)
            return true;
        for (int i = 0; i < indexOfOne.size() - 1; i++)
            if (indexOfOne[i + 1] - indexOfOne[i] <= k)
                return false;
        return true;
    }
};
// @lc code=end
