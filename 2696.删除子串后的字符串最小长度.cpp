/*
 * @lc app=leetcode.cn id=2696 lang=cpp
 *
 * [2696] 删除子串后的字符串最小长度
 */

// @lc code=start

// 暴力

// class Solution
// {
// public:
//     int minLength(string s)
//     {
//         // 特判
//         if (s.empty())
//             return 0;

//         int indexOfAB = s.find("AB"), indexOfCD = s.find("CD");
//         while (indexOfAB != string::npos || indexOfCD != string::npos)
//         {
//             if (indexOfAB != string::npos)
//                 s = s.substr(0, indexOfAB) + s.substr(indexOfAB + 2);
//             indexOfCD = s.find("CD");
//             if (indexOfCD != string::npos)
//                 s = s.substr(0, indexOfCD) + s.substr(indexOfCD + 2);
//             indexOfAB = s.find("AB"), indexOfCD = s.find("CD");
//         }
//         return s.length();
//     }
// };

// 栈

class Solution
{
public:
    int minLength(string s)
    {
        // 特判
        if (s.empty())
            return 0;

        stack<char> stk;
        for (char &c : s)
        {
            if (!stk.empty() && ((c == 'B' && stk.top() == 'A') || (c == 'D' && stk.top() == 'C')))
                stk.pop();
            else
                stk.push(c);
        }
        return stk.size();
    }
};
// @lc code=end
