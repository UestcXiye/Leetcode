#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    string s = "iiii";
    string trans;
    for (char c : s)
        trans.append(to_string((int)c - 'a' + 1));
    cout << trans << endl;

    system("pause");
    return 0;
}
