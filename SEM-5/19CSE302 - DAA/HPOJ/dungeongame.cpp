#include <iostream>
using namespace std;

int main()
{
    int M, N, i, j;
    cin >> M >> N;
    int dungeon[M][N];
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            cin >> dungeon[i][j];
        }
    }
    i = j = 0;
    int min_arr[M][N];
    for (i = M - 1; i >= 0; --i)
    {
        for (j = N - 1; j >= 0; --j)
        {
            if (i == M - 1 && j == N - 1)
                min_arr[i][j] = min(0, dungeon[i][j]);
            else if (i == M - 1)
                min_arr[i][j] = min(0, dungeon[i][j] + min_arr[i][j + 1]);
            else if (j == N - 1)
                min_arr[i][j] = min(0, dungeon[i][j] + min_arr[i + 1][j]);
            else
                min_arr[i][j] = min(0, dungeon[i][j] + max(min_arr[i][j + 1], min_arr[i + 1][j]));
        }
    }
    cout << abs(min_arr[0][0]) + 1;
    return 0;
}