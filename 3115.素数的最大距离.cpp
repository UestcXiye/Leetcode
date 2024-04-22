/*
 * @lc app=leetcode.cn id=3115 lang=cpp
 *
 * [3115] 素数的最大距离
 */

// @lc code=start

// 双指针

class Solution
{
private:
    bool isPrime(int x)
    {
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
                return false;
        return x != 1;
    }

public:
    int maximumPrimeDifference(vector<int> &nums)
    {
        int n = nums.size();
        int leftPrimeIdx = 0, rightPrimeIdx = n - 1;
        while (leftPrimeIdx < n && !isPrime(nums[leftPrimeIdx]))
            leftPrimeIdx++;
        while (rightPrimeIdx >= 0 && !isPrime(nums[rightPrimeIdx]))
            rightPrimeIdx--;
        return rightPrimeIdx - leftPrimeIdx;
    }
};
// @lc code=end
