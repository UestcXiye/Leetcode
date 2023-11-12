/*
 * @lc app=leetcode.cn id=100124 lang=cpp
 *
 * [100124] 找出强数对的最大异或值 II
 */

// @lc code=start
class Solution
{
public:
    int maximumStrongPairXor(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int high_bit = 31 - __builtin_clz(nums.back());

        int ans = 0, mask = 0;
        unordered_map<int, int> mp;
        // 从最高位开始枚举
        for (int i = high_bit; i >= 0; i--)
        {
            mp.clear();
            mask |= 1 << i;
            int new_ans = ans | (1 << i); // 这个比特位可以是 1 吗？
            for (int y : nums)
            {
                int mask_y = y & mask; // 低于 i 的比特位置为 0
                auto it = mp.find(new_ans ^ mask_y);
                if (it != mp.end() && it->second * 2 >= y)
                {
                    ans = new_ans; // 这个比特位可以是 1
                    break;
                }
                mp[mask_y] = y;
            }
        }
        return ans;
    }
};
// @lc code=end
