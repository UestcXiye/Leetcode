/*
 * @lc app=leetcode.cn id=2829 lang=cpp
 *
 * [2829] k-avoiding 数组的最小总和
 */

// @lc code=start

// 贪心 + 哈希

class Solution
{
public:
    int minimumSum(int n, int k)
    {
        unordered_set<int> visited;
        int sum = 0;
        for (int x = 1; x <= 2 * n; x++)
        {
            if (!visited.count(k - x))
            {
                sum += x;
                visited.insert(x);
                if (visited.size() == n)
                    break;
            }
        }
        return sum;
    }
};

// 数学

// class Solution
// {
// public:
//     int minimumSum(int n, int k)
//     {
//         int m = min(k / 2, n);
//         return (m * (m + 1) + (k * 2 + n - m - 1) * (n - m)) / 2;
//     }
// };

// @lc code=end
