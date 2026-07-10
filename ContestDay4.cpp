// Задача B - Максимумы

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    long long answer = 0;
    for (int i = 0; i < N; ++i) {
        int maximum = a[i];
        for (int j = i; j < N; ++j) {
            if (a[j] > maximum) maximum = a[j];
            answer += maximum;
        }
    }

    cout << answer << '\n';
    return 0;
}