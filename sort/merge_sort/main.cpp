#include <iostream>

using namespace std;

void merge(int* a, int l, int mid, int r, int* merge) {
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            merge[k] = a[i];
            i++;
        } else {
            merge[k] = a[j];
            j++;
        }
        k++;
    }

    if (i > mid) {
        while (j <= r) {
            merge[k] = a[j];
            k++;
            j++;
        }
    } else {
        while (i <= mid) {
            merge[k] = a[i];
            k++;
            i++;
        }
    }

    for (int i = l; i <= r; i++) {
        a[i] = merge[i];
    }
}

void merge_sort(int* a, int l, int r, int* tmp) {
    if (l < r) {
        int mid = (l + r) / 2;
        merge_sort(a, l, mid, tmp);
        merge_sort(a, mid + 1, r, tmp);
        merge(a, l, mid, r, tmp);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int tmp[n];
    merge_sort(a, 0, n - 1, tmp);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
