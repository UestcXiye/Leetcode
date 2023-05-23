/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution
{
private:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        int n = people.size();
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> queue;
        for (const vector<int> &person : people)
        {
            int pos = person[1];
            queue.insert(queue.begin() + pos, person);
        }
        return queue;
    }
};
// @lc code=end
