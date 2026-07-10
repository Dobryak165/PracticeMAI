// Задача C - Хороводоводы

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long factorial = 1;
    for (int i = 2; i <= N - 1; ++i) {
        factorial = factorial * i % MOD;
    }

    long long answer = factorial * ((MOD+1) / 2) % MOD;

    cout << answer << '\n';
    return 0;
}
