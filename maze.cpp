//使用了BFS宽度优先算法（还是不太理解），好像还可以用DFS深度优先算法。看了别人的才写出来
#include <cstdio>
#include <queue>
#define size 5
const int hx=0,hy=0;
const int ex=size-1,ey=size-1;
int maze[size][size];
int previous[size][size];
int mindistant[size][size];
int minmap[size*size*size*size];
const int direction[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
int hasbeenvisited[size][size] = {0};
void get()
{
	for(int i = 0;i<size;i++)
	{
		for(int j = 0;j<size;j++)
		{
			scanf("%d",&maze[i][j]);
		}
	}
}
void printorder();
int solve()
{
     int temp;
	 int x=hx,y=hy;
	 int key;
	 key = x * size + y;
	 previous[x][y] = key;
	 mindistant[x][y] = 0;
	 hasbeenvisited[x][y] = 1;
	 std::queue<int> list;
	 list.push(key);
	 for(;;)
	 {
	 	key = list.front();
	 	list.pop();
	 	x = key/size;
	 	y = key%size;
	 	for(int i = 0;i <= 3;i++)
	 	{
	 		int nx = x + direction[i][0];
	 		int ny = y + direction[i][1];
	 		if(ny >= 0&&nx >= 0&&nx < size&&ny < size&&hasbeenvisited[nx][ny] == 0&&maze[nx][ny] != 1)
	 		{
	 			mindistant[nx][ny] = mindistant[x][y] + 1;
	 			previous[nx][ny] = key;
	 			temp = nx*size +ny;
	 			list.push(temp);
	 			hasbeenvisited[nx][ny] = 1;
	 			if(nx == ex&&ny == ey)
	 			{
	 				printorder();
	 				return mindistant[nx][ny];
				 }
			 }
		 }
	 }
}
void printorder()
{
	int x=ex,y=ey;
	int count = 0;
	int temp;
	while(1)
	{
		temp = previous[x][y];
		minmap[count++] = temp;
		x = temp/size;
		y = temp%size;
		if(x == hx&&y == hy)
		{
			break;
		}
	}
	for(int i = count-1;i>=0;i--)
	{
		printf("(%d, %d)",minmap[i]/size,minmap[i]%size);
	}
}
int main()
{
	get();
	solve();
	return 0;
}
