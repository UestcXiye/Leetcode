/*
 * @lc app=leetcode.cn id=2975 lang=cpp
 *
 * [2975] 移除栅栏得到的正方形田地的最大面积
 */

// @lc code=start
class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
    {
        // 特判
        if (m == n)
            return (long long)(m - 1) * (n - 1);
        if (hFences.empty() || vFences.empty())
            return pow(min(m, n) - 1, 2);
        // 预处理
        hFences.push_back(1), hFences.push_back(m);
        vFences.push_back(1), vFences.push_back(n);
        // 得到距离
        unordered_set<int> hDistances = calDistances(hFences);
        unordered_set<int> vDistances = calDistances(vFences);
        // 计算正方形田地的最大面积
        int max_len = 0;
        for (int h_distance : hDistances)
            if (vDistances.contains(h_distance))
                max_len = max(max_len, h_distance);
        return max_len == 0 ? -1 : (long long)max_len * max_len % MOD;
    }
    // 辅函数 - 计算任意两个栅栏之间的距离
    unordered_set<int> calDistances(vector<int> &fences)
    {
        unordered_set<int> distances;
        sort(fences.begin(), fences.end());
        for (int i = 0; i < fences.size() - 1; i++)
            for (int j = i + 1; j < fences.size(); j++)
                distances.insert(fences[j] - fences[i]);
        return distances;
    }
};
// @lc code=end
