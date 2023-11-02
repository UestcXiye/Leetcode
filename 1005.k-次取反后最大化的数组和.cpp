/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count_neg = 0, min_abs_idx = 0;
        bool zero = false;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
                count_neg++;
            else if (nums[i] == 0)
                zero = true;
            if (abs(nums[i]) < abs(nums[min_abs_idx]))
                min_abs_idx = i;
        }

        if (k <= count_neg)
        {
            int index = 0;
            while (k--)
            {
                nums[index] = -nums[index];
                index++;
            }
        }
        else
        {
            for (int i = 0; i < count_neg; i++)
                nums[i] = -nums[i];
            if ((k - count_neg) % 2 == 1 && zero == false)
                nums[min_abs_idx] = -nums[min_abs_idx];
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
// @lc code=end
