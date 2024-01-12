#include <iostream>
using namespace std;

typedef long long ll;

uint64_t Mul(uint64_t a, uint64_t b, uint64_t mod) {
    if (b == 0) return 0;
    if (b == 1) return a % mod;
    uint64_t tmp = Mul(a, b / 2, mod) % mod;
    return (b % 2 == 0) ? (tmp + tmp) % mod : (tmp + tmp + a) % mod;
}

uint64_t Pow(uint64_t a, uint64_t b, uint64_t mod) {
    if (b == 0) return 1;
    uint64_t tmp = Pow(a, b / 2, mod) % mod;
    return (b % 2 == 1) ? ((Mul(Mul(tmp, tmp, mod) % mod, a % mod, mod)) % mod) : (Mul(tmp, tmp, mod) % mod);
}

int main() {
    uint64_t x, n, m;
    cin >> x >> n >> m;

    if (x == 1) {
        cout << (n + 1) % m;
        return 0;
    }

    uint64_t mod = (x - 1) * m;
    cout << (Pow(x, n + 1, mod) - 1) / (x - 1);
    return 0;
}
