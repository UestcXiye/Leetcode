/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        if (s.empty())
            return -1;
        unordered_map<char, int> hash;
        for (const char &c : s)
            hash[c]++;
        for (int i = 0; i < s.size(); i++)
            if (hash[s[i]] == 1)
                return i;
        return -1;
    }
};

// class Solution
// {
// public:
//     int firstUniqChar(string s)
//     {
//         unordered_map<int, int> position;
//         int n = s.size();
//         for (int i = 0; i < n; ++i)
//         {
//             if (position.count(s[i]))
//             {
//                 position[s[i]] = -1;
//             }
//             else
//             {
//                 position[s[i]] = i;
//             }
//         }
//         int first = n;
//         for (auto [_, pos] : position)
//         {
//             if (pos != -1 && pos < first)
//             {
//                 first = pos;
//             }
//         }
//         if (first == n)
//         {
//             first = -1;
//         }
//         return first;
//     }
// };

// @lc code=end
