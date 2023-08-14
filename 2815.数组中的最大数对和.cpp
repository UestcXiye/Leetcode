/*
 * @lc app=leetcode.cn id=2815 lang=cpp
 *
 * [2815] 数组中的最大数对和
 */

// @lc code=start
class Solution
{
private:
    int maxDigit(int x)
    {
        int maxDigit = 0;
        while (x)
        {
            maxDigit = max(maxDigit, x % 10);
            x /= 10;
        }
        return maxDigit;
    }

public:
    int maxSum(vector<int> &nums)
    {
        int n = nums.size();
        int maxSum = -1;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (maxDigit(nums[i]) == maxDigit(nums[j]))
                    maxSum = max(maxSum, nums[i] + nums[j]);
        return maxSum;
    }
};
// @lc code=end
