#include <iostream>
using namespace std;


float GetRowMember(int k, float x) {
    return (k / (k + 1)) - (float)pow(cos(abs(x)), k);
}


int main()
{
    // Произведение 3мя способами
    setlocale(LC_ALL, "RUS");
    unsigned int n;
    float x;
    float p;

    cout << "Введите количество элементов ряда" << endl;
    cin >> n;
    cout << "Введите Х" << endl;
    cin >> x;
    // 1 for
    p = 1;
    for (int i = 1; i <= (int)n; i++) {
        p *= GetRowMember(i, x);
    }
    cout << "1 Способ. Произведение = " << p << endl;

    // 2 while
    int i = 1;
    p = 1;
    while (i <= (int)n) {
        p *= GetRowMember(i, x);
        i++;
    }
    cout << "2 Способ. Произведение = " << p << endl;

    // 3 do while
    i = 1;
    p = 1;
    do {
        p *= GetRowMember(i, x);
        i++;
    } while (i <= (int)n);

    cout << "3 Способ. Произведение = " << p << endl;

    system("pause");
    return 0;
}