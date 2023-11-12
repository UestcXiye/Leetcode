/*
 * @lc app=leetcode.cn id=100117 lang=cpp
 *
 * [100117] 最大化数组末位元素的最少操作次数
 */

// @lc code=start
class Solution
{
private:
    const int INF = 0x3f3f3f3f;

public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        function<int(int, int)> getOps = [&](int last1, int last2) -> int
        {
            int ops = 0;
            for (int i = 0; i < n - 1; i++)
            {
                int x = nums1[i], y = nums2[i];
                if (x > last1 || y > last2)
                {
                    if (y > last1 || x > last2)
                        return INF;
                    else
                        ops++;
                }
            }
            return ops;
        };
        int ans = getOps(nums1.back(), nums2.back());
        ans = min(ans, getOps(nums2.back(), nums1.back()) + 1);
        return ans >= INF ? -1 : ans;
    }
};
// @lc code=end
