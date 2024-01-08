/*
 * @lc app=leetcode.cn id=2942 lang=cpp
 *
 * [2942] 查找包含给定字符的单词
 */

// @lc code=start
class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        // 特判
        if (words.empty())
            return {};

        vector<int> ans;
        for (int i = 0; i < words.size(); i++)
        {
            bool find = false;
            for (char &c : words[i])
                if (c == x)
                {
                    find = true;
                    break;
                }
            if (find)
                ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end
