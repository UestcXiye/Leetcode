/*
 * @lc app=leetcode.cn id=2269 lang=cpp
 *
 * [2269] 找到一个数字的 K 美丽值
 */

// @lc code=start
class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {
        int ans = 0;
        string s = to_string(num);
        for (int i = 0; i <= s.size() - k; i++)
        {
            // 枚举所有长度为 k 的子串
            int temp = stoi(s.substr(i, k));
            if (temp != 0 && num % temp == 0)
                ans++;
        }
        return ans;
    }
};
// @lc code=end
