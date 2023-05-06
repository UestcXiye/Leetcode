#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums;
    for (int i = 0; i < 10; i++)
    {
        nums.push_back(10 - i);
        nums.push_back(i);
    }
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
        s.insert(nums[i]);

    cout << (*(--s.end())) << endl;

    system("pause");
    return 0;
}
