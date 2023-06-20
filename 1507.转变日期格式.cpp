/*
 * @lc app=leetcode.cn id=1507 lang=cpp
 *
 * [1507] 转变日期格式
 */

// @lc code=start
class Solution
{
private:
    unordered_map<string, string> Months =
        {
            {"Jan", "01"},
            {"Feb", "02"},
            {"Mar", "03"},
            {"Apr", "04"},
            {"May", "05"},
            {"Jun", "06"},
            {"Jul", "07"},
            {"Aug", "08"},
            {"Sep", "09"},
            {"Oct", "10"},
            {"Nov", "11"},
            {"Dec", "12"}};

public:
    string reformatDate(string date)
    {
        stringstream ss(date);
        string year, month, day;
        ss >> day >> month >> year;
        month = Months[month];
        day.pop_back();
        day.pop_back();
        if (day.size() == 1)
            day = "0" + day;
        return year + "-" + month + "-" + day;
    }
};
// @lc code=end
