/*
 * @lc app=leetcode.cn id=2176 lang=cpp
 *
 * [2176] 统计数组中相等且可以被整除的数对
 */

// @lc code=start
class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (nums[i] == nums[j] && (i * j) % k == 0)
                    ans++;
        return ans;
    }
};
// @lc code=end
