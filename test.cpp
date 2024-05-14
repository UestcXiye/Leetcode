#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> &vec);

int getFirstTargetIndex(vector<int> &nums, int target)
{
	if (nums.empty())
		return -1;
	int left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
		{
			if ((mid > 0 && nums[mid - 1] != target) || mid == 0)
				return mid;
			else
				right = mid - 1;
		}
		else if (nums[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

vector<int> getNxt(string &pattern)
{
	vector<int> nxt;
	// next[0] 必然是 0
	nxt.push_back(0);
	// 从 next[1] 开始求
	int x = 1, now = 0;
	while (x < pattern.length())
	{
		if (pattern[now] == pattern[x])
		{
			// 如果 pattern[now] == pattern[x]，向右拓展一位
			now++;
			x++;
			nxt.push_back(now);
		}
		else if (now != 0)
		{
			// 缩小 now，改成 nxt[now - 1]
			now = nxt[now - 1];
		}
		else
		{
			// now 已经为 0，无法再缩小，故 next[x] = 0
			nxt.push_back(0);
			x++;
		}
	}
	return nxt;
}

vector<int> kmp(string &s, string &pattern)
{
	int m = pattern.length();
	vector<int> nxt = getNxt(pattern);
	vector<int> res;
	int tar = 0; // 主串中将要匹配的位置
	int pos = 0; // 模式串中将要匹配的位置
	while (tar < s.length())
	{
		if (s[tar] == pattern[pos])
		{
			// 若两个字符相等，则 tar、pos 各进一步
			tar++;
			pos++;
		}
		else if (pos != 0)
		{
			// 失配，如果 pos != 0，则依据 nxt 移动标尺
			pos = nxt[pos - 1];
		}
		else
		{
			// pos[0] 失配，标尺右移一位
			tar++;
		}

		if (pos == pattern.length())
		{
			res.push_back(tar - pos);
			pos = nxt[pos - 1];
		}
	}
	return res;
}

bool is_equal(string &s1, string &s2)
{
	if (s1.length() != s2.length())
		return false;

	for (int i = 0; i < s1.length(); i++)
		if (s1[i] != s2[i])
			return false;
	return true;
}

vector<int> bruteForce(string &s, string &pattern)
{
	int slen = s.length(), plen = pattern.length();
	vector<int> res;
	for (int i = 0; i <= slen - plen; i++)
	{
		string tmp = s.substr(i, plen);
		if (is_equal(tmp, pattern))
			res.push_back(i);
	}
	return res;
}

void quickSort(vector<int> &arr, int begin, int end)
{
	if (begin >= end)
		return;

	int left = begin, right = end;
	// 选区间最左边的元素作为主元
	int pivot = arr[left];

	while (left < right)
	{
		while (left < right && arr[right] >= pivot)
			right--;
		// 跳出此循环，代表右指针找到了比 pivot 小的数字
		if (left < right)
			arr[left] = arr[right];

		while (left < right && arr[left] <= pivot)
			left++;
		// 跳出此循环，代表左指针找到了比 pivot 大的数字
		if (left < right)
			arr[right] = arr[left];

		// 左右指针相遇，放入 pivot
		if (left == right)
			arr[left] = pivot;
	}

	// 分治
	quickSort(arr, begin, left - 1);
	quickSort(arr, left + 1, end);
}

int main()
{
	// string s = "abdcabcabcd";
	// string pattern = "abc";
	// vector<int> ans = kmp(s, pattern);
	// PrintVector(ans);

	// vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	// quickSort(arr, 0, 10);
	// for (auto x : arr)
	// {
	// 	cout << x << " ";
	// }
	// cout << endl;

	vector<int> nums = {2, 5, 6, 8, 5};

	int n = nums.size(), k = 7;
	sort(nums.begin(), nums.end());
	int median = 0;
	if (n % 2)
		median = nums[n / 2];
	else
		median = max(nums[n / 2 - 1], nums[n / 2]);
	long long op = 0;
	op += abs(median - k);
	int i = n / 2 - 1;
	while (i >= 0 && nums[i] > k)
	{
		op += nums[i] - k;
		i--;
	}
	i = n / 2 + 1;
	while (i < n && nums[i] < k)
	{
		op += k - nums[i];
		i++;
	}
	cout << op << endl;
	system("pause");
	return 0;
}

void PrintVector(vector<int> &vec)
{
	for (int &v : vec)
		cout << v << " ";
	cout << endl;
}
