#include <bits/stdc++.h>
using namespace std;
#define an 100
const int assume = -1e7;
int measure[an][an];
int furt[an][an];
void ls(int fs, vector<vector<int>> &mar)
{
    for (int p = 0; p < fs; p++)
    {
        for (int q = 0; q < fs; q++)
        {
            measure[p][q] = mar[p][q];
            if (mar[p][q] == assume)
                furt[p][q] = -1;
            else
                furt[p][q] = q;
        }
    }
}
vector<int> pathfindalgo(int k, int l)
{
    if (furt[k][l] == -1)
        return {};
    vector<int> way = {k};
    while (k != l)
    {
        k = furt[k][l];
        way.push_back(k);
    }
    return way;
}
void approach(int f)
{
    for (int ini = 0; ini < f; ini++)
    {
        for (int p = 0; p < f; p++)
        {
            for (int q = 0; q < f; q++)
            {
                if (measure[p][ini] == assume || measure[ini][q] == assume)
                    continue;

                if (measure[p][q] < measure[p][ini] + measure[ini][q])
                {
                    measure[p][q] = measure[p][ini] + measure[ini][q];
                    furt[p][q] = furt[p][ini];
                }
            }
        }
    }
}

void get(vector<int> &way)
{
    int count = way.size();
    for (int c = 0; c < count - 1; c++)
        cout << way[c] + 1 << ",";
    cout << way[count - 1] + 1 << endl;
}

int main()
{
    int ct, nw;
    cin >> ct >> nw;
    int gf = ct;
    int fromuser[ct];
    vector<vector<int>> mar;
    for (int d = 0; d < ct; d++)
    {
        cin >> fromuser[d];
    }

    for (int d = 0; d < ct; d++)
    {
        vector<int> ner;
        for (int e = 0; e < ct; e++)
        {
            if (fromuser[d] == fromuser[e] - 1)
            {
                ner.push_back(abs(e - d));
            }
            else
            {
                ner.push_back(assume);
            }
        }
        mar.push_back(ner);
    }
    ls(gf, mar);
    approach(gf);
    vector<int> way;

    int hg = assume;
    int start, final;
    for (int d = 0; d < ct; d++)
    {
        for (int e = 0; e < ct; e++)
        {
            if (fromuser[e] == nw && measure[d][e] != assume && hg < measure[d][e])
            {
                hg = measure[d][e];
                start = d;
                final = e;
            }
        }
    }
    if (hg == assume)
        cout << 0;
    else
        cout << hg << endl;

    if (hg != assume)
    {
        way = pathfindalgo(start, final);
        get(way);
    }

    return 0;
}