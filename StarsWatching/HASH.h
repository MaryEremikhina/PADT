#include <vector>
#ifndef HASH_H
#define HASH_H

inline int p1 = 31;
inline int p2 = 37;
inline int mod = 1e9 + 7;

long long bin_pow(long long base, long long exp, long long mod);
std::vector<std::vector<long long>> prefHASH(std::vector<std::vector<int>> A, std::vector<int> powP1, std::vector<int> powP2);
long long getHASH(std::vector<std::vector<int>> B, std::vector<int> powP1, std::vector<int> powP2);
long long getSubHASH(int x1, int y1, int x2, int y2, std::vector<std::vector<long long>> H);

#endif //HASH_H
