//Write a program for analysis of quick sort by using deterministic and randomized variant their time and space complexity.
#include <iostream>
#include <cstdlib>

using namespace std;
//dqs- deterministic quick sort
//rqs-randomized quick sort

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void dqs(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        dqs(arr, low, pi - 1);
        dqs(arr, pi + 1, high);
    }
}

void rqs(int arr[], int low, int high) {
    if (low < high) {
        int random = (low + high)/2;
        swap(arr[random], arr[high]);

        int pi = partition(arr, low, high);
        rqs(arr, low, pi - 1);
        rqs(arr, pi + 1, high);
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int deterministic_sorted[n];
    for (int i = 0; i < n; i++) {
        deterministic_sorted[i] = arr[i];
    }
    dqs(deterministic_sorted, 0, n - 1);

    int randomized_sorted[n];
    for (int i = 0; i < n; i++) {
        randomized_sorted[i] = arr[i];
    }
    rqs(randomized_sorted, 0, n - 1);

    cout << "Deterministic Quick Sort Result:" << endl;
    for (int i = 0; i < n; i++) {
        cout << deterministic_sorted[i] << " ";
    }
    cout << endl;

    cout << "Randomized Quick Sort Result:" << endl;
    for (int i = 0; i < n; i++) {
        cout << randomized_sorted[i] << " ";
    }
    cout << endl;

    return 0;
}
