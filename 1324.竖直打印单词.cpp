/*
 * @lc app=leetcode.cn id=1324 lang=cpp
 *
 * [1324] 竖直打印单词
 */

// @lc code=start
class Solution
{
public:
    vector<string> printVertically(string s)
    {
        istringstream iss(s);
        string word;
        vector<string> words;
        int maxLen = INT_MIN;
        while (iss >> word)
        {
            maxLen = max(maxLen, (int)word.length());
            words.push_back(word);
        }

        vector<string> ans;
        for (int j = 0; j < maxLen; j++)
        {
            string col_str;
            for (string &word : words)
            {
                if (j >= word.length())
                    col_str.push_back(' ');
                else
                    col_str.push_back(word[j]);
            }
            ans.push_back(col_str);
        }

        for (string &str : ans)
            deleteBackSpace(str);
        return ans;
    }
    // 辅函数 - 删除字符串尾部的空格
    void deleteBackSpace(string &str)
    {
        int idx = str.length() - 1;
        while (idx >= 0 && str[idx] == ' ')
            idx--;
        str = str.substr(0, idx + 1);
    }
};
// @lc code=end
