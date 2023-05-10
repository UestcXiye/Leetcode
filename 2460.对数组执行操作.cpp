/*
 * @lc app=leetcode.cn id=2460 lang=cpp
 *
 * [2460] 对数组执行操作
 */

// @lc code=start
class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (nums[i] == 0)
                {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
        return nums;
    }
};
// @lc code=end
