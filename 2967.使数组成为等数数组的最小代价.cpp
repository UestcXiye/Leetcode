/*
 * @lc app=leetcode.cn id=2967 lang=cpp
 *
 * [2967] 使数组成为等数数组的最小代价
 */

// @lc code=start
class Solution
{
public:
    long long minimumCost(vector<int> &nums)
    {
        // 特判
        if (nums.empty())
            return 0LL;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = nums[n / 2];
        while (left > 0 && isPalindrome(left) == false)
            left--;
        int right = nums[n / 2];
        while (right <= 1e9 && isPalindrome(right) == false)
            right++;
        return min(calCost(nums, left), calCost(nums, right));
    }
    // 辅函数 - 判断 x 是不是回文数
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        return s == string(s.rbegin(), s.rend());
    }
    // 辅函数 - 计算将数组 nums 的所有元素全部变成 x 的代价
    long long calCost(vector<int> &nums, int x)
    {
        long long cost = 0;
        for (int &num : nums)
            cost += abs(num - x);
        return cost;
    }
};
// @lc code=end
