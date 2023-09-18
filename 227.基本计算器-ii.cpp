/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start

// 模拟

class Solution
{
public:
    int calculate(string s)
    {
        vector<int> nums;
        char preSign = '+';
        int num = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
                num = num * 10 + int(s[i] - '0');
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1)
            {
                switch (preSign)
                {
                case '+':
                    nums.push_back(num);
                    break;
                case '-':
                    nums.push_back(-num);
                    break;
                case '*':
                    nums.back() *= num;
                    break;
                case '/':
                    nums.back() /= num;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

// class Solution
// {
// public:
//     // 主函数
//     int calculate(string s)
//     {
//         int i = 0;
//         return parseExpr(s, i);
//     }
//     // 辅函数- 递归 parse 从位置 i 开始的剩余字符串
//     int parseExpr(const string &s, int &i)
//     {
//         char op = '+';
//         long left = 0, right = 0;
//         while (i < s.size())
//         {
//             if (s[i] != ' ')
//             {
//                 long n = parseNum(s, i);
//                 switch (op)
//                 {
//                 case '+':
//                     left += right;
//                     right = n;
//                     break;
//                 case '-':
//                     left += right;
//                     right = -n;
//                     break;
//                 case '*':
//                     right *= n;
//                     break;
//                 case '/':
//                     right /= n;
//                     break;
//                 }
//                 if (i < s.size())
//                     op = s[i];
//             }
//             i++;
//         }
//         return left + right;
//     }
//     // 辅函数- parse 从位置 i 开始的一个数字
//     long parseNum(const string &s, int &i)
//     {
//         long num = 0;
//         while (i < s.size() && isdigit(s[i]))
//         {
//             num = 10 * num + (s[i] - '0');
//             i++;
//         }
//         return num;
//     }
// };
// @lc code=end
