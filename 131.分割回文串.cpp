/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start

// 回溯

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> path;

        function<void(int, int)> backtrack = [&](int level, int start) -> void
        {
            if (level == n)
            {
                ans.push_back(path);
                return;
            }
            if (level < n - 1)
            {
                // 跳过当前字符 s[level]
                backtrack(level + 1, start);
            }

            if (isPalindrome(s, start, level))
            {
                // s[start, level] 是一个回文串
                path.push_back(s.substr(start, level - start + 1));
                // 下一个回文串从 level+1 开始
                backtrack(level + 1, level + 1);
                // 回溯
                path.pop_back();
            }
        };

        backtrack(0, 0);

        return ans;
    }
    // 辅函数 - 判断字符串 s 的 [left, right] 部分是否回文
    bool isPalindrome(const string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end
