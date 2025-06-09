#include <iostream>
#include <fstream>
#include <vector>

#include "HASH.h"

// int p1 = 31;
// int p2 = 37;
// int mod = 1e9 + 7;

std::vector<std::vector<int>> TransformPerson(std::vector<std::vector<int>> B) {
    if (B.size() < 2) {
        return B;
    }
    std::vector<std::vector<int>> resultMatrix(B.size() + 2, std::vector<int>(B.size() + 2, 0));

    for (int i = 0; i < B.size(); ++i) {
        for (int j = 0; j < B[0].size(); ++j) {
            int value = B[i][j];

            bool isTop = (i == 0);
            bool isBottom = (i == B.size() - 1);
            bool isLeft = (j == 0);
            bool isRight = (j == B.size() - 1);

            // Внутренние элементы
            if (!isTop && !isBottom && !isLeft && !isRight) {
                resultMatrix[i + 1][j + 1] = value;
            }
            // Угловые элементы
            else if (isTop && isLeft) {
                resultMatrix[0][1] = value;
                resultMatrix[1][0] = value;
            } else if (isTop && isRight) {
                resultMatrix[0][B.size()] = value;
                resultMatrix[1][B.size() + 1] = value;
            } else if (isBottom && isLeft) {
                resultMatrix[B.size()][0] = value;
                resultMatrix[B.size() + 1][1] = value;
            } else if (isBottom && isRight) {
                resultMatrix[B.size()][B.size() + 1] = value;
                resultMatrix[B.size() + 1][B.size()] = value;
            }
            else if (isTop) {
                resultMatrix[0][j + 1] = value;
            } else if (isBottom) {
                resultMatrix[B.size() + 1][j + 1] = value;
            } else if (isLeft) {
                resultMatrix[i + 1][0] = value;
            } else if (isRight) {
                resultMatrix[i + 1][B.size() + 1] = value;
            }
        }
    }
    return resultMatrix;
}

std::vector<std::vector<int>> getMatrixStar() {
    std::ifstream fA("../StarMap.txt");
    if (!fA) {
        std::cerr << "Не удалось открыть файл для чтения!" << std::endl;
    }
    int colA, rowA;
    fA >> colA >> rowA;
    std::vector<std::vector<int>> A(colA, std::vector<int>(rowA, 0));
    for (int i = 0; i < colA; i++) {
        for (int j = 0; j < rowA; j++) {
            fA >> A[i][j];
        }
    }
    fA.close();
    return A;
}

std::vector<std::vector<int>> getMatrixPerson() {
    std::ifstream fB("../PersonView.txt");
    if (!fB) {
        std::cerr << "Не удалось открыть файл для чтения!" << std::endl;
    }
    int colB, rowB;
    fB >> colB >> rowB;
    std::vector<std::vector<int>> B(colB, std::vector<int>(rowB, 0));
    for (int i = 0; i < colB; i++) {
        for (int j = 0; j < rowB; j++) {
            fB >> B[i][j];
        }
    }
    fB.close();

    return B;
}

// long long bin_pow(long long base, long long exp, long long mod) {
//     long long res = 1;
//     base = base % mod;
//     while (exp > 0) {
//         if (exp % 2 == 1) {
//             res = res * base % mod;
//         }
//         base = base * base % mod;
//         exp /= 2;
//     }
//     return res;
// }
//
// std::vector<std::vector<long long>> prefHASH(std::vector<std::vector<int>> A, std::vector<int> powP1, std::vector<int> powP2) {
//     std::vector<std::vector<long long>> H(A.size(), std::vector<long long>(A[0].size(), 0));
//
//     for (int i = 0; i < A.size(); i++) {
//         for (int j = 0; j < A[i].size(); j++) {
//             if (i == 0 && j == 0) {
//                 H[i][j] = A[i][j] * powP1[i] % mod * powP2[j] % mod;
//             } else if (i == 0) {
//                 H[i][j] = (A[i][j] * powP1[i] % mod * powP2[j] % mod + H[i][j - 1]) % mod;
//             } else if (j == 0) {
//                 H[i][j] = (A[i][j] * powP1[i] % mod * powP2[j] % mod + H[i - 1][j]) % mod;
//             } else {
//                 H[i][j] = (A[i][j] * powP1[i] % mod * powP2[j] % mod + H[i][j - 1] + H[i - 1][j] - H[i - 1][j - 1]) % mod;
//             }
//         }
//     }
//     return H;
// }
//
// long long getHASH(std::vector<std::vector<int>> B, std::vector<int> powP1, std::vector<int> powP2) {
//     long long ans = 0;
//     for (int i = 0; i < B.size(); i++) {
//         for (int j = 0; j < B[i].size(); j++) {
//             ans += B[i][j] * powP1[i] % mod * powP2[j] % mod;
//         }
//     }
//     return ans;
// }
//
// long long getSubHASH(int x1, int y1, int x2, int y2, std::vector<std::vector<long long>> H) {
//     long long res;
//     if (x1 == 0 && y1 == 0) {
//         res = H[x2][y2];
//     } else if (x1 == 0) {
//         res = (H[x2][y2] - H[x2][y1 - 1]) % mod;
//     } else if (y1 == 0) {
//         res = (H[x2][y2] - H[x1 - 1][y2]) % mod;
//     } else {
//         res = (H[x2][y2] - H[x1 - 1][y2] - H[x2][y1 - 1] + H[x1 - 1][y1 - 1]) % mod;
//     }
//
//     res = res * bin_pow(p1, mod - 1 - x1, mod) % mod;
//     res = res * bin_pow(p2, mod - 1 - y1, mod) % mod;
//     return res;
// }

