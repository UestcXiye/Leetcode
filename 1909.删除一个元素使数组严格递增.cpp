/*
 * @lc app=leetcode.cn id=1909 lang=cpp
 *
 * [1909] 删除一个元素使数组严格递增
 */

// @lc code=start
class Solution
{
public:
    bool canBeIncreasing(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j < i; j++)
                temp.push_back(nums[j]);
            for (int j = i + 1; j < n; j++)
                temp.push_back(nums[j]);
            bool judge = true;
            for (int j = 0; j < temp.size() - 1; j++)
                if (temp[j + 1] <= temp[j])
                {
                    judge = false;
                    break;
                }
            if (judge)
                return true;
        }
        return false;
    }
};
// @lc code=end
