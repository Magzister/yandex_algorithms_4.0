#include <iostream>
#include <time.h>

using namespace std;

void partition(int x, int* array, int l, int r, int *equal, int *greater) {
    int e = l, g = l;

    for (int n = l; n <= r; n++) {
        if (array[n] == x) {
            int tmp = array[n];
            array[n] = array[g];
            array[g] = tmp;
            g++;
        } else if (array[n] < x) {
            int tmp = array[n];
            array[n] = array[g];
            array[g] = array[e];
            array[e] = tmp;
            g++;
            e++;
        }
    }

    *equal = e;
    *greater = g;
}

int pivot(int* array, int l, int r) {
    int mid = (l + r) / 2;
    if (array[mid] < array[l]) {
        int tmp = array[mid];
        array[mid] = array[l];
        array[l] = tmp;
    }
    if (array[r] < array[l]) {
        int tmp = array[l];
        array[l] = array[r];
        array[r] = tmp;
    }
    if (array[mid] < array[r]) {
        int tmp = array[r];
        array[r] = array[mid];
        array[mid] = tmp;
    }
    return array[r];
}

void quick_sort(int* array, int l, int r) {
    if (l < r) {
        int ind = l + rand() % (r - l + 1);
        int x = array[ind];
        int e, g;
        partition(x, array, l, r, &e, &g);
        quick_sort(array, l, e - 1);
        quick_sort(array, g, r);
    }
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << endl;
        return 0;
    }
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    bool is_sorted = true;
    for (int i = 1; i < n; i++) {
        if (array[i - 1] > array[i]) {
            is_sorted = false;
        }
    }

    if (!is_sorted) {
        srand((unsigned)time(NULL));
        quick_sort(array, 0, n - 1);
    }

    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
