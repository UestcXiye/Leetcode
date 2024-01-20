/*
 * @lc app=leetcode.cn id=2788 lang=cpp
 *
 * [2788] 按分隔符拆分字符串
 */

// @lc code=start
class Solution
{
public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator)
    {
        // 特判
        if (words.empty())
            return {};

        vector<string> ans;
        for (string &word : words)
        {
            int i = 0, len = word.length();
            while (i < len)
            {
                if (word[i] == separator)
                {
                    i++;
                    continue;
                }
                int start = i;
                i++;
                while (i < len && word[i] != separator)
                    i++;
                ans.push_back(word.substr(start, i - start));
            }
        }
        return ans;
    }
};
// @lc code=end
