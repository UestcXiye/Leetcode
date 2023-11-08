/*
 * @lc app=leetcode.cn id=2918 lang=cpp
 *
 * [2918] 数组的最小相等和
 */

// @lc code=start
class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        long long sum1 = 0, sum2 = 0;
        int countZero1 = 0, countZero2 = 0;
        for (const int num : nums1)
        {
            if (num)
                sum1 += num;
            else
                countZero1++;
        }
        for (const int num : nums2)
        {
            if (num)
                sum2 += num;
            else
                countZero2++;
        }
        if (sum1 < sum2 + countZero2 && countZero1 == 0)
            return -1;
        if (sum2 < sum1 + countZero1 && countZero2 == 0)
            return -1;
        return max(sum1 + countZero1, sum2 + countZero2);
    }
};
// @lc code=end
