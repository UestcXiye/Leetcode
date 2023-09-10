/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start

// Time Limit Exceeded

// class Solution
// {
// private:
//     bool isPrime(int x)
//     {
//         for (int i = 2; i < x; i++)
//             if (x % i == 0)
//                 return false;
//         return true;
//     }

// public:
//     int countPrimes(int n)
//     {
//         if (n <= 2)
//             return 0;
//         int count = 0;
//         for (int i = 2; i < n; i++)
//             if (isPrime(i))
//                 count++;
//         return count;
//     }
// };

// 埃拉托斯特尼筛法

class Solution
{
public:
    int countPrimes(int n)
    {
        // 特判
        if (n <= 2)
            return 0;
        vector<bool> prime(n, true);
        int count = n - 2;
        // 从2到n遍历，假设当前遍历到m，则把所有小于n的、且是m 的倍数的整数标为和数
        for (int i = 2; i < n; i++)
            if (prime[i] == true)
                for (int j = 2 * i; j < n; j += i)
                    if (prime[j] == true)
                    {
                        prime[j] = false;
                        count--;
                    }
        // 遍历完成后，没有被标为和数的数字即为质数
        return count;
    }
};

// 埃拉托斯特尼筛法-优化

// class Solution
// {
// public:
//     int countPrimes(int n)
//     {
//         // 特判
//         if (n <= 2)
//             return 0;
//         vector<bool> prime(n, true);
//         int i = 3, count = n / 2; // 偶数一定不是质数
//         while (i <= sqrt(n))
//         {
//             // 最小质因子一定小于等于开方数
//             for (int j = i * i; j < n; j += 2 * i)
//             {
//                 // 避免偶数和重复遍历
//                 if (prime[j] == true)
//                 {
//                     prime[j] = false;
//                     count--;
//                 }
//             }
//             // 避免偶数和重复遍历
//             do
//             {
//                 i += 2;
//             } while (i <= sqrt(n) && prime[i] == false);
//         }
//         return count;
//     }
// };
// @lc code=end
