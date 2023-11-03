#include <iostream>

using namespace std;

int partition(int x, int* array, int l, int r) {
    int e = l, g = l;

    for (int n = l; n < r; n++) {
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

    return e;
}

int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    int x;
    cin >> x;

    int p = partition(x, array, 0, n);
    cout << p << endl;
    cout << n - p << endl;

    return 0;
}
