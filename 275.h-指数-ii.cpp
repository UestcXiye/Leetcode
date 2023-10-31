/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (citations[mid] >= n - mid)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return n - left;
    }
};
// @lc code=end
