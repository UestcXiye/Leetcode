/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
// class Solution
// {
// public:
//     int countSegments(string s)
//     {
//         istringstream iss(s);
//         vector<string> words;
//         string word;
//         while (iss >> word)
//             words.push_back(word);
//         return words.size();
//     }
// };

class Solution
{
public:
    int countSegments(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ')
                count++;
        return count;
    }
};
// @lc code=end