std::vector<int> GetCentre(std::vector<std::vector<int>> A) {
    std::vector<int> centreA;
    if (A.size() % 2 == 0 && A[0].size() % 2 == 0) {
        centreA.push_back(A[0].size() / 2 - 1);
        centreA.push_back(A.size() / 2 - 1);
    } else if (A.size() % 2 == 0 && A[0].size() % 2 != 0) {
        centreA.push_back(A[0].size() / 2);
        centreA.push_back(A.size() / 2 - 1);
    } else if (A.size() % 2 != 0 && A[0].size() % 2 == 0) {
        centreA.push_back(A[0].size() / 2 - 1);
        centreA.push_back(A.size() / 2);
    } else {
        centreA.push_back(A[0].size() / 2);
        centreA.push_back(A.size() / 2);
    }
    std::cout << "Centre of StarMap: " << centreA[0] << " " << centreA[1] << std::endl;
    return centreA;
}

std::vector<int> GetCentre(int x1, int y1, int x2, int y2) {
    std::vector<int> centre;
    if ((y2 - y1 + 1) % 2 == 0 && (x2 - x1 + 1) % 2 == 0) {
        centre.push_back(x1 + (x2 - x1 + 1) / 2 - 1);
        centre.push_back(y1 + (y2 - y1 + 1) / 2 - 1);
    } else if ((y2 - y1 + 1) % 2 == 0 && (x2 - x1 + 1) % 2 != 0) {
        centre.push_back(x1 + (x2 - x1 + 1) / 2);
        centre.push_back(y1 + (y2 - y1 + 1) / 2 - 1);
    } else if ((y2 - y1 + 1) % 2 != 0 && (x2 - x1 + 1) % 2 == 0) {
        centre.push_back(x1 + (x2 - x1 + 1) / 2 - 1);
        centre.push_back(y1 + (y2 - y1 + 1) / 2);
    } else {
        centre.push_back(x1 + (x2 - x1 + 1) / 2);
        centre.push_back(y1 + (y2 - y1 + 1) / 2);
    }
    std::cout << "Centre of transformed PersonWatching: " << centre[0] << " " << centre[1] << std::endl;
    return centre;
}

std::vector<int> GetPosition(std::vector<int> centreA, std::vector<int> centrePersonWatching, int differenceX, int differenceY, bool Higher, bool Lower, bool Righter, bool Lefter) {
    differenceX = abs(centreA[0] - centrePersonWatching[0]); differenceY = abs(centreA[1] - centrePersonWatching[1]);
    std::cout << "Difference of coordinates: " << differenceX << " " << differenceY << std::endl;

    if ((centrePersonWatching[0] - centreA[0]) > 0) {
        Righter = true;
        std::cout << "It's righter and ";
    } else {
        Lefter = true;
        std::cout << "It's lefter and ";
    }
    if ((centrePersonWatching[1] - centreA[1]) > 0) {
        Lower = true;
        std::cout << "lower\n";
    } else {
        Higher = true;
        std::cout << "higher\n";
    }

    std::vector<int> position;
    if (Lower) {
        position.push_back(-differenceY * 10);
    } else {
        position.push_back(differenceY * 10);
    }
    if (Righter) {
        position.push_back(differenceX * 10);
    } else {
        position.push_back(-differenceX * 10);
    }

    // std::cout << "The position: " << Higher << " " << Lower << ", " << Righter << " " << Lefter << std::endl;
    return position;
}

