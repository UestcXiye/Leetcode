/*
 * @lc app=leetcode.cn id=1668 lang=cpp
 *
 * [1668] 最大重复子字符串
 */

// @lc code=start
class Solution
{
public:
    int maxRepeating(string sequence, string word)
    {
        int ans = 0;
        string temp = word;
        for (int i = 1; i <= sequence.size() / word.size(); i++)
        {
            if (sequence.find(temp) != string::npos)
                ans = i;
            temp += word;
        }
        return ans;
    }
};
// @lc code=end
