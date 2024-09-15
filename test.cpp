#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;

// 截取 Times 中的日期
string getDateFromTimesLine(string &input)
{
	size_t startPos = input.find('[');
	if (startPos == string::npos)
		return "";
	size_t endPos = input.find(' ', startPos);
	if (endPos == string::npos)
		return input.substr(startPos);
	return input.substr(startPos + 1, endPos - startPos - 1);
}
// 截取 Data 中的日期
string getDateFromDataLine(string &input)
{
	size_t startPos = input.find('[');
	if (startPos == string::npos)
		return "";
	size_t endPos = input.find('.', startPos);
	if (endPos == string::npos)
		return input.substr(startPos);
	return input.substr(startPos + 2, endPos - startPos - 1);
}

class Solution
{
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 * 增量转全量
	 * @param lines string字符串vector
	 * @return string字符串vector
	 */
	vector<string> convert(vector<string> &lines)
	{
		// write code here
		if (lines.size() % 8 != 0)
			return {};
		int n = lines.size() / 8;
		double last_vol = -1.0;
		vector<string> results;
		for (int i = 0; i < n; i++)
		{
			vector<string> fields = getFields(getFieldsString(lines[i * 8 + 5]), ',');
			vector<string> data = getData(getDataString(lines[i * 8 + 7]), ',');

			int date_idx = getDateIndex(fields);
			if (getDateFromTimesLine(lines[i * 8 + 6]) != getDateWithoutPoint(
															  data[date_idx]))
				continue;

			int vol_idx = getVolIndex(fields);
			if (stod(data[vol_idx]) < last_vol)
				continue;

			last_vol = stod(data[vol_idx]);
			string res;
			res += lines[i * 8 + 6].substr(lines[i * 8 + 6].find('=') + 1);
			res += ("[CODE=" + getCodesFromCodesLine(lines[i * 8 + 4]) + "]");
			for (int j = 0; j < fields.size(); j++)
			{
				res += "[" + fields[j] + "=" + data[j] + "]";
			}
			results.push_back(res);
		}
		return results;
	}
	vector<string> getFields(const string &s, char c)
	{
		vector<string> result;
		istringstream stream(s);
		string token;
		while (std::getline(stream, token, c))
		{
			result.push_back(token);
		}
		return result;
	}
	// 截取 Fields 字符串
	string getFieldsString(string &input)
	{
		size_t startPos = input.find('[');
		if (startPos == string::npos)
			return "";
		size_t endPos = input.find(']', startPos);
		if (endPos == string::npos)
			return input.substr(startPos);
		return input.substr(startPos + 1, endPos - startPos - 1);
	}
	vector<string> getData(const string &s, char c)
	{
		vector<string> result;
		istringstream stream(s);
		string token;
		while (std::getline(stream, token, c))
		{
			int len = token.length();
			result.push_back(token.substr(1, len - 2));
		}
		return result;
	}
	// 截取 Data 字符串
	string getDataString(string &input)
	{
		int len = input.length();
		return input.substr(9, len - 10);
	}
	int getDateIndex(vector<string> &fields)
	{
		int date_idx = -1;
		for (int i = 0; i < fields.size(); i++)
			if (fields[i] == "RT_DATE")
			{
				date_idx = i;
				break;
			}
		return date_idx;
	}
	int getVolIndex(vector<string> &fields)
	{
		int date_idx = -1;
		for (int i = 0; i < fields.size(); i++)
			if (fields[i] == "RT_VOL")
			{
				date_idx = i;
				break;
			}
		return date_idx;
	}
	// 截取 Times 中的日期
	string getDateFromTimesLine(string &input)
	{
		size_t startPos = input.find('[');
		if (startPos == string::npos)
			return "";
		size_t endPos = input.find(' ', startPos);
		if (endPos == string::npos)
			return input.substr(startPos);
		return input.substr(startPos + 1, endPos - startPos - 1);
	}
	// 截取 Data 中的日期的整数部分
	string getDateWithoutPoint(string &input)
	{
		size_t startPos = 0;
		size_t endPos = input.find('.', startPos);
		if (endPos == string::npos)
			return input.substr(startPos);
		return input.substr(startPos, endPos - startPos - 1);
	}
	// 截取 Codes
	string getCodesFromCodesLine(string &input)
	{
		size_t startPos = input.find('[');
		if (startPos == string::npos)
			return "";
		size_t endPos = input.find(']', startPos);
		if (endPos == string::npos)
			return input.substr(startPos);
		return input.substr(startPos + 1, endPos - startPos - 1);
	}
};

int main()
{
	string s1 = "example[substring data]";
	string s2 = ".Data=[[]]" cout << getDateFromTimesLine(s1) << endl;
	;

	system("pause");
	return 0;
}
