/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

// @lc code=start
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int n = people.size();
        ranges::sort(people);
        int i = 0, j = n - 1;
        int ans = 0;
        while (i <= j)
        {
            if (people[i] + people[j] <= limit)
                i++;
            j--;
            ans++;
        }
        return ans;
    }
};
// @lc code=end
