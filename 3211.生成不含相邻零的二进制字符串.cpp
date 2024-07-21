/*
 * @lc app=leetcode.cn id=3211 lang=cpp
 *
 * [3211] 生成不含相邻零的二进制字符串
 */

// @lc code=start
class Solution
{
private:
    bool check(string &s)
    {
        int n = s.size();
        for (int i = 0; i < n - 1; i++)
            if (s[i] == '0' && s[i + 1] == '0')
                return false;
        return true;
    }

public:
    vector<string> validStrings(int n)
    {
        vector<string> ans;
        string cur = "";
        backtrack(cur, 0, n, ans);
        return ans;
    }
    // 辅函数- 回溯
    void backtrack(string &cur, int level, int n, vector<string> &ans)
    {
        if (level > n)
            return;
        if (level == n && check(cur))
        {
            ans.push_back(cur);
            return;
        }
        
        cur.push_back('0');
        level++;
        backtrack(cur, level, n, ans);
        level--;
        cur.pop_back();

        cur.push_back('1');
        level++;
        backtrack(cur, level, n, ans);
        level--;
        cur.pop_back();
    }
};
// @lc code=end
