/*
 * @lc app=leetcode.cn id=3158 lang=cpp
 *
 * [3158] 求出出现两次数字的 XOR 值
 */

// @lc code=start
class Solution
{
public:
    int duplicateNumbersXOR(vector<int> &nums)
    {
        set<int> s;
        int ans = 0;
        for (int &num : nums)
        {
            if (s.contains(num))
                ans ^= num;
            else
                s.insert(num);
        }
        return ans;
    }
};
// @lc code=end
