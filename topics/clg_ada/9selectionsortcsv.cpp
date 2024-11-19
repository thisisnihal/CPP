#include <bits/stdc++.h>
using namespace std;

// Function to perform selection sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    ofstream fptr("selection_sort_results.csv");
    if (!fptr) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    fptr << "Number of Elements,Time Taken (seconds)\n";
    srand(time(nullptr));

    for (int n = 5000; n <= 50000; n += 5000) {
        vector<int> arr(n);
        for (int& elem : arr)
            elem = rand();

        clock_t start = clock();
        selectionSort(arr);
        clock_t end = clock();

        double cpu_time_used = (end - start) * 1.0 / CLOCKS_PER_SEC;
        cout << "Time taken to sort " << n << " elements: " << cpu_time_used << " seconds" << endl;
        fptr << n << ',' << cpu_time_used << '\n';
    }

    return 0;
}
