/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start

// 分治
class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        // 特判
        if (expression.empty())
            return {};
        int n = expression.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*')
            {
                string leftStr = expression.substr(0, i);   // 左算式
                string rightStr = expression.substr(i + 1); // 右算式
                vector<int> left = diffWaysToCompute(leftStr);
                vector<int> right = diffWaysToCompute(rightStr);
                for (const int &l : left)
                    for (const int &r : right)
                        switch (c)
                        {
                        case '+':
                            ans.push_back(l + r);
                            break;
                        case '-':
                            ans.push_back(l - r);
                            break;
                        case '*':
                            ans.push_back(l * r);
                            break;
                        default:
                            break;
                        }
            }
        }
        // 特判，expression只有数字
        if (ans.empty())
            ans.push_back(stoi(expression));
        return ans;
    }
};

// 深度优先搜索
// class Solution
// {
// public:
//     // 主函数
//     vector<int> diffWaysToCompute(string expression)
//     {
//         // 特判
//         if (expression.empty())
//             return {};
//         int n = expression.size();
//         return dfs(expression, 0, n - 1);
//     }
//     // 辅函数
//     vector<int> dfs(string &expression, int left, int right)
//     {
//         vector<int> result;
//         for (int i = left; i <= right; i++)
//         {
//             char c = expression[i];
//             if (c == '+' || c == '-' || c == '*')
//             {
//                 vector<int> leftArr = dfs(expression, left, i - 1);
//                 vector<int> rightArr = dfs(expression, i + 1, right);
//                 for (const int &l : leftArr)
//                     for (const int &r : rightArr)
//                         switch (c)
//                         {
//                         case '+':
//                             result.push_back(l + r);
//                             break;
//                         case '-':
//                             result.push_back(l - r);
//                             break;
//                         case '*':
//                             result.push_back(l * r);
//                             break;
//                         default:
//                             break;
//                         }
//             }
//         }
//         // 特判，expression只有数字
//         if (result.empty())
//         {
//             // int temp = 0;
//             // for (int i = left; i <= right; i++)
//             //     temp = temp * 10 + (expression[i] - '0');
//             // result.push_back(temp);
//             string s = expression.substr(left, right - left + 1);
//             result.push_back(stoi(s));
//         }
//         return result;
//     }
// };

// 动态规划
// class Solution
// {
// public:
//     vector<int> diffWaysToCompute(string expression)
//     {
//         vector<int> data;
//         vector<char> ops;
//         int num = 0;
//         char op = ' ';
//         istringstream iss(expression + "+");
//         while (iss >> num && iss >> op)
//         {
//             data.push_back(num);
//             ops.push_back(op);
//         }
//         int n = data.size();
//         // 状态数组
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>()));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i; j >= 0; j--)
//             {
//                 if (i == j)
//                     dp[j][i].push_back(data[i]);
//                 else
//                 {
//                     for (int k = j; k < i; k++)
//                     {
//                         for (int &left : dp[j][k])
//                         {
//                             for (int &right : dp[k + 1][i])
//                             {
//                                 int val = 0;
//                                 switch (ops[k])
//                                 {
//                                 case '+':
//                                     val = left + right;
//                                     break;
//                                 case '-':
//                                     val = left - right;
//                                     break;
//                                 case '*':
//                                     val = left * right;
//                                     break;
//                                 default:
//                                     break;
//                                 }
//                                 dp[j][i].push_back(val);
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return dp[0][n - 1];
//     }
// };
// @lc code=end
