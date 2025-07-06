#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, vector<int>& b, vector<int>& res) 
{
    int i = 0, j = 0, k = 0;

    // Merge elements from a and b into res
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            res[k++] = a[i++];
        } else {
            res[k++] = b[j++];
        }
    }
    // Copy any remaining elements from a
    while (i < a.size()) {
        res[k++] = a[i++];
    }

    // Copy any remaining elements from b
    while (j < b.size()) {
        res[k++] = b[j++];
    }
}

void mergeSort(vector<int>& v) 
{
    int n = v.size();
    if (n <= 1) return; // Base case: single element is already sorted

    int n1 = n / 2, n2 = n - n1;
    vector<int> a(n1), b(n2);

    // Split the vector into two halves
    for (int i = 0; i < n1; i++) a[i] = v[i];
    for (int i = 0; i < n2; i++) b[i] = v[i + n1];

    // Recursively sort both halves
    mergeSort(a);
    mergeSort(b);

    // Merge the sorted halves back into v
    merge(a, b, v);
}

int main() 
{
    int arr[] = {5, 1, 3, 0, 4, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + n);//to fill the vector with elements

    // Print the original array
    cout << "Original array: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Perform merge sort
    mergeSort(v);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
