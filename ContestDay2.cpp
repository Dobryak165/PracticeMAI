// Задача A - Никогда не играйте с незнакомцами

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    bool ok = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i-1] + 1) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Deck looks good" : "Scammed") << '\n';
    return 0;

}