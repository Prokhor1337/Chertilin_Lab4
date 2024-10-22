#include <iostream>
#include <windows.h>

using namespace std;

void quickSort(int a[], int left, int right) {
    if (left >= right) return;
    int p = a[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    quickSort(a, left, j);
    quickSort(a, i, right);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    const int N = 10;
    int a[N];

    cout << "Масив: \n";
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 20;
        cout << a[i] << " ";
    }
    cout << endl;

    quickSort(a, 0, N - 1);

    cout << "Відсортований масив: \n";
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
