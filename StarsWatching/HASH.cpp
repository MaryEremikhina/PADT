#include <vector>
#include "HASH.h"

long long bin_pow(long long base, long long exp, long long mod) {
    long long res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = res * base % mod;
        }
        base = base * base % mod;
        exp /= 2;
    }
    return res;
}

std::vector<std::vector<long long>> prefHASH(std::vector<std::vector<int>> A, std::vector<int> powP1, std::vector<int> powP2) {
    std::vector<std::vector<long long>> H(A.size(), std::vector<long long>(A[0].size(), 0));

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (i == 0 && j == 0) {
                H[i][j] = A[i][j] * powP1[i] % mod * powP2[j] % mod;
            } else if (i == 0) {
                H[i][j] = (A[i][j] * powP1[i] % mod * powP2[j] % mod + H[i][j - 1]) % mod;
            } else if (j == 0) {
                H[i][j] = (A[i][j] * powP1[i] % mod * powP2[j] % mod + H[i - 1][j]) % mod;
            } else {
                H[i][j] = (A[i][j] * powP1[i] % mod * powP2[j] % mod + H[i][j - 1] + H[i - 1][j] - H[i - 1][j - 1]) % mod;
            }
        }
    }
    return H;
}

long long getHASH(std::vector<std::vector<int>> B, std::vector<int> powP1, std::vector<int> powP2) {
    long long ans = 0;
    for (int i = 0; i < B.size(); i++) {
        for (int j = 0; j < B[i].size(); j++) {
            ans += B[i][j] * powP1[i] % mod * powP2[j] % mod;
        }
    }
    return ans;
}

long long getSubHASH(int x1, int y1, int x2, int y2, std::vector<std::vector<long long>> H) {
    long long res;
    if (x1 == 0 && y1 == 0) {
        res = H[x2][y2];
    } else if (x1 == 0) {
        res = (H[x2][y2] - H[x2][y1 - 1]) % mod;
    } else if (y1 == 0) {
        res = (H[x2][y2] - H[x1 - 1][y2]) % mod;
    } else {
        res = (H[x2][y2] - H[x1 - 1][y2] - H[x2][y1 - 1] + H[x1 - 1][y1 - 1]) % mod;
    }

    res = res * bin_pow(p1, mod - 1 - x1, mod) % mod;
    res = res * bin_pow(p2, mod - 1 - y1, mod) % mod;
    return res;
}