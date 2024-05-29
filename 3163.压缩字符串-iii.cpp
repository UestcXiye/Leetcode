/*
 * @lc app=leetcode.cn id=3163 lang=cpp
 *
 * [3163] 压缩字符串 III
 */

// @lc code=start
class Solution
{
public:
    string compressedString(string word)
    {
        string comp;
        // 分组循环
        int i = 0;
        while (i < word.length())
        {
            int j = i + 1;
            while (j < word.length() && word[i] == word[j])
                j++;
            int len = j - i;
            for (int k = 0; k < len / 9; k++)
            {
                comp.push_back('9');
                comp.push_back(word[i]);
            }
            if (len % 9)
            {
                comp.push_back(len % 9 + '0');
                comp.push_back(word[i]);
            }
            i = j;
        }
        return comp;
    }
};
// @lc code=end
