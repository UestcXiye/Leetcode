/*
 * @lc app=leetcode.cn id=3271 lang=cpp
 *
 * [3271] 哈希分割字符串
 */

// @lc code=start
class Solution
{
public:
    string stringHash(string s, int k)
    {
        int n = s.length();
        string result;
        for (int i = 0; i < n / k; i++)
        {
            int sum = 0;
            for (int j = 0; j < k; j++)
                sum += s[i * k + j] - 'a';
            int hashedChar = sum % 26;
            result.push_back(hashedChar + 'a');
        }
        return result;
    }
};
// @lc code=end
