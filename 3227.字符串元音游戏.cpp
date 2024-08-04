/*
 * @lc app=leetcode.cn id=3227 lang=cpp
 *
 * [3227] 字符串元音游戏
 */

// @lc code=start
class Solution
{
public:
    bool doesAliceWin(string s)
    {
        for (char &c : s)
            if (isVowel(c))
                return true;
        return false;
    }
    // 辅函数
    bool isVowel(char &c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};
// @lc code=end
