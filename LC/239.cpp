#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define ulld unsigned long long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

using namespace std;

template <typename T>
void printArray(const vector<T> &arr)
{
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

template <typename T>
void printDeque(const deque<T> &dq)
{
    cout << "Deque (front -> back): [";
    for (size_t i = 0; i < dq.size(); ++i)
    {
        cout << dq[i];
        if (i != dq.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;

    deque<int> dq; // store indices of elements such the elements are in
                   // monotonically decreasing order

    for (int head = 0; head < nums.size(); ++head)
    {

        // remove elements smaller than current from back
        while (!dq.empty() && nums[head] >= nums[dq.back()])
        {
            dq.pop_back();
        }

        // add current index to the back
        dq.push_back(head);

        // Remove front if it is out of the current window
        if (!dq.empty() && dq.front() <= head - k)
        {
            dq.pop_front();
        }

        // if window has formed, add max to result
        // this condition is basically for time until it reaches the sufficient window size
        if (head >= k - 1)
        {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}
int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);
    printArray(ans);
}
