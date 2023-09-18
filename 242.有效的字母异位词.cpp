/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start

// 哈希

// class Solution
// {
// public:
//     bool isAnagram(string s, string t)
//     {
//         unordered_map<char, int> hashOfs, hashOft;
//         for (char &c : s)
//             hashOfs[c]++;
//         for (char &c : t)
//             hashOft[c]++;
//         if (hashOfs.size() != hashOft.size())
//             return false;
//         for (auto it = hashOfs.begin(); it != hashOfs.end(); it++)
//         {
//             char c = it->first;
//             int count = it->second;
//             if (hashOft[c] != count)
//                 return false;
//         }
//         return true;
//     }
// };

// 排序

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
// @lc code=end
