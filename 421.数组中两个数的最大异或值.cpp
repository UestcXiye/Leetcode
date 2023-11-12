/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int mx = *max_element(nums.begin(), nums.end());
        int high_bit = mx ? 31 - __builtin_clz(mx) : -1;

        int ans = 0, mask = 0;
        unordered_set<int> seen;
        // 从最高位开始枚举
        for (int i = high_bit; i >= 0; i--)
        {
            seen.clear();
            mask |= 1 << i;
            int new_ans = ans | (1 << i); // 这个比特位可以是 1 吗？
            for (int x : nums)
            {
                x &= mask; // 低于 i 的比特位置为 0
                if (seen.contains(new_ans ^ x))
                {
                    ans = new_ans; // 这个比特位可以是 1
                    break;
                }
                seen.insert(x);
            }
        }
        return ans;
    }
};
// @lc code=end
