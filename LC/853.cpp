#include <bits/stdc++.h>
#define ed "\n"

using namespace std;

template <typename T>
void printArray(const vector<T> &arr)
{
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << arr[i].first << ":" << arr[i].second;
        if (i != arr.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}
int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    int ans = 0;
    vector<pair<int, int>> cars;

    for (int i = 0; i < position.size(); i++)
        cars.push_back({position[i], speed[i]});

    sort(cars.begin(), cars.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
             return a.first > b.first;
             // desc order based on position
         });
    
    printArray(cars);
    cout << "time :";
    stack<double> st;
    for (auto& car : cars) {
        double time = (double)(target - car.first) / car.second; // time = dist / speed
        cout << time << ","; //

        while (st.empty() || time > st.top()) {
            st.push(time);
        }
    }
    return st.size();
}
int main()
{
    int t = 12;
    vector<int> pos, speed;
    pos = {10, 8, 0, 5, 3};
    speed = {2, 4, 1, 1, 3};
    int ans = carFleet(t, pos, speed);
    cout << "ans=" << ans << ed;
    return 0;
}
