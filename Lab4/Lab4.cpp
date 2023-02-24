#include <iostream>
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int n, m;
    cout << "COLUMNS" << endl;
    cin >> m;
    cout << "ROWS" << endl;
    cin >> n;

    vector<int> pseudoMatrix;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pseudoMatrix.push_back(rand());
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << pseudoMatrix[m * i + j] << "\t";
        }
        cout << "\n\n";
    }

    bool isBiggerBefore;
    for (int i = 0; i < n * m; i++) {
        isBiggerBefore = true;
        for (int j = 0; j < i; j++) {
            if (pseudoMatrix[i] <= pseudoMatrix[j]) {
                isBiggerBefore = false;
            }
        }
        if (isBiggerBefore) cout << "x[" << (i / n) << ", " << (i % n) << "] = " << pseudoMatrix[i] << endl;
    }

    system("pause");
    return 0;
}