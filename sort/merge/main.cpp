#include <iostream>

using namespace std;

void merge(int *a, int size_a, int *b, int size_b, int *merge) {
    int i = 0, j = 0, k = 0;
    while (i < size_a && j < size_b) {
        if (a[i] <= b[j]) {
            merge[k] = a[i];
            i++;
        } else {
            merge[k] = b[j];
            j++;
        }
        k++;
    }

    if (i == size_a) {
        while (j < size_b) {
            merge[k] = b[j];
            k++;
            j++;
        }
    } else {
        while (i < size_a) {
            merge[k] = a[i];
            k++;
            i++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int result[n + m];
    merge(a, n, b, m, result);
    for (int i = 0; i < n + m; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
