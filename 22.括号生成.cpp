/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start

// 回溯

class Solution
{
public:
    // 主函数
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string comb;
        backtracking(ans, 0, 2 * n, comb);
        return ans;
    }
    // 辅函数 - 回溯函数
    void backtracking(vector<string> &ans, int level, int n, string &comb)
    {
        if (level == n)
        {
            if (isValid(comb))
                ans.push_back(comb);
            return;
        }
        comb.push_back('(');
        backtracking(ans, level + 1, n, comb);
        comb.pop_back();
        comb.push_back(')');
        backtracking(ans, level + 1, n, comb);
        comb.pop_back();
    }
    // 辅函数 - 判断字符串 s 是否有效
    bool isValid(const string &s)
    {
        int balance = 0;
        for (const char &c : s)
        {
            if (c == '(')
                balance++;
            else
                balance--;
            if (balance < 0)
                return false;
        }
        return balance == 0;
    }
};

// DFS
//
// class Solution
// {
// public:
//     vector<string> generateParenthesis(int n)
//     {
//         vector<string> ans;
//         dfs(ans, n, n, "");
//         return ans;
//     }

//     void dfs(vector<string> &ans, int left, int right,const string &str)
//     {
//         if (left < 0 || left > right)
//             return;
//         if (left == 0 && right == 0)
//         {
//             ans.push_back(str);
//             return;
//         }
//         dfs(ans, left - 1, right, str + '(');
//         dfs(ans, left, right - 1, str + ')');
//     }
// };
// @lc code=end
