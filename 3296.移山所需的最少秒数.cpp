/*
 * @lc app=leetcode.cn id=3296 lang=cpp
 *
 * [3296] 移山所需的最少秒数
 */

// @lc code=start
class Solution
{
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes)
    {
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
        for (int i = 0; i < workerTimes.size(); i++)
            pq.push(tuple<long long, int, int>(workerTimes[i], 1, i));

        long long ans = 0LL;
        while (mountainHeight--)
        {
            auto [cost, cnt, idx] = pq.top();
            pq.pop();
            ans = cost;

            cnt++;
            cost += (long long)cnt * workerTimes[idx];
            pq.push(tuple<long long, int, int>(cost, cnt, idx));
        }
        return ans;
    }
};
// @lc code=end
