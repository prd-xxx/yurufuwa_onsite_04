#include <string>
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if (s[1] == 'u' && s[3] == 'u' && s[5] == 'u' && s[7] == 'a')
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}