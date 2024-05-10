/*
 * @lc app=leetcode.cn id=319 lang=cpp
 *
 * [319] 灯泡开关
 */

// @lc code=start

// TLE

// class Solution
// {
// public:
//     int bulbSwitch(int n)
//     {
//         if (n == 0)
//             return 0;
//         if (n <= 3)
//             return 1;
//         vector<bool> lights(n, true);
//         for (int round = 2; round <= n; round++)
//         {
//             int idx = -1, gap = round;
//             while (idx < n - gap)
//             {
//                 idx += gap;
//                 lights[idx] = !lights[idx];
//             }
//         }
//         return accumulate(lights.begin(), lights.end(), 0);
//     }
// };

// TLE

// class Solution
// {
// public:
//     int bulbSwitch(int n)
//     {
//         if (n == 0)
//             return 0;

//         int ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             int cnt = 0;
//             for (int round = 1; round <= n; round++)
//                 if ((i + 1) % round == 0)
//                     cnt++;
//             if (cnt % 2 == 1)
//                 ans++;
//         }
//         return ans;
//     }
// };

// 数学

class Solution
{
public:
    int bulbSwitch(int n)
    {
        if (n == 0)
            return 0;
        // 对于第 k 个灯泡，它被切换的次数恰好就是 k 的约数个数
        // 如果 k 有偶数个约数，那么最终第 k 个灯泡的状态为暗
        // 如果 k 有奇数个约数，那么最终第 k 个灯泡的状态为亮
        // 只有当 k 是「完全平方数」时，它才会有奇数个约数
        // [1,n] 中的完全平方数的个数为 ⌊sqrt(n)⌋
        return floor(sqrt(1.0 * n));
    }
};
// @lc code=end
