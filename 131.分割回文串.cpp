/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start

// 回溯

class Solution
{
private:
    vector<vector<string>> ans;

public:
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<string> path;
        backtracking(s, 0, 0, path);
        return ans;
    }
    // 辅函数 - 回溯算法
    void backtracking(const string &s, int level, int start, vector<string> path)
    {
        if (level == s.size())
        {
            ans.push_back(path);
            return;
        }
        if (level < s.size() - 1)
            backtracking(s, level + 1, start, path);
        if (isPalindrome(s, start, level))
        {
            path.push_back(s.substr(start, level - start + 1));
            backtracking(s, level + 1, level + 1, path);
            path.pop_back();
        }
    }
    // 辅函数 - 判断字符串 s 的 [left, right] 部分是否回文
    bool isPalindrome(const string &s, int left, int right)
    {
        while (left < right)
            if (s[left++] != s[right--])
                return false;
        return true;
    }
};
// @lc code=end
