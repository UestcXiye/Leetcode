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
    int a, b, ans = 0, l = 0, n;
    cin >> n >> a;               // 建立一个n，输入后面跟第一个数字，
    for (int i = 1; i <= n; i++) // for循环在未满足长度时继续循环
    {
        cin >> b;  // 输入第二个数字
        if (b < a) // 当b<a的时候，就是左坡高于b
        {
            l = 1; // 使l=1做标记
        }
        if (b > a && l == 1) // 当第二个输入的b大于a时，就是右坡高于中间
        {
            ans++;
            l = 0; // 使答案+1，标记用的l变为0
        }
        a = b; // 让a=b（就是一个重新赋值）
    }
    cout << ans; // 当全部结束后，输出可能形成水洼的个数

    system("pause");
    return 0;
}
