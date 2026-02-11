#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

// Function to generate random numbers
void randGen(vector<int> &arr, int n) {
    srand(time(0));
    arr.clear();
    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 100); // Random numbers between 0-99
    }
    cout << "Random array generated.\n";
}

// Function to print the array
void print(const vector<int> &arr) {
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}

//Insertion Sort
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    cout << "Array sorted using Insertion Sort.\n";
}

//Merge Sort
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

//Quick Sort
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//Heap Sort
void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    cout << "Array sorted using Heap Sort.\n";
}

//Radix Sort
int getMax(vector<int> &arr) {
    int mx = arr[0];
    for (int x : arr)
        if (x > mx) mx = x;
    return mx;
}

void countSort(vector<int> &arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int> &arr) {
    int m = getMax(arr);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
    cout << "Array sorted using Radix Sort.\n";
}

int main() {
    vector<int> arr;
    int n, choice;
    cout << "Enter number of elements: ";
    cin >> n;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Generate Random Numbers\n";
        cout << "2. Print Array\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Heap Sort\n";
        cout << "7. Radix Sort\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: randGen(arr, n); break;
            case 2: print(arr); break;
            case 3: insertionSort(arr); break;
            case 4: mergeSort(arr, 0, arr.size() - 1); cout << "Array sorted using Merge Sort.\n"; break;
            case 5: quickSort(arr, 0, arr.size() - 1); cout << "Array sorted using Quick Sort.\n"; break;
            case 6: heapSort(arr); break;
            case 7: radixSort(arr); break;
            case 8: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}
