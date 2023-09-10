/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start

// 计算过程会有以下三种可能：
// 1. 最终会得到 1
// 2. 最终会进入循环
// 3. 值会越来越大，最后接近无穷大（排除）

// 用哈希集合检测循环

// class Solution
// {
// public:
//     int getNext(int n)
//     {
//         int sum = 0;
//         while (n > 0)
//         {
//             int x = n % 10;
//             sum += x * x;
//             n /= 10;
//         }
//         return sum;
//     }
//     bool isHappy(int n)
//     {
//         unordered_map<int, bool> umap;
//         while (n != 1 && umap.find(n) == umap.end()) // n 不为 1 且 n 不在哈希表中
//         {
//             umap.insert(pair<int, bool>(n, true));
//             n = getNext(n);
//         }
//         return n == 1;
//     }
// };

// 快慢指针法

class Solution
{
private:
    int getNext(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int x = n % 10;
            sum += x * x;
            n /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n)
    {
        int fast = n, slow = n;
        do
        {
            fast = getNext(getNext(fast));
            slow = getNext(slow);
        } while (fast != slow);
        return fast == 1;
    }
};
// @lc code=end
