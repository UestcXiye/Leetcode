/*
 * @lc app=leetcode.cn id=2570 lang=cpp
 *
 * [2570] 合并两个二维数组 - 求和法
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        vector<vector<int>> ans;
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            int id1 = nums1[i][0], id2 = nums2[j][0];
            if (id1 < id2)
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else if (id1 == id2)
            {
                ans.push_back({id1, nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
            else
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while (i < n1)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < n2)
        {
            ans.push_back(nums2[j]);
            j++;
        }

        return ans;
    }
};

// @lc code=end
