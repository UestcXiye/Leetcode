#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    char *string1 = "ae";
    char *string2 = "aae";

    int length;
    length = strspn(string1, string2);
    cout << "character where strings differ is at position: " << length << endl;
    system("pause");
    return 0;
}
