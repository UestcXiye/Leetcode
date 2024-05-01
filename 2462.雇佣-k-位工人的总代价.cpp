/*
 * @lc app=leetcode.cn id=2462 lang=cpp
 *
 * [2462] 雇佣 K 位工人的总代价
 */

// @lc code=start
class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        int n = costs.size();
        if (2 * candidates + k > n)
        {
            ranges::sort(costs);
            return accumulate(costs.begin(), costs.begin() + k, 0LL);
        }
        priority_queue<int, vector<int>, greater<>> pre, suf;
        for (int i = 0; i < candidates; i++)
        {
            pre.push(costs[i]);
            suf.push(costs[n - 1 - i]);
        }

        long long ans = 0LL;
        int i = candidates, j = n - 1 - candidates;
        while (k--)
        {
            // 如果有多位代价相同且最小的工人，选择下标更小的一位工人
            if (pre.top() <= suf.top())
            {
                ans += pre.top();
                pre.pop();
                pre.push(costs[i]);
                i++;
            }
            else
            {
                ans += suf.top();
                suf.pop();
                suf.push(costs[j]);
                j--;
            }
        }
        return ans;
    }
};
// @lc code=end
