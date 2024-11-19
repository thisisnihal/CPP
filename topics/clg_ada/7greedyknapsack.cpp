#include <bits/stdc++.h>
using namespace std;

struct Item {
    int profit, weight;
    Item(int p, int w) : profit(p), weight(w) {}

    double ratio() const {
        return (profit * 1.0) / weight;
    }
};

void greedyKnapsack(int n, vector<Item>& items, int maxCapacity) {
    
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio() > b.ratio();
    });

    double maxProfit = 0.0;
    vector<double> solution(n, 0);
    int currentWeight = 0;

    for (int i = 0; i < n; ++i) {
        if (currentWeight + items[i].weight <= maxCapacity) {
            solution[i] = 1;
            currentWeight += items[i].weight;
            maxProfit += items[i].profit;
        } else {
            solution[i] = (maxCapacity - currentWeight) * 1.0 / items[i].weight;
            maxProfit += solution[i] * items[i].profit;
            break;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Optimal solution for greedy method: " << maxProfit << "\n";
    cout << "Solution vector for greedy method: ";
    for (double x : solution) {
        cout << setw(5) << x << "\t"; // Adjust width as needed
    }
    cout << endl;
}

int main() {
    int n, maxCapacity;
    cout << "Enter the number of objects: ";
    cin >> n;
    vector<Item> items;

    cout << "Enter the objects' weights: ";
    for (int i = 0; i < n; ++i) {
        int weight;
        cin >> weight;
        items.push_back(Item(0, weight));
    }

    cout << "Enter the objects' profits: ";
    for (int i = 0; i < n; ++i) {
        int profit;
        cin >> profit;
        items[i].profit = profit;
    }

    cout << "Enter the maximum capacity: ";
    cin >> maxCapacity;

    greedyKnapsack(n, items, maxCapacity);

    return 0;
}
