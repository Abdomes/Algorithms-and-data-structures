#include <iostream>
#include <string>
#include <vector>

using namespace std;

size_t Manaken(const string& str, int isEven) {
    size_t count = 0;
    vector<int> d(str.size());
    int l = 0, r = -1;
    for (int i = 0; i < str.size(); ++i) {
        d[i] = (i > r ? 0 : min(d[l + r - i + isEven], r - i + isEven)) + 1;
        while (i - d[i] >= 0 && i + d[i] - isEven < str.size() && str[i - d[i]] == str[i + d[i] - isEven]) ++d[i];
        count += --d[i];
        if (i + d[i] - isEven > r) {
            l = i - d[i];
            r = i + d[i] - isEven;
        }
    }
    return count;
}

int main() {
    string str;
    cin >> str;
    cout << Manaken(str, 1) + Manaken(str, 0) << endl;
    return 0;
}
