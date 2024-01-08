/*
 * @lc app=leetcode.cn id=2982 lang=cpp
 *
 * [2982] 找出出现至少三次的最长特殊子字符串 II
 */

// @lc code=start

// 字符串分割 + 分类讨论

class Solution
{
public:
    int maximumLength(string s)
    {
        // 特判
        if (s.empty())
            return 0;

        vector<int> groups[26];
        int n = s.length();
        // int count = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     count++;
        //     if (i + 1 == n || s[i] != s[i + 1])
        //     {
        //         groups[s[i] - 'a'].push_back(count); // 统计连续字符长度
        //         count = 0;
        //     }
        // }

        // 分组循环
        for (int i = 0; i < n;)
        {
            int start = i;
            i++;
            while (i < n && s[i] == s[i - 1])
                i++;
            groups[s[i - 1] - 'a'].push_back(i - start); // 统计连续字符长度
        }

        int ans = 0;
        for (vector<int> &group : groups)
        {
            if (group.empty())
                continue;
            // 降序排序
            sort(group.begin(), group.end(), greater<int>());
            // 假设还有两个空串
            group.push_back(0);
            group.push_back(0);
            ans = max({ans, group[0] - 2, min(group[0] - 1, group[1]), group[2]});
        }
        return ans == 0 ? -1 : ans;
    }
};

// 字符串分割 + 枚举

// class Solution
// {
// public:
//     int maximumLength(string s)
//     {
//         // 特判
//         if (s.empty())
//             return 0;

//         vector<int> groups[26];
//         int n = s.length();
//         int count = 0;
//         for (int i = 0; i < n; i++)
//         {
//             count++;
//             if (i + 1 == n || s[i] != s[i + 1])
//             {
//                 groups[s[i] - 'a'].push_back(count); // 统计连续字符长度
//                 count = 0;
//             }
//         }

//         int mx = 0;
//         for (vector<int> &group : groups)
//             for (int &x : group)
//                 mx = max(mx, x);
//         // 枚举
//         for (int ans = mx; ans >= mx - 2 && ans > 0; ans--)
//         {
//             // 枚举字母，计算该字母长度为 ans 的特殊子串有几个
//             for (int i = 0; i < 26; i++)
//             {
//                 int count = 0;
//                 for (int len : groups[i])
//                     if (len >= ans)
//                         count += len - ans + 1;
//                 if (count >= 3)
//                     return ans;
//             }
//         }
//         return -1;
//     }
// };
// @lc code=end
