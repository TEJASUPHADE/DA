#include <iostream>
using namespace std;

int customMax(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int weight[], int value[], int n) {
    if (n == 0 || W == 0)
        return 0;

    if (weight[n - 1] > W)
        return knapSack(W, weight, value, n - 1);

    return customMax(value[n - 1] + knapSack(W - weight[n - 1], weight, value, n - 1),
                     knapSack(W, weight, value, n - 1));
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number of items." << endl;
       cin >> n;
    }

    int *value = new int[n];
    int *weight = new int[n];

    cout << "Enter the item’s weight and its value:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];

        if (weight[i] <= 0 || value[i] <= 0) {
            cout << "Please enter positive values for weight and value." << endl;
           cin >> weight[i] >> value[i];
        }
    }

    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    if (W <= 0) {
        cout << "Please enter a positive capacity for the knapsack." << endl;
        cin >> W;
    }

    cout << "Maximum value in a 0-1 knapsack: " << knapSack(W, weight, value, n) << endl;

    delete[] value;
    delete[] weight;

    return 0;
}

