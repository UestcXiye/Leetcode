/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start

// 优先队列

// class Solution
// {
// private:
//     const vector<int> factors = {2, 3, 5};

// public:
//     int nthUglyNumber(int n)
//     {
//         if (n <= 0)
//             return 0;
//         // 小根堆，最小值在堆顶
//         priority_queue<long, vector<long>, greater<long>> minHeap;
//         unordered_set<long> res;
//         // 1 是第一个丑数
//         int ans = 0;
//         res.insert(1L);
//         minHeap.push(1L);
//         for (int i = 0; i < n; i++)
//         {
//             long curUglyNumber = minHeap.top();
//             ans = (int)curUglyNumber;
//             minHeap.pop();
//             for (const int factor : factors)
//             {
//                 long nextUglyNumber = curUglyNumber * factor;
//                 if (!res.count(nextUglyNumber))
//                 {
//                     res.insert(nextUglyNumber);
//                     minHeap.push(nextUglyNumber);
//                 }
//             }
//         }
//         return ans;
//     }
// };

// 三路归并

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n <= 0)
            return 0;
        vector<int> res(1, 1);
        int p2 = 0, p3 = 0, p5 = 0;
        while (res.size() < n)
        {
            int t = min(2 * res[p2], min(3 * res[p3], 5 * res[p5]));
            res.emplace_back(t);
            if (2 * res[p2] == t)
                p2++;
            if (3 * res[p3] == t)
                p3++;
            if (5 * res[p5] == t)
                p5++;
        }
        return res.back();
    }
};
// @lc code=end
