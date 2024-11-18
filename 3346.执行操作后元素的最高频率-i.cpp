/*
 * @lc app=leetcode.cn id=3346 lang=cpp
 *
 * [3346] 执行操作后元素的最高频率 I
 */

// @lc code=start
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        unordered_map<int, int> cnt;
        map<int, int> diff;
        for (int x : nums)
        {
            cnt[x]++;
            diff[x];       // 把 x 插入 diff，以保证下面能遍历到 x
            diff[x - k]++; // 把 [x-k, x+k] 中的每个整数的出现次数都加一
            diff[x + k + 1]--;
        }

        int ans = 0, sum_d = 0;
        for (auto &[x, d] : diff)
        {
            sum_d += d;
            ans = max(ans, min(sum_d, cnt[x] + numOperations));
        }
        return ans;
    }
};
// @lc code=end
