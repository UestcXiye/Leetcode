/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        if (tickets.empty())
            return {};
        unordered_map<string, multiset<string>> hash;
        for (vector<string> &ticket : tickets)
            hash[ticket[0]].insert(ticket[1]);
        vector<string> ans;
        stack<string> s;
        s.push("JFK");
        while (!s.empty())
        {
            string next = s.top();
            if (hash[next].empty())
            {
                ans.push_back(next);
                s.pop();
            }
            else
            {
                s.push(*(hash[next].begin()));
                hash[next].erase(hash[next].begin());
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
