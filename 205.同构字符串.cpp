/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
// class Solution
// {
// public:
//     bool isIsomorphic(string s, string t)
//     {
//         if (s.size() != t.size())
//             return false;
//         for (int i = 0; i < s.size(); i++)
//             if (s.find(s[i]) != t.find(t[i]))
//                 return false;
//         return true;
//     }
// };
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> smap;
        unordered_map<char, char> tmap;
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            if ((smap.find(s[i]) != smap.end() && smap[s[i]] != t[i]) || (tmap.find(t[i]) != tmap.end() && tmap[t[i]] != s[i]))
                return false;
            smap.insert(pair<char, char>(s[i], t[i]));
            tmap.insert(pair<char, char>(t[i], s[i]));
        }
        return true;
    }
};
// @lc code=end
