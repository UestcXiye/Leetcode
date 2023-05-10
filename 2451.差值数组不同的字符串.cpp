/*
 * @lc app=leetcode.cn id=2451 lang=cpp
 *
 * [2451] 差值数组不同的字符串
 */

// @lc code=start
class Solution
{
public:
    string oddString(vector<string> &words)
    {
        map<vector<int>, vector<string>> m;
        for (string word : words)
        {
            int n = word.size();
            vector<int> difference(n - 1);
            for (int i = 0; i < n - 1; i++)
                difference[i] = word[i + 1] - word[i];
            m[difference].push_back(word);
        }
        for (auto it = m.begin(); it != m.end(); it++)
            if (it->second.size() == 1)
                return (it->second)[0];
        return "";
    }
};
// @lc code=end
