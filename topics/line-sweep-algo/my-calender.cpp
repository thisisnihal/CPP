#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-09-11 15:01:17 */
using namespace std;

class MyCalendarTwo
{
private:
    map<int, int> mp;

public:
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        mp[start]++, mp[end]--;
        int sum = 0;
        for (pair<int,int> pr : mp)
        {
            sum += pr.second;
            if (sum > 2)
            {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

int main()
{
    MyCalendarTwo* myCalendarTwo = new MyCalendarTwo();
    bool b1 = myCalendarTwo->book(10, 20);
    bool b2 = myCalendarTwo->book(50, 60);
    bool b3 = myCalendarTwo->book(10, 40);
    bool b4 = myCalendarTwo->book(5, 15);
    bool b5 = myCalendarTwo->book(5, 10);
    bool b6 = myCalendarTwo->book(25, 55);
    cout << b1 << " " << b2 << " " << b3 << " " << b4 << " " << b5 << " " << b6 << " \n";
    return 0;
}