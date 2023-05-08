/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// @lc code=start
class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        vector<string> ans;
        string s[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        // for (string word : s)
        //     cout << word << endl;
        unordered_set<char> check[3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < s[i].size(); j++)
                check[i].insert(s[i][j]);
        // for (int i = 0; i < 3; i++)
        // {
        //     for (auto it = check[i].begin(); it != check[i].end(); it++)
        //         cout << *it << " ";
        //     cout << endl;
        // }
        for (string word : words)
        {
            int i;
            bool judge = true;
            for (i = 0; i < 3; i++)
                if (check[i].count(tolower(word[0])))
                    break;
            for (char c : word)
                if (!check[i].count(tolower(c)))
                {
                    judge = false;
                    break;
                }
            if (judge == true)
                ans.push_back(word);
        }
        return ans;
    }
};

// class Solution
// {
// public:
//     vector<string> findWords(vector<string> &words)
//     {
//         vector<string> ans;
//         string rowIdx = "12210111011122000010020202";
//         for (auto &word : words)
//         {
//             bool isValid = true;
//             char idx = rowIdx[tolower(word[0]) - 'a'];
//             for (int i = 1; i < word.size(); ++i)
//             {
//                 if (rowIdx[tolower(word[i]) - 'a'] != idx)
//                 {
//                     isValid = false;
//                     break;
//                 }
//             }
//             if (isValid)
//             {
//                 ans.emplace_back(word);
//             }
//         }
//         return ans;
//     }
// };
// @lc code=end
