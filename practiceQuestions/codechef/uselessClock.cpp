#include "/Users/amitabh/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int p, q, N;
        cin >> p >> q >> N; N--;
        int den = 2 * abs(p - q);
        long long num = N * q;
        long long ans = num / den + 1;
        cout << ans << "\n";
    }

    return 0;
}