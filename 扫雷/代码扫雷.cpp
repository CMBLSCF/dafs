#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <easyx.h>
#include <mmsystem.h>
#pragma comment (lib,"winmm.lib")
const int ROW = 10;
const int COL = 10;
const int IMGW = 40;
using namespace std;
void mapquip(int map[ROW][COL]);
void draw_map(int map[ROW][COL], IMAGE img[12]);
int mouseEvent(int map[ROW][COL], IMAGE img[12]);
void openNull(int map[ROW][COL], int row, int col);
void judge(int map[ROW][COL], int row, int col);
int pan(int map[ROW][COL]);
void showMap(int map[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int k = 0; k < COL; k++)
		{
			printf("%4d", map[i][k]);
		}
		printf("\n");
	}
	cout << endl;
}
bool isOver = false;//over 
int main()
{
	//设置窗口
	initgraph(COL*IMGW, ROW*IMGW);
	mciSendString("open 1.mp3", 0, 0, 0);
	mciSendString("play 1.mp3", 0, 0, 0);
	mciSendString("repeat 1.mp3", 0, 0, 0);
	srand((unsigned)time(NULL));
	int map[ROW][COL] = { 0 };
	mapquip(map);
	//把数据转成对应的图形界面
	IMAGE img[12];//定义图片数组
	//加载图片
	for (int i = 0; i < 12; i++)
	{
		char fileName[50] = { 0 };
		sprintf_s(fileName, "./imga/%d.jpg", i);
		loadimage(img + i, fileName, IMGW, IMGW);
		//  putimage(i * IMGW, 0, img + i);
	}
	//绘制地图
	while (true)
	{   
		int m = mouseEvent(map,img);
		draw_map(map, img);
		if (m == 1)
		{
			int ret = MessageBox(GetHWnd(), "you are winner  再来一把？", "hit", MB_OKCANCEL);
			if (ret == IDOK)
			{
				mapquip(map);
				showMap(map);
				isOver = false;
			}
			else if (ret == IDCANCEL)
			{
				exit(666);
			}
		}
		if (isOver)
		{
			int ret=MessageBox(GetHWnd(), "你踩到雷了，再来一把？", "hit", MB_OKCANCEL);
			if (ret == IDOK)
			{
				mapquip(map);
				showMap(map);
				isOver = false;
			}
			else if (ret==IDCANCEL)
			{
				exit(666);
			}
		}
	}
	system("pause");
	return 0;
}
void mapquip(int map[ROW][COL])
{   //重置为0；
	memset(map, 0, ROW * COL * sizeof(int));
	//lei
	for (int i = 0; i < 10;)
	{
		int r = rand() % ROW;
		int c = rand() % COL;
if (map[r][c] == 0)
{
	map[r][c] = -1;
	i++;
}
	}
//
for (int i = 0; i < ROW; i++)
{
	for (int k = 0; k < COL; k++)
	{
		if (map[i][k] == -1)
		{
			for (int r = i - 1; r <= i + 1; r++)
			{
				for (int c = k - 1; c <= k + 1; c++)
				{
					if ((r >= 0 && r < ROW && c >= 0 && c < COL) && map[r][c] != -1)
						map[r][c]++;
				}
			}

		}
	}
}
//把所有的格子都用遮罩盖起来，给每个格子都加密，都加20
for (int i = 0; i < ROW; i++)
{
	for (int k = 0; k < COL; k++)
	{
		map[i][k] += 20;
	}
}
}
void draw_map(int map[ROW][COL], IMAGE img[12])
{
	//把数组里面的数据，转换成对应的图片，贴到图形窗口上面；
	for (int i = 0; i < ROW; i++)
	{
		for (int k = 0; k < COL; k++)
		{
			//空白格子和数字
			if (map[i][k] >= 0 && map[i][k] <= 8)
			{
				putimage(k * IMGW, i * IMGW, img + map[i][k]);
			}
			else if (map[i][k] == -1)
			{
				putimage(k * IMGW, i * IMGW, img + 9);
			}
			else if (map[i][k] >= 19 && map[i][k] <= 28)
			{
				putimage(k * IMGW, i * IMGW, img + 10);
			}
		}
	}
}
int  mouseEvent(int map[ROW][COL], IMAGE img[12])
{
	//定义消息结构体（鼠标，按键，字符）
	ExMessage msg;
	//如果有消息返回真，并且给msg设置值
	if (peekmessage(&msg, EM_MOUSE))
	{		
		//把鼠标转换che'gng
		int r = msg.y / IMGW;
		int c = msg.x / IMGW;
		if (msg.message == WM_LBUTTONDOWN)
		{
			if (map[r][c] >= 19 && map[r][c] <= 28)
			{
				map[r][c] -= 20;
				openNull(map, r, c);
				judge(map, r, c);
				showMap(map);
				if (pan(map) == 10) return 1;
			}
		}
	}
}
void openNull(int map[ROW][COL], int row, int col)
{
	//判断当前点击是不是空白
	if (map[row][col] == 0)
	{
		for (int i = row - 1; i <= row + 1; i++)
		{
			for (int k = col - 1; k <= col + 1; k++)
			{
				if ((i >= 0 && i < ROW && k >= 0 && k < COL) && map[i][k] >= 19 && map[i][k] <= 28)
				{
					map[i][k] -= 20;
					openNull(map, i, k);
				}
			}
		}
	}
}
void judge(int map[ROW][COL], int row, int col)
{
	//点到雷；over
	if (map[row][col] == -1)
	{
		for (int i = 0; i < ROW; i++)
		{
			for (int k = 0; k < COL; k++)
			{
				if (map[i][k] == 19)
				{
					map[i][k] -= 20;
				}
			}
		}
		isOver = true;
	}
}
int pan(int map[ROW][COL])
{
	int k=0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] > 15) k++;
		}
	}
	return k;
}