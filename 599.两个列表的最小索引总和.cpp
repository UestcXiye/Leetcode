/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> hash; //<餐厅名，索引>
        for (int i = 0; i < list1.size(); i++)
            hash[list1[i]] = i;
        int index_sum = INT_MAX;
        vector<string> ans;
        for (int i = 0; i < list2.size(); i++)
            if (hash.count(list2[i]))
            {
                if (i + hash[list2[i]] < index_sum)
                {
                    index_sum = i + hash[list2[i]];
                    ans.clear();
                    ans.push_back(list2[i]);
                }
                else if (i + hash[list2[i]] == index_sum)
                    ans.push_back(list2[i]);
            }
        return ans;
    }
};
// @lc code=end
