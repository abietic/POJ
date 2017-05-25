#include <iostream>
#include <cstdio>
//----------------------------------------
using namespace std;
//----------------------------------------
int frigemap[4][4] = {0};
//----------------------------------------
//----------------------------------------
void flip(int x , int y);
//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
bool enumeration(int start , int coun , int NUM , int length , int result[]);
//----------------------------------------
bool do_cal(int result[] , int coun);
//----------------------------------------
bool isopened();
//----------------------------------------
int main()
{
    int result[30] = {0};
    for (int i = 0 ; i < 4 ; i++)
    {
        for (int j = 0 ; j <= 4 ; j++)
        {
            int t = getchar();
            if (t == '-')
            {
                frigemap[i][j] = 1;
            }
            else
            {
                frigemap[i][j] = 0;
            }
        }
    }
    /*for (int i = 0 ; i < 4 ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            printf("%d" , frigemap[i][j]);
        }
        printf("\n");
    }*/
    for (int i = 1 ; i <= 16 ; i++)
    {
        if (enumeration(0 , 0 , i , 16 , result))
        {
            break;
        }
    }
    //cout << "Hello world!" << endl;
    return 0;
}
//----------------------------------------
//----------------------------------------
//----------------------------------------
void flip(int x , int y)
{
    for (int i = 0 ; i < 4 ; i++)
    {
        frigemap[i][y] ^= 1;
        frigemap[x][i] ^= 1;
    }
    frigemap[x][y] ^= 1;
}
//----------------------------------------
bool isopened()
{
    for (int i = 0 ; i < 4 ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            if (!frigemap[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
//----------------------------------------
bool do_cal(int result[] , int coun)
{
    for (int i = 0 ; i < coun ; i++)
    {
        flip(result[i]/4 , result[i]%4);
    }
    //cout << "Hello world!" << endl;
    if (isopened())
    {
        printf("%d\n" , coun);
        for (int i = 0 ; i < coun ; i++)
        {
            printf("%d %d\n" , result[i]/4 + 1 , result[i]%4 + 1);
        }
        return true;
    }
    for (int i = 0 ; i < coun ; i++)
    {
        flip(result[i]/4 , result[i]%4);
    }
    return false;
}
//----------------------------------------
bool enumeration(int start , int coun , int NUM , int length , int result[])
{
    if (coun == NUM)
    {
        return do_cal(result , coun);
    }
    for (int i = start ; i < length ; i++)
    {
        result[coun] = i;
        if(enumeration(i + 1 , coun + 1 , NUM , length , result))
        {
            return true;
        }
    }
    return false;
}
//----------------------------------------
//----------------------------------------

