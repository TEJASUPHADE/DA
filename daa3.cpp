#include <iostream>
#include <algorithm>
#include <stdexcept> // Include this for exception handling
using namespace std;

// Structure to represent an item with its weight and value
struct Item {
    double weight; // Change to double for accepting float numbers
    double value;  // Change to double for accepting float numbers
};

// Function to compare items based on their value per weight ratio in descending order
bool compareItems(Item a, Item b) {
    double ratio_a = a.value / a.weight;
    double ratio_b = b.value / b.weight;
    return ratio_a > ratio_b;
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(double capacity, Item items[], int n) {
    if (capacity <= 0) {
        throw invalid_argument("Capacity should be a positive number.");
    }

    // Sort items in non-increasing order of value per weight ratio
    sort(items, items + n, compareItems);
    double totalValue = 0.0;
    double currentWeight = 0.0;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= 0 || items[i].value <= 0) {
            throw invalid_argument("Weight and value of items should be positive numbers.");
        }

        if (currentWeight + items[i].weight <= capacity) {
            // If the entire item can be added, add it to the knapsack
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Otherwise, add a fraction of the item to fill the capacity
            double remainingCapacity = capacity - currentWeight;
            double fraction = remainingCapacity / items[i].weight;
            totalValue += fraction * items[i].value;
            break; // The knapsack is now full, so we break out of the loop
        }
    }
    return totalValue;
}

int main() {
    double capacity; // Change to double for accepting float numbers
    int n;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> capacity;
    if (capacity <= 0) {
        cout << "Capacity should be a positive number. Exiting the program." << endl;
        cout<<"Enter capacity ";
        cin>>capacity;
    }
    cout << "Enter the number of items: ";
    cin >> n;

    Item items[n];
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " weight: ";
        cin >> items[i].weight;
        if (items[i].weight <= 0) {
            cout << "Weight of item must be a positive number. Please enter again: ";
            cin >> items[i].weight;
        }

        cout << "Item " << i + 1 << " value: ";
        cin >> items[i].value;
        if (items[i].value <= 0) {
            cout << "Value of item must be a positive number. Please enter again: ";
            cin >> items[i].value;
        }
    }

   
        double maxValue = fractionalKnapsack(capacity, items, n);
        cout << "The maximum value that can be obtained is: " << maxValue << endl;

   
    

    return 0;
}