int main() {
    std::vector<std::vector<int>> A = getMatrixStar();
    std::vector<std::vector<int>> B = getMatrixPerson();
    // B = TransformPerson(B);

    ///////////////////////////////////////////////
    //////////////ОТЛАДОЧНЫЕ ПЕЧАТИ////////////////
    ///////////////////////////////////////////////

    std::cout << "StarMap:\n";
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "PersonWatching before transformation:\n";
    for (int i = 0; i < B.size(); i++) {
        for (int j = 0; j < B[i].size(); j++) {
            std::cout << B[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    B = TransformPerson(B);

    std::cout << "PersonWatching after transformation:\n";
    for (int i = 0; i < B.size(); i++) {
        for (int j = 0; j < B[i].size(); j++) {
            std::cout << B[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> powP1(A.size(), 1);
    std::vector<int> powP2(A.size(), 1);
    for (int i = 1; i < A.size(); i++) {
        powP1[i] = powP1[i - 1] * p1 % mod;
        powP2[i] = powP2[i - 1] * p2 % mod;
    }

    std::cout << "Pow for P1 - internal base:\n";
    for (int i = 0; i < powP1.size(); i++) {
        std::cout << powP1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Pow for P2 - external base:\n";
    for (int i = 0; i < powP2.size(); i++) {
        std::cout << powP2[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::vector<std::vector<long long>> H = prefHASH(A, powP1, powP2);

    std::cout << "Matrix of hash for StarMap:\n";
    for (int i = 0; i < H.size(); i++) {
        for (int j = 0; j < H[i].size(); j++) {
            std::cout << H[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    long long ans = getHASH(B, powP1, powP2);
    std::cout << "Hash for transformed PersonWatching: " << ans << std::endl;
    std::cout << std::endl;

    // std::vector<int> powP1(A.size(), 1);
    // std::vector<int> powP2(A.size(), 1);
    // for (int i = 1; i < A.size(); i++) {
    //     powP1[i] = powP1[i - 1] * p1 % mod;
    //     powP2[i] = powP2[i - 1] * p2 % mod;
    // }

    // std::vector<std::vector<int>> H = prefHASH(A, powP1, powP2);
    // long long ans = getHASH(B, powP1, powP2);
    int x1 = 0; int x2 = 0; int y1 = 0; int y2 = 0;

    std::cout << "All subhashes from StarMap:\n";
    for (int i = 0; i <= A.size() - B.size(); i++) {
        for (int j = 0; j <= A[i].size() - B[i].size(); j++) {
            long long res = getSubHASH(i, j, i + B.size() - 1, j + B[i].size() - 1, H);
            std::cout << res << std::endl;
            if (res == ans) {
                std::cout << std::endl;
                std::cout << "Coordinates of start: " << i << " " << j << " and coordinates of finish: " << i + B.size() - 1 << " " << j + B[i].size() - 1 << std::endl;
                x1 = i; y1 = j; x2 = i + B.size() - 1; y2 = j + B[i].size() - 1;
                std::cout << std::endl;
                std::cout << "Continue subhashes:\n";
            }
        }
    }
    std::cout << std::endl;
    std::vector<int> centreA = GetCentre(A);
    std::vector<int> centrePersonWatching = GetCentre(x1, y1, x2, y2);
    std::cout << std::endl;

    int differenceX = 0, differenceY = 0;
    bool Higher = false; bool Lower = false; bool Righter = false; bool Lefter = false;

    // int differenceX = abs(centreA[0] - centrePersonWatching[0]); int differenceY = abs(centreA[1] - centrePersonWatching[1]);
    // bool Higher; bool Lower; bool Righter; bool Lefter;
    // if ((centrePersonWatching[0] - centreA[0]) > 0) {
    //     Righter = true;
    // } else {
    //     Lefter = true;
    // }
    // if ((centrePersonWatching[1] - centreA[1]) > 0) {
    //     Lower = true;
    // } else {
    //     Higher = true;
    // }
    //
    // std::cout << "Difference of coordinates: " << differenceX << " " << differenceY << std::endl;
    // std::cout << "The position: " << Higher << " " << Lower << ", " << Righter << " " << Lefter << std::endl;
    std::vector<int> position = GetPosition(centreA, centrePersonWatching, differenceX, differenceY, Higher, Lower, Righter, Lefter);
    std::cout << "Differeences: " << position[0] << " " << position[1] << std::endl;
    std::cout << std::endl;

    if (position[0] > 0) {
        std::cout << "Person is standing on Northen latitude = " << (90 - position[0]);
    } else {
        std::cout << "Person is standing on Southern latitude = " << (90 + position[0]);
    }

    if (position[1] > 0) {
        std::cout << " and on East longitude = " << position[1] << std::endl;
    } else {
        std::cout << " and on West longitude = " << -position[1] << std::endl;
    }
    return 0;
}