/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution
{
private:
    // 判断 t 是否是 s 的子序列
    bool isSubsequence(string s, string t)
    {
        // 如果 t 长度大于 s，一定不是子序列
        if (t.size() > s.size())
            return false;
        int n = s.size(), m = t.size();
        // 记录当前 s 中匹配到了哪个位置
        int i = 0;
        for (char ch : t)
        {
            while (i < n && s[i] != ch)
                i++;
            if (i >= n)
                return false;
            // 此时 s[i] = ch，下次要从 s[i + 1] 开始匹配
            i++;
        }
        return true;
    }

public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        // 更长的、字典序更小的排在前面，这样一旦找到，就是结果
        sort(dictionary.begin(), dictionary.end(), [&](string &a, string &b)
             {
            if(a.size() == b.size()) return a < b;
            return a.size() > b.size(); });
        for (string &str : dictionary)
            if (isSubsequence(s, str))
                return str;
        return "";
    }
};
// @lc code=end
