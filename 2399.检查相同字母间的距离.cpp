/*
 * @lc app=leetcode.cn id=2399 lang=cpp
 *
 * [2399] 检查相同字母间的距离
 */

// @lc code=start
class Solution
{
public:
    bool checkDistances(string s, vector<int> &distance)
    {
        int n = s.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (s[i] == s[j] && j - i - 1 != distance[s[i] - 'a'])
                    return false;
        return true;
    }
};

// class Solution
// {
// public:
//     bool checkDistances(string s, vector<int> &distance)
//     {
//         vector<int> firstIndex(26, -1);
//         for (int i = 0; i < s.size(); i++)
//         {
//             int index = s[i] - 'a';
//             if (firstIndex[index] != -1 && i - firstIndex[index] - 1 != distance[index])
//                 return false;
//             firstIndex[index] = i;
//         }
//         return true;
//     }
// };
// @lc code=end
