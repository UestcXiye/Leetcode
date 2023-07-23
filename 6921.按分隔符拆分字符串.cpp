/*
 * @lc app=leetcode.cn id=6921 lang=cpp
 *
 * [6921] 按分隔符拆分字符串
 */

// @lc code=start
class Solution
{
public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator)
    {
        vector<string> ans;
        for (string &word : words)
        {
            stringstream ss(word);
            string s;
            while (getline(ss, s, separator))
                if (!s.empty())
                    ans.push_back(s);
        }
        return ans;
    }
}
// @lc code=end
