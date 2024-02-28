/*
 * @lc app=leetcode.cn id=3048 lang=cpp
 *
 * [3048] 标记所有下标的最早秒数 I
 */

// @lc code=start
class Solution
{
public:
    int earliestSecondToMarkIndices(vector<int> &nums, vector<int> &changeIndices)
    {
        int n = nums.size(), m = changeIndices.size();
        if (n > m)
            return -1;

        vector<int> last_t(n);
        auto check = [&](int mx) -> bool
        {
            ranges::fill(last_t, -1);
            for (int t = 0; t < mx; t++)
            {
                last_t[changeIndices[t] - 1] = t;
            }
            if (ranges::find(last_t, -1) != last_t.end())
            { // 有课程没有考试时间
                return false;
            }

            int cnt = 0;
            for (int i = 0; i < mx; i++)
            {
                int idx = changeIndices[i] - 1;
                if (i == last_t[idx])
                { // 考试
                    if (nums[idx] > cnt)
                    { // 没时间复习
                        return false;
                    }
                    cnt -= nums[idx]; // 复习这门课程
                }
                else
                { // 留着后面用
                    cnt++;
                }
            }
            return true;
        };

        int left = n - 1, right = m + 1;
        while (left + 1 < right)
        {
            int mid = (left + right) / 2;
            if (check(mid))
                right = mid;
            else
                left = mid;
        }
        return right > m ? -1 : right;
    }
};
// @lc code=end
