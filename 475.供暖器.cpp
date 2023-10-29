/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 */

// @lc code=start
class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        int min_radius = 0;
        sort(heaters.begin(), heaters.end());
        for (const int &house : houses)
        {
            int j = upper_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            int i = j - 1;
            int left_distance = i < 0 ? __INT_MAX__ : house - heaters[i];
            int right_distance = j >= heaters.size() ? __INT_MAX__ : heaters[j] - house;
            min_radius = max(min_radius, min(left_distance, right_distance));
        }
        return min_radius;
    }
};
// @lc code=end
