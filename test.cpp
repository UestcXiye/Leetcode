#include <iostream>
#include <sstream> //istream
using namespace std;

int main()
{
    string text = "aaa bb ccc d";
    istringstream is(text);
    string word;
    while (is >> word)
    {
        cout << word << endl;
    }
    system("pause");
    return 0;
}
