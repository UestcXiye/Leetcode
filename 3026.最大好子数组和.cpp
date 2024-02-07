/*
 * @lc app=leetcode.cn id=3026 lang=cpp
 *
 * [3026] 最大好子数组和
 */

// @lc code=start

// 哈希 + 前缀和

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long ans = LLONG_MIN, sum = 0;
        unordered_map<int, long long> hash;
        for (int &x : nums)
        {
            auto it = hash.find(x + k);
            if (it != hash.end())
                ans = max(ans, sum + x - it->second);

            it = hash.find(x - k);
            if (it != hash.end())
                ans = max(ans, sum + x - it->second);

            it = hash.find(x);
            if (it == hash.end() || sum < it->second)
                hash[x] = sum;
            sum += x;
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};
// @lc code=end
