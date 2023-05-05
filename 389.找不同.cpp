/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
// class Solution
// {
// public:
//     char findTheDifference(string s, string t)
//     {
//         int count_c[26];
//         memset(count_c, 0, 26 * sizeof(int));
//         for (int i = 0; i < t.size(); i++)
//             count_c[t[i] - 'a']++;
//         for (int i = 0; i < s.size(); i++)
//             count_c[s[i] - 'a']--;
//         for (int i = 0; i < 26; i++)
//             if (count_c[i])
//                 return i + 'a';
//         return t[0];
//     }
// };

// class Solution
// {
// public:
//     char findTheDifference(string s, string t)
//     {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         for (int i = 0; i < s.size(); i++)
//             if (s[i] != t[i])
//                 return t[i];
//         return t[t.size() - 1];
//     }
// };

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int sum = 0;
        for (int i = 0; i < t.size(); i++)
            sum += t[i];
        for (int i = 0; i < s.size(); i++)
            sum -= s[i];
        return sum;
    }
};
// @lc code=end
