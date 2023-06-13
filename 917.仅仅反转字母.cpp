/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            while (left < right && !isalpha(s[left]))
                left++;
            while (left < right && !isalpha(s[right]))
                right--;
            if (left >= right)
                break;
            swap(s[left++], s[right--]);
        }
        return s;
    }
};
// @lc code=end
