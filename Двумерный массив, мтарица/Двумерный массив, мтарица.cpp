#include <iostream>
#include<iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    int N, M;
    cout << "Количество строк:" << endl;
    cin >> N;
    cout << "Количество столбцов:" << endl;
    cin >> M;
    int** a = new int* [N];
    for (int i = 0; i < N; i++)
    {
        a[i] = new int[M];
    }
    double* c = new double[N];
    cout << "1 - ввести массив, 2 - заполнить случайными числами:" << endl;
    int b; cin >> b;
    if (b == 1)
    {
        cout << "Введите " << N * M << " чисел в интервале (-10;10)" << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                cin >> a[i][j];
        }
        cout << "Введенный массив" << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                cout << setw(4) << a[i][j] << "   ";
            cout << endl;
        }
    }
    else
    {
        srand((unsigned)time(0));
        cout << "Исходный массив" << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                a[i][j] = (rand() % 21 - 10);
                cout << setw(4) << a[i][j] << "   ";
            }
            cout << endl;
        }
    }
    for (int i = 0; i < N; i++)
    {
        int s = 0;
        for (int j = 0; j < M; j++)
        {
            s += a[i][j];
        }
        c[i] = (double)s / M;
        s = 0;
        for (int j = 0; j < M; j++)
        {
            if (a[i][j] < c[i])
                s++;
        }
        cout << "в строке " << i << " количество элементов меньших среднего арифметического=" << s << endl;
    }
    for (int i = 0; i < N; i++)
        delete[] a[i];
    delete[] a;
    delete[] c;
    system("PAUSE");
    return 0;
}