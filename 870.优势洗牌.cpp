/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start

// 贪心 + 排序 + 二分查找
//  对于任意一个 nums2[i] 而言，我们应当在候选集合中选择比其大的最小数，若不存在这样的数字，则选择候选集合中的最小值。

class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<pair<int, int>> t; //<值，下标>
        for (int i = 0; i < n; i++)
            t.push_back({nums2[i], i});
        sort(t.begin(), t.end());
        sort(nums1.begin(), nums1.end());
        int i = 0, j = n - 1;
        vector<int> ans(n);
        for (int &num : nums1)
        {
            if (num > t[i].first)
                ans[t[i++].second] = num;
            else
                ans[t[j--].second] = num;
        }
        return ans;
    }
};
// @lc code=end
