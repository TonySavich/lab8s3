#include <iostream>


using namespace std;
const int n = 10, col_razr = 4;
int velich_razr(int chislo, int razr)
{
    while (razr > 1)
    {
        chislo /= 10;
        razr--;
    }
    return chislo % 10;
}

void sort_razr(int dop_mas[n][n], int mas[n], int razr)
{
    int mas_col[n], i, j, temp = 0;
    for (i = 0; i < n; i++)
        mas_col[i] = 0;
    for (i = 0; i < n; i++)
    {
        int a = velich_razr(mas[i], razr);
        dop_mas[mas_col[a]][a] = mas[i];
        mas_col[a]++;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < mas_col[i]; j++)
        {
            mas[temp] = dop_mas[j][i];
            temp++;
        }
    }
}

int main()
{

    int razr, i;
    int mas[n] = { 6, 543, 1260, 935, 1423, 6130, 732, 126, 84, 68 };
    int dop_mas[n][n];
    for (razr = 1; razr < col_razr + 1; razr++)
        sort_razr(dop_mas, mas, razr);
    for (i = 0; i < n; i++)
        cout << mas[i] << endl;
    return 0;
}


