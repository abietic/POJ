#include <iostream>
#include <queue>
#include <stack>
//----------------------------------------
using namespace std;
//----------------------------------------
int main()
{
    const int key = 100;
    int watermap[200][200] = {0};
    int M , N;
    cin >> M >> N;
    char str[200];
    for (int i = 0 ; i < M ; i++)
    {
        cin >> str;
        for (int j = 0 ; j < N ; j++)
        {
            if (str[j] == 'W')
            {
                watermap[i][j] = 1;
            }
        }
    }
    stack<int> s;
    int temp , temp_l , temp_a;
    int coun = 0;
    int curl , cura;
    for (curl = 0 ; curl < M ; curl++)
    {
        for (cura = 0 ; cura < N ; cura++)  //////////之前把N写成了M疯狂WA   = =;
        {
            if (watermap[curl][cura] == 1)
            {
                s.push(curl * key + cura);
                while (!s.empty())
                {
                    temp = s.top();
                    s.pop();
                    temp_l = temp / key;
                    temp_a = temp % key;
                    watermap[temp_l][temp_a] = 2;
                    for (int p = temp_l - 1 ; p <= temp_l + 1 ; p++)
                    {
                        for (int q = temp_a - 1 ; q <= temp_a + 1 ; q++)
                        {
                            if (q >= 0 && q < N && p >= 0 && p < M && watermap[p][q] == 1)
                            {
                                s.push(p * key + q);
                            }
                        }
                    }
                }
                coun++;
            }
        }
    }
    cout << coun << endl;
    /*for (int m = 0 ; m < M ; m++)
    {
        for (int n = 0 ; n < N ; n++)
        {
            cout << watermap[m][n];
        }
        cout << endl;
    }*/
    //cout << "Hello world!" << endl;
    return 0;
}
//----------------------------------------
