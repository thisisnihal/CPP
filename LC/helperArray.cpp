#include <bits/stdc++.h>
using namespace std;

void printArray(string s) {
    for(char c : s) {
        if (c == '[') cout << "{";
        else if (c == ']') cout << "}";
        else cout << c; 
    }
    cout << "\n";
}
int main()
{
    string s = "[[2,1,5],[7,10,0],[12,6,4]]";


    printArray(s);

    // string s1 = "[885,1445,1580,1309,205,1788,1214,1404,572,1170,989,265,153,151,1479,1180,875,276,1584]";
    // printArray(s1);
    return 0;
}