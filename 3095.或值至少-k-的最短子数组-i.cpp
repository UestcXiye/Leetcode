/*
 * @lc app=leetcode.cn id=3095 lang=cpp
 *
 * [3095] 或值至少 K 的最短子数组 I
 */

// @lc code=start
class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        // 特判
        if (*max_element(nums.begin(), nums.end()) >= k)
            return 1;

        int n = nums.size();
        int minLen = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            int res = 0;
            for (int j = i; j < n; j++)
            {
                res |= nums[j];
                if (res >= k)
                {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};
// @lc code=end
