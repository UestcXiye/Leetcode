/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++)
            if (s.find(s[i]) != t.find(t[i]))
                return false;
        return true;
    }
};

// 哈希

// class Solution
// {
// public:
//     bool isIsomorphic(string s, string t)
//     {
//         if (s.size() != t.size())
//             return false;
//         unordered_map<char, char> hashOfs;
//         unordered_map<char, char> hashOft;
//         int len = s.size();
//         for (int i = 0; i < len; i++)
//         {
//             if ((hashOfs.find(s[i]) != hashOfs.end() && hashOfs[s[i]] != t[i]) || (hashOft.find(t[i]) != hashOft.end() && hashOft[t[i]] != s[i]))
//                 return false;
//             hashOfs.insert(pair<char, char>(s[i], t[i]));
//             hashOft.insert(pair<char, char>(t[i], s[i]));
//         }
//         return true;
//     }
// };

// class Solution
// {
// public:
//     bool isIsomorphic(string s, string t)
//     {
//         vector<int> s_first_index(256, 0), t_first_index(256, 0);
//         for (int i = 0; i < s.length(); ++i)
//         {
//             if (s_first_index[s[i]] != t_first_index[t[i]])
//             {
//                 return false;
//             }
//             s_first_index[s[i]] = t_first_index[t[i]] = i + 1;
//         }
//         return true;
//     }
// };
// @lc code=end
