#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
    private:
        map<int, int> mp;
    public:
        MyCalendar() {
            
        }
        
        bool book(int s, int e) {
            mp[s]++, mp[e]--;
            int sum = 0;
            for(auto& [k,v] : mp) {
                sum += v;
                if (sum > 1) {
                    mp[s]--;
                    mp[e]++;
                    return false;
                }
            }
            return true;
        }
    };
    
    /**
     * Your MyCalendar object will be instantiated and called as such:
     * MyCalendar* obj = new MyCalendar();
     * bool param_1 = obj->book(startTime,endTime);
     */