#include <iostream>
#include <cstdio>
//----------------------------------------
using namespace std;
//----------------------------------------
bool enumeration(int targ[] , int start , int coun , int NUM , int length , int result[]);
//----------------------------------------
struct node
{
    int x;
    int y;
} pos[16];
//----------------------------------------
char flipmap[10][10] = {0};
//----------------------------------------
void initiate()
{
    for (int i = 0 ; i < 4 ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            int t = i * 4 + j;
            pos[t].x = i;
            pos[t].y = j;
        }
    }
}
//----------------------------------------
bool do_caculate(int result[] , int coun);
//----------------------------------------
void flip(int x , int y);
//----------------------------------------
bool isfullfunc()
{
    char t = flipmap[0][0];
    for (int i = 0 ; i < 4 ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            if (t != flipmap[i][j])
                return false;
        }
    }
    return true;
}
//----------------------------------------
void do_flip(int x , int y)
{
    if (flipmap[x][y] == 'b')
    {
        flipmap[x][y] = 'w';
    }
    else
    {
        flipmap[x][y] = 'b';
    }
}
//----------------------------------------
void do_print(bool minstep[])
{
    for (int i = 1 ; i <= 16 ; i++)
    {
        if (minstep[i])
        {
            if (i != 16)
            {
                cout << i << endl;
                return;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
    cout << "Impossible\n";
    return;
}
//----------------------------------------
int main()
{
    for (int i = 0 ; i < 4 ; i++)
    {
        scanf("%s" , flipmap[i]);
    }
    if (isfullfunc())
    {
        cout << 0 << endl;
    }
    else
    {
        initiate();
        int res[30] , targ[16];
        for (int i = 0 ; i < 16 ; i++)
        {
            targ[i] = i + 1;
        }
        bool minstep[17] = {0};
        for (int i = 1 ; i <= 16 ; i++)
        {
            minstep[i] = enumeration(targ , 0 , 0 , i , 16 , res);
        }
        do_print(minstep);
    }
    //cout << "Hello world!" << endl;
    return 0;
}
//----------------------------------------
bool enumeration(int targ[] , int start , int coun , int NUM , int length , int result[])
{
    if (coun == NUM)
    {
        return do_caculate(result , coun);
    }
    for (int i = start ; i < length ; i++)
    {
        result[coun] = i;
        bool isfull = enumeration(targ , i + 1 , coun + 1 , NUM , length , result);
        if (isfull)
        {
            return true;
        }
    }
    return false;
}
//----------------------------------------
bool do_caculate(int result[] , int coun)
{
    for (int i = 0 ; i < coun ; i++)
    {
        flip(pos[result[i]].x , pos[result[i]].y);
    }
    bool isfull = isfullfunc();
    for (int i = 0 ; i < coun ; i++)
    {
        flip(pos[result[i]].x , pos[result[i]].y);
    }
    return isfull;
}
//----------------------------------------
void flip(int x , int y)
{
    do_flip(x , y);
    if (x - 1 >= 0)
    {
        do_flip(x - 1 , y);
    }
    if (x + 1 < 4)
    {
        do_flip(x + 1 , y);
    }
    if (y - 1 >= 0)
    {
        do_flip(x , y - 1);
    }
    if (y + 1 < 4)
    {
        do_flip(x , y + 1);
    }
}
//----------------------------------------
