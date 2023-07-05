/*
 * @lc app=leetcode.cn id=1608 lang=cpp
 *
 * [1608] 特殊数组的特征值
 */

// @lc code=start
class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int num = 1; num <= nums[n - 1]; num++)
        {
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] >= num)
                    count++;
                if (count > num)
                    break;
            }
            if (count == num)
            {
                return num;
            }
        }
        return -1;
    }
};
// @lc code=end
