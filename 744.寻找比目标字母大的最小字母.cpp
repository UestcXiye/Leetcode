/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int n = letters.size();
        for (int i = 0; i < n; i++)
        {
            if (letters[i] > target)
                return letters[i];
        }
        return letters[0];
    }
};
// @lc code=end
