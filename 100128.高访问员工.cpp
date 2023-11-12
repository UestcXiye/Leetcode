/*
 * @lc app=leetcode.cn id=100128 lang=cpp
 *
 * [100128] 高访问员工
 */

// @lc code=start
class Solution
{
private:
    static const int MINUTE = 60;

public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        map<string, vector<int>> employees;
        for (const vector<string> &access_time : access_times)
        {
            string name = access_time[0];
            string time = access_time[1];
            int accessTime = MINUTE * stoi(time.substr(0, 2)) + stoi(time.substr(2));
            employees[name].push_back(accessTime);
        }
        vector<string> highAccessEmployees;
        for (auto &[name, accessTime] : employees)
        {
            sort(accessTime.begin(), accessTime.end());
            for (int i = 2; i < accessTime.size(); i++)
                if (accessTime[i] - accessTime[i - 2] < 60)
                {
                    highAccessEmployees.push_back(name);
                    break;
                }
        }
        return highAccessEmployees;
    }
};
// @lc code=end
