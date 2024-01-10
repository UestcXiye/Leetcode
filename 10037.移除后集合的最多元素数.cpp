/*
 * @lc app=leetcode.cn id=10037 lang=cpp
 *
 * [10037] 移除后集合的最多元素数
 */

// @lc code=start

// 贪心

class Solution
{
public:
    int maximumSetSize(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        unordered_set<int> set1, set2;
        for (int &x : nums1)
            set1.insert(x);
        for (int &x : nums2)
            set2.insert(x);
        int common = 0; // 两个数组共有的元素个数
        for (int x : set1)
            if (set2.count(x))
                common++;
        // count1 和 count2 分别为数组 nums1 和 nums2 独有元素的个数
        int count1 = set1.size() - common, count2 = set2.size() - common;
        // 贪心策略：先选二者独有的，没得选才选二者共有的
        int s1 = min(count1, n / 2), s2 = min(count2, n / 2);
        return s1 + s2 + min(n - s1 - s2, common);
    }
};
// @lc code=end
