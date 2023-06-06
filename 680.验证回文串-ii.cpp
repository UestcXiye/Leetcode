/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */

// @lc code=start
class Solution
{
private:
    bool isPalindrome(const string &s, int low, int high)
    {
        for (int i = low, j = high; i < j; i++, j--)
            if (s[i] != s[j])
                return false;
        return true;
    }

public:
    bool validPalindrome(string s)
    {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            if (s[left] == s[right])
            {
                left++;
                right--;
            }
            else
                return isPalindrome(s, left, right - 1) || isPalindrome(s, left + 1, right);
        }
        return true;
    }
};
// @lc code=end
