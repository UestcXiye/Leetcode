/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start

// Time Limit Exceeded

// class Solution
// {
// private:
//     bool isPalindrome(string s)
//     {
//         string rev = string(s.rbegin(), s.rend());
//         return rev == s;
//     }

// public:
//     int countSubstrings(string s)
//     {
//         int n = s.size();
//         int count = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int len = 1; len <= n - i; len++)
//             {
//                 string temp = s.substr(i, len);
//                 if (isPalindrome(temp))
//                     count++;
//             }
//         }
//         return count;
//     }
// };

// 中心拓展
// 枚举每一个可能的回文中心，然后用两个指针分别向左右两边拓展，当两个指针指向的元素相同的时候就拓展，否则停止拓展。

class Solution
{
public:
    int countSubstrings(string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            count += extendSubstrings(s, i, i);     // 奇数长度
            count += extendSubstrings(s, i, i + 1); // 偶数长度
        }
        return count;
    }
    // 辅函数
    int extendSubstrings(string s, int l, int r)
    {
        int count = 0;
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            l--;
            r++;
            count++;
        }
        return count;
    }
};
// @lc code=end
