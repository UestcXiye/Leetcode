/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        if (n % 3 == 0)
            return isPowerOfThree(n / 3);
        else
            return false;
    }
};

// class Solution
// {
// public:
//     bool isPowerOfThree(int n)
//     {
//         vector<int> nums;
//         for (int i = 0; i <= 19; i++)
//             nums.push_back(pow(3, i));
//         return count(nums.begin(), nums.end(), n);
//     }
// };

// class Solution
// {
// public:
//     bool isPowerOfThree(int n)
//     {
//         return n > 0 && (int)pow(3, 19) % n == 0;
//     }
// };
// @lc code=end
