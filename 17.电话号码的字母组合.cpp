/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

// 模拟

// class Solution
// {
// public:
//     vector<string> letterCombinations(string digits)
//     {
//         if (digits.empty())
//             return {};
//         int n = digits.size();
//         unordered_map<char, string> dict{
//             {'2', "abc"},
//             {'3', "def"},
//             {'4', "ghi"},
//             {'5', "jkl"},
//             {'6', "mno"},
//             {'7', "pqrs"},
//             {'8', "tuv"},
//             {'9', "wxyz"}};
//         vector<string> ans;
//         if (n == 1)
//         {
//             string s = dict[digits[0]];
//             for (char &c : s)
//             {
//                 string temp;
//                 temp += c;
//                 ans.push_back(temp);
//             }
//         }
//         else if (n == 2)
//         {
//             string s1 = dict[digits[0]], s2 = dict[digits[1]];
//             for (char &c1 : s1)
//                 for (char &c2 : s2)
//                 {
//                     string temp;
//                     temp += c1;
//                     temp += c2;
//                     ans.push_back(temp);
//                 }
//         }
//         else if (n == 3)
//         {
//             string s1 = dict[digits[0]], s2 = dict[digits[1]], s3 = dict[digits[2]];
//             for (char &c1 : s1)
//                 for (char &c2 : s2)
//                     for (char &c3 : s3)
//                     {
//                         string temp;
//                         temp += c1;
//                         temp += c2;
//                         temp += c3;
//                         ans.push_back(temp);
//                     }
//         }
//         else
//         {
//             string s1 = dict[digits[0]], s2 = dict[digits[1]], s3 = dict[digits[2]], s4 = dict[digits[3]];
//             for (char &c1 : s1)
//                 for (char &c2 : s2)
//                     for (char &c3 : s3)
//                         for (char &c4 : s4)
//                         {
//                             string temp;
//                             temp += c1;
//                             temp += c2;
//                             temp += c3;
//                             temp += c4;
//                             ans.push_back(temp);
//                         }
//         }
//         return ans;
//     }
// };

// 回溯

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        int n = digits.size();
        unordered_map<char, string> dict{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        vector<string> ans;
        string comb;
        backtracking(ans, dict, digits, 0, comb);
        return ans;
    }
    void backtracking(vector<string> &ans, unordered_map<char, string> &dict, string &digits, int level, string &comb)
    {
        if (level == digits.size())
            ans.push_back(comb);
        char digit = digits[level];
        string s = dict[digit];
        for (char &c : s)
        {
            comb.push_back(c);
            backtracking(ans, dict, digits, level + 1, comb);
            comb.pop_back();
        }
    }
};
// @lc code=end
