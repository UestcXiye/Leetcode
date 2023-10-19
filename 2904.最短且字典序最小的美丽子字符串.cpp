/*
 * @lc app=leetcode.cn id=2904 lang=cpp
 *
 * [2904] 最短且字典序最小的美丽子字符串
 */

// @lc code=start
// class Solution
// {
// public:
//     string shortestBeautifulSubstring(string s, int k)
//     {
//         string ans = "";
//         int n = s.size();
//         for (int i = 0; i <= n - k; i++)
//         {
//             string temp = getBeautifulSubstring(s, i, k);
//             if (temp.size() > 0)
//             {
//                 if (ans.empty())
//                     ans = temp;
//                 else
//                 {
//                     if (temp.size() < ans.size())
//                         ans = temp;
//                     else if (temp.size() == ans.size())
//                     {
//                         if (compare(temp, ans))
//                             ans = temp;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
//     // 辅函数 - 从下标 begin 开始截取美丽子字符串
//     string getBeautifulSubstring(string &s, int begin, int k)
//     {
//         int n = s.size(), count_one = 0;
//         string bss = "";
//         for (int i = begin; i < n; i++)
//         {
//             bss += s[i];
//             if (s[i] == '1')
//                 count_one++;
//             if (count_one == k)
//                 return bss;
//         }
//         return "";
//     }
//     // 辅函数 - 比较 字符串 s 和字符串 t 的字典序
//     bool compare(string &s, string &t)
//     {
//         int n = s.size();
//         for (int i = 0; i < n; i++)
//         {
//             if (s[i] > t[i])
//                 return false;
//             else if (s[i] < t[i])
//                 return true;
//         }
//         return true;
//     }
// };

// 滑动窗口

class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        // 特判
        if (count(s.begin(), s.end(), '1') < k)
            return "";
        string ans = s;
        int n = s.size();
        int left = 0, count_one = 0;
        for (int right = 0; right < n; right++)
        {
            count_one += s[right] - '0';
            while (count_one > k || s[left] == '0')
            {
                count_one -= s[left] - '0';
                left++;
            }
            if (count_one == k)
            {
                string temp = s.substr(left, right - left + 1);
                if (temp.size() < ans.size() || (temp.size() == ans.size() && temp < ans))
                    ans = move(temp);
            }
        }
        return ans;
    }
};
// @lc code=end
