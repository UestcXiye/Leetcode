/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
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
//         while (n != 1 && umap.find(n) == umap.end()) // n不为1且n不在哈希表中
//         {
//             umap.insert(pair<int, bool>(n, true));
//             n = getNext(n);
//         }
//         return n == 1;
//     }
// };
class Solution
{
public:
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
