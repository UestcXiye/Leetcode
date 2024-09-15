/*
 * @lc app=leetcode.cn id=3281 lang=cpp
 *
 * [3281] 范围内整数的最大得分
 */

// @lc code=start
class Solution
{
public:
    int maxPossibleScore(vector<int> &start, int d)
    {
        int n = start.size();
        sort(start.begin(), start.end());

        auto check = [&](int score) -> bool
        {
            long long x = LLONG_MIN;
            for (int &s : start)
            {
                x = max(x + score, (long long)s);
                if (x > s + d)
                    return false;
            }
            return true;
        };

        int left = 0, right = floor(1.0 * (start[n - 1] + d - start[0]) / (n - 1)) + 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (check(mid))
                left = mid;
            else
                right = mid;
        }
        return left;
    }
};
// @lc code=end
