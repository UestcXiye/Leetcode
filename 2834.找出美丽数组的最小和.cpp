/*
 * @lc app=leetcode.cn id=2834 lang=cpp
 *
 * [2834] 找出美丽数组的最小和
 */

// @lc code=start
// class Solution
// {
// private:
//     const int MOD = 1e9 + 7;

// public:
//     int minimumPossibleSum(int n, int target)
//     {
//         set<int> nums;
//         nums.insert(1);
//         int num = 2;
//         while (nums.size() < n)
//         {
//             if (!nums.count(target - num))
//                 nums.insert(num);
//             num++;
//         }
//         return accumulate(nums.begin(), nums.end(), 0LL) % MOD;
//     }
// };

class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    int minimumPossibleSum(int n, int target)
    {
        long long m = min(target / 2, n);
        return (cal(1, m) + cal(target, target + n - m - 1)) % MOD;
    }
    // 辅函数 - 返回 [left, right] 区间内元素和
    long long cal(int left, int right)
    {
        long long sum = 0;
        for (int i = left; i <= right; i++)
            sum += i;
        return sum;
    }
};
// @lc code=end
