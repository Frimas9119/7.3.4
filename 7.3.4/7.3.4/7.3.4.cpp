#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo);
int Math(int** a, int* b, const int k, const int n);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -10;
	int High = 10;
	int n;
	int k;
	int z = 0;
	cout << "n = "; cin >> n;
	cout << "k = "; cin >> k;
	int** a = (int**) new int[k][5];
	int* b = new int[k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	CreateRows(a, k, n, Low, High, 0);
	Print(a, k, n, 0, 0);
	Math(a, b, k, n);
	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	delete[] b;
	return 0;
}
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo)

{
	CreateRow(a, rowNo, colCount, Low, High, 0);
	if (rowNo < rowCount - 1)
		CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);

}
void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo)

{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < colCount - 1)
		CreateRow(a, rowNo, colCount, Low, High, colNo + 1);

}
void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;

}
int Math(int** a, int* b, const int k, const int n) {
	int s = 0;
	for (int i = 0;i < k;i++) {
		for (int j = 0;j < n;j++) {
			if (a[i][j] < 0) {
				for (int z = 0;z < k;z++) {
					s += a[z][j];
				}
				b[j] = s;
				s = 0;
			}
		}
	}
	for (int x = 0;x < n;x++) {
		cout << b[x] << endl;
	}
	return 0;
}