#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int get_int_from_char(char ch) {
    if (ch == '0') {
        return 0;
    } else if (ch == '1') {
        return 1;
    } else if (ch == '2') {
        return 2;
    } else if (ch == '3') {
        return 3;
    } else if (ch == '4') {
        return 4;
    } else if (ch == '5') {
        return 5;
    } else if (ch == '6') {
        return 6;
    } else if (ch == '7') {
        return 7;
    } else if (ch == '8') {
        return 8;
    } else {
        return 9;
    }
}

int main() {

    int n;
    cin >> n;
    vector<string> s;
    for (int i = 0; i < n; i++) {
        string s_i;
        cin >> s_i;
        s.push_back(s_i);
    }

    cout << "Initial array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << s[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "**********" << endl;

    map<int, vector<string>> bucket;
    int length = s[0].size();
    for (int i = length - 1; i >= 0; i--) {
        cout << "Phase " << length - i << endl;

        for (int j = 0; j < 10; j++) {
            bucket[j] = vector<string>();
        }
        for (int j = 0; j < n; j++) {
            int digit = get_int_from_char(s[j][i]);
            bucket[digit].push_back(s[j]);
        }
        int k = 0;
        for (int j = 0; j < 10; j++) {
            cout << "Bucket " << j << ": ";
            if (bucket[j].size() == 0) {
                cout << "empty" << endl;
            } else {
                for (int x = 0; x < bucket[j].size(); x++) {
                    s[k] = bucket[j][x];
                    k++;
                    cout << bucket[j][x];
                    if (x < bucket[j].size() - 1) {
                        cout << ", ";
                    }
                }
                cout << endl;
            }
        }

        cout << "**********" << endl;
    }

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << s[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << endl;


    return 0;
}
