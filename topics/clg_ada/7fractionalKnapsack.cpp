#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int profit, weight;

    Item(int profit, int weight) : profit(profit), weight(weight) {}

    // Function to calculate the profit-to-weight ratio
    double ratio() const
    {
        return (profit * 1.0) / weight;
    }
};

// Main greedy function to solve the fractional knapsack problem
double fractionalKnapsack(int W, vector<Item> &arr)
{
    // Sorting items based on the ratio of profit/weight in descending order
    sort(arr.begin(), arr.end(), [](const Item &a, const Item &b)
         { return a.ratio() > b.ratio(); });

    double finalvalue = 0.0;

    for (const Item &item : arr)
    {
        if (item.weight <= W)
        {
            W -= item.weight;
            finalvalue += item.profit;
        }
        else
        {
            finalvalue += item.profit * (W * 1.0 / item.weight);
            break;
        }
    }

    return finalvalue;
}

// Driver code
int main()
{
    int W = 50;
    vector<Item> arr = {{60, 10}, {100, 20}, {120, 30}};

    // Function call
    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, arr) << endl;
    return 0;
}
