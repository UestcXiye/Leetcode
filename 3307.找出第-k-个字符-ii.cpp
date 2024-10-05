/*
 * @lc app=leetcode.cn id=3307 lang=cpp
 *
 * [3307] 找出第 K 个字符 II
 */

// @lc code=start
class Solution
{
public:
    char kthCharacter(long long k, vector<int> &operations)
    {
        int inc = 0;
        for (int i = __lg(k - 1); i >= 0; i--)
        {
            if (k > (1LL << i))
            {
                // k 在右半边
                inc += operations[i];
                k -= (1LL << i);
            }
        }
        return 'a' + inc % 26;
    }
};
// @lc code=end
