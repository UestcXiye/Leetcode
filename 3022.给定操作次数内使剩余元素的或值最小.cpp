/*
 * @lc app=leetcode.cn id=3022 lang=cpp
 *
 * [3022] 给定操作次数内使剩余元素的或值最小
 */

// @lc code=start
class Solution
{
public:
    int minOrAfterOperations(vector<int> &nums, int k)
    {
        int ans = 0, mask = 0;
        // 从高位到低位一次枚举
        for (int b = 29; b >= 0; b--)
        {
            mask |= 1 << b;
            int cnt = 0;
            // -1 在二进制下全为 1，所以可以省去特判每一段第一个数
            int and_res = -1;
            for (int &x : nums)
            {
                and_res &= x & mask;
                if (and_res)
                {
                    // 合并 x，操作次数加一
                    cnt++;
                }
                else
                {
                    // 准备合并下一段，省去特判每一段的第一个数
                    and_res = -1;
                }
            }
            if (cnt > k)
            {
                ans |= 1 << b; // 答案的这个比特位必须是 1
                // 后面不考虑这个比特位，这一位一定为 1，消除这一位的影响
                mask ^= 1 << b;
            }
        }
        return ans;
    }
};
// @lc code=end
