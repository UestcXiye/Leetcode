/*
 * @lc app=leetcode.cn id=1832 lang=cpp
 *
 * [1832] 判断句子是否为全字母句
 */

// @lc code=start
class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        set<char> s(sentence.begin(), sentence.end());
        return s.size() == 26;
    }
};
// @lc code=end
