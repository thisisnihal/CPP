#include <bits/stdc++.h>
#define ed "\n"

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

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
         ans[st.top()] = -1;
        st.pop();
    }
    for (int i = 0; i < ans.size(); i++) {
       if (ans[i] != -1) ans[i] = ans[i] - i;
       else ans[i] = 0;
    }
    return ans;
}
int main()
{
    vector<int> v = {73, 74, 75, 71, 69, 72, 76, 73};
    auto ans = dailyTemperatures(v);
    printArray(ans);
    return 0;
}

/*
Traverse from right to left.

Maintain a stack of possible greater elements.

For each element:

Pop elements from stack ≤ current.

If stack is empty → NGE = -1

Else → top of stack is the NGE

Push current element to stack
*/