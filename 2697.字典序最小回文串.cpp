/*
 * @lc app=leetcode.cn id=2697 lang=cpp
 *
 * [2697] 字典序最小回文串
 */

// @lc code=start
class Solution
{
public:
    string makeSmallestPalindrome(string s)
    {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            if (s[left] != s[right])
            {
                char c = s[left] > s[right] ? s[right] : s[left];
                s[left] = s[right] = c;
            }
            left++;
            right--;
        }
        return s;
    }
};
// @lc code=end
