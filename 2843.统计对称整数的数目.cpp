/*
 * @lc app=leetcode.cn id=2843 lang=cpp
 *
 * [2843] 统计对称整数的数目
 */

// @lc code=start
// class Solution
// {
// public:
//     int countSymmetricIntegers(int low, int high)
//     {
//         int count = 0;
//         for (int num = low; num <= high; num++)
//             if (check(num))
//                 count++;
//         return count;
//     }
//     // 辅函数 - 判断 x 是不是一个对称整数
//     bool check(int x)
//     {
//         vector<int> digits;
//         while (x)
//         {
//             digits.push_back(x % 10);
//             x /= 10;
//         }
//         if (digits.size() % 2 == 1)
//             return false;
//         int sum = 0;
//         for (int i = 0; i < digits.size() / 2; i++)
//             sum += digits[i];
//         for (int i = digits.size() / 2; i < digits.size(); i++)
//             sum -= digits[i];
//         return sum == 0;
//     }
// };

class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        int count = 0;
        for (int num = low; num <= high; num++)
        {
            string s = to_string(num);
            if (s.size() % 2 == 0 && accumulate(s.begin(), s.begin() + s.size() / 2, 0) == accumulate(s.begin() + s.size() / 2, s.end(), 0))
                count++;
        }
        return count;
    }
};
// @lc code=end
