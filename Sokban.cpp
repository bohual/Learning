#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
//地图
//0：空地；1：墙壁 3：箱子的目的地
//4：箱子  6：人	7：箱子和目的地重合
//9：人站在目的地
int g_map[2][10][12] = 
{
	{
		{1,1,1,1,1,0,0,0,0,0,0,0},
		{1,0,0,0,1,0,1,1,1,0,0,0},
		{1,0,4,0,1,0,1,1,1,1,1,1},
		{1,0,4,6,1,0,1,0,0,0,3,1},
		{1,1,1,4,1,1,1,0,0,0,3,1},
		{0,1,0,0,0,0,0,0,0,0,3,1},
		{0,1,0,0,0,1,0,0,0,0,0,1},
		{0,1,0,0,0,1,0,0,0,0,0,1},
		{0,1,1,1,1,1,0,0,0,0,0,1},
		{0,0,0,0,0,0,1,1,1,1,1,1},
	},
	{
		{0,1,1,1,1,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,0,0,0},
		{0,1,0,0,0,0,1,1,1,1,1,1},
		{1,1,4,1,1,0,1,0,0,0,0,1},
		{1,1,6,0,1,0,0,0,0,0,0,1},
		{1,0,0,1,1,1,0,0,0,0,0,1},
		{1,0,0,0,4,0,0,4,0,0,0,1},
		{1,0,3,3,1,0,4,0,0,0,0,1},
		{1,1,3,3,1,0,0,0,0,0,0,1},
		{0,1,1,1,1,1,1,1,1,1,1,1},
	},

};

int g_nCurrentLevel = 0;//当前关卡

//打印地图
void DrawMap();
POINT GetGamerPosition();//获取玩家坐标
void Up();
void Down();
void Left();
void Right();
int GetSpareBox(); //计算空余箱子个数

int main()
{
	if (GetSpareBox() == 0)
	{
		g_nCurrentLevel++;
	}
	//设置标题
	SetConsoleTitle(L"推箱子");

	//设置窗口的大小
	system("mode con cols=26 lines=12");

	while (1)
	{
	
		system("cls");
		DrawMap();
		char ch = getch();
		switch (ch)
		{
			case 'w':
			case 72://往上
				Up();
				break;
			case 's':
			case 80:
				Down();
				break;//往下
			case 'a':
			case 75:
				Left();
				break;
			case 'd':
			case 77:
				Right();
				break;
		}
	}
	return 0;
}

//打印地图
void DrawMap()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			switch (g_map[g_nCurrentLevel][i][j])
			{
				case 0://空地
					printf("  ");
					break;
				case 1://墙壁
					printf("■");
					break;
				case 3://箱子目的地
					printf("☆");
					break;
				case 4://箱子
					printf("□");
					break;
				case 6://人
					printf("♂");
					break;
				case 7://箱子与目的地重合
					printf("★");
					break;
				case 9:
					//人站在目的地
					printf("♂");
					break;


			}
		}
		printf("\n");
	}
}

POINT GetGamerPosition()//获取玩家坐标
{
	POINT pos = { -1,-1 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (g_map[g_nCurrentLevel][i][j] == 6 || g_map[g_nCurrentLevel][i][j] == 9)
			{
				pos.x = i;
				pos.y = j;
				return pos;
			}
		}
	}
	return pos;
}

//向上
void Up()
{
	POINT pos = GetGamerPosition();

	//1.人的前面是空地
	if (g_map[g_nCurrentLevel][pos.x - 1][pos.y] == 0)
	{
		g_map[g_nCurrentLevel][pos.x - 1][pos.y] = 6;//空地改为人

		//原来人的位置还原
		if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
			g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
		else
			g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
	}
	//2.人的前面是目的地
	if (g_map[g_nCurrentLevel][pos.x - 1][pos.y] == 3)
	{
		g_map[g_nCurrentLevel][pos.x - 1][pos.y] = 9;//人站在目的地
		//原来人的位置还原
		if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
			g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
		else
			g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
	}
	//3.人的前面是箱子
	if (g_map[g_nCurrentLevel][pos.x - 1][pos.y] == 4)
	{
		//a.箱子的前面是空地
		if (g_map[g_nCurrentLevel][pos.x - 2][pos.y] == 0)
		{
			g_map[g_nCurrentLevel][pos.x - 2][pos.y] = 4;
			g_map[g_nCurrentLevel][pos.x - 1][pos.y] = 6;
			
			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
		}
		//b.箱子的前面是目的地
		if (g_map[g_nCurrentLevel][pos.x - 2][pos.y] == 3)
		{
			g_map[g_nCurrentLevel][pos.x - 2][pos.y] = 7;
			g_map[g_nCurrentLevel][pos.x - 1][pos.y] = 6;
			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
		}
	}

		
	//4.人的前面是是箱子和目的地的重合
	if (g_map[g_nCurrentLevel][pos.x - 1][pos.y] == 7)

	{	
		//a.箱子的前面是空地
		if (g_map[g_nCurrentLevel][pos.x - 2][pos.y] == 0)
		{
			g_map[g_nCurrentLevel][pos.x - 2][pos.y] = 4;
			g_map[g_nCurrentLevel][pos.x - 1][pos.y] = 9;
			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
			
		}
		//b.箱子的前面是目的地
		if (g_map[g_nCurrentLevel][pos.x - 2][pos.y] == 3)
		{
			g_map[g_nCurrentLevel][pos.x - 2][pos.y] = 7;
			g_map[g_nCurrentLevel][pos.x - 1][pos.y] = 9;

			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
		}
	}
}

void Down()
{
	POINT pos = GetGamerPosition();

	//1.人的前面是空地
	if (g_map[g_nCurrentLevel][pos.x + 1][pos.y] == 0)
	{
		g_map[g_nCurrentLevel][pos.x + 1][pos.y] = 6;//空地改为人

		//原来人的位置还原
		if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
			g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
		else
			g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
	}
	//2.人的前面是目的地
	if (g_map[g_nCurrentLevel][pos.x + 1][pos.y] == 3)
	{
		g_map[g_nCurrentLevel][pos.x + 1][pos.y] = 9;//人站在目的地
		//原来人的位置还原
		if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
			g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
		else
			g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
	}
	//3.人的前面是箱子
	if (g_map[g_nCurrentLevel][pos.x + 1][pos.y] == 4)
	{
		//a.箱子的前面是空地
		if (g_map[g_nCurrentLevel][pos.x + 2][pos.y] == 0)
		{
			g_map[g_nCurrentLevel][pos.x + 2][pos.y] = 4;
			g_map[g_nCurrentLevel][pos.x + 1][pos.y] = 6;

			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
		}
		//b.箱子的前面是目的地
		if (g_map[g_nCurrentLevel][pos.x + 2][pos.y] == 3)
		{
			g_map[g_nCurrentLevel][pos.x + 2][pos.y] = 7;
			g_map[g_nCurrentLevel][pos.x - 1][pos.y] = 6;
			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
		}
	}


	//4.人的前面是是箱子和目的地的重合
	if (g_map[g_nCurrentLevel][pos.x + 1][pos.y] == 7)

	{
		//a.箱子的前面是空地
		if (g_map[g_nCurrentLevel][pos.x + 2][pos.y] == 0)
		{
			g_map[g_nCurrentLevel][pos.x + 2][pos.y] = 4;
			g_map[g_nCurrentLevel][pos.x + 1][pos.y] = 9;
			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;

		}
		//b.箱子的前面是目的地
		if (g_map[g_nCurrentLevel][pos.x + 2][pos.y] == 3)
		{
			g_map[g_nCurrentLevel][pos.x + 2][pos.y] = 7;
			g_map[g_nCurrentLevel][pos.x + 1][pos.y] = 9;

			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
		}
	}
}

void Left()
{
	POINT pos = GetGamerPosition();

	//1.人的前面是空地
	if (g_map[g_nCurrentLevel][pos.x][pos.y - 1] == 0)
	{
		g_map[g_nCurrentLevel][pos.x][pos.y - 1] = 6;//空地改为人

		//原来人的位置还原
		if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
			g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
		else
			g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
	}
	//2.人的前面是目的地
	if (g_map[g_nCurrentLevel][pos.x][pos.y - 1] == 3)
	{
		g_map[g_nCurrentLevel][pos.x][pos.y - 1] = 9;//人站在目的地
		//原来人的位置还原
		if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
			g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
		else
			g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
	}
	//3.人的前面是箱子
	if (g_map[g_nCurrentLevel][pos.x][pos.y - 1] == 4)
	{
		//a.箱子的前面是空地
		if (g_map[g_nCurrentLevel][pos.x][pos.y - 2] == 0)
		{
			g_map[g_nCurrentLevel][pos.x][pos.y - 2] = 4;
			g_map[g_nCurrentLevel][pos.x][pos.y - 1] = 6;

			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
		}
		//b.箱子的前面是目的地
		if (g_map[g_nCurrentLevel][pos.x][pos.y - 2] == 3)
		{
			g_map[g_nCurrentLevel][pos.x][pos.y - 2] = 7;
			g_map[g_nCurrentLevel][pos.x][pos.y - 1] = 6;
			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
		}
	}


	//4.人的前面是是箱子和目的地的重合
	if (g_map[g_nCurrentLevel][pos.x][pos.y - 1] == 7)

	{
		//a.箱子的前面是空地
		if (g_map[g_nCurrentLevel][pos.x][pos.y] == 0)
		{
			g_map[g_nCurrentLevel][pos.x][pos.y - 2] = 4;
			g_map[g_nCurrentLevel][pos.x][pos.y - 1] = 9;
			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;

		}
		//b.箱子的前面是目的地
		if (g_map[g_nCurrentLevel][pos.x][pos.y - 2] == 3)
		{
			g_map[g_nCurrentLevel][pos.x][pos.y - 2] = 7;
			g_map[g_nCurrentLevel][pos.x][pos.y - 1] = 9;

			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
		}
	}
}

void Right()
{
	POINT pos = GetGamerPosition();

	//1.人的前面是空地4
	if (g_map[g_nCurrentLevel][pos.x][pos.y + 1] == 0)
	{
		g_map[g_nCurrentLevel][pos.x][pos.y + 1] = 6;//空地改为人

		//原来人的位置还原
		if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
			g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
		else
			g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
	}
	//2.人的前面是目的地
	if (g_map[g_nCurrentLevel][pos.x][pos.y + 1] == 3)
	{
		g_map[g_nCurrentLevel][pos.x][pos.y + 1] = 9;//人站在目的地
		//原来人的位置还原
		if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
			g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
		else
			g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
	}
	//3.人的前面是箱子
	if (g_map[g_nCurrentLevel][pos.x][pos.y + 1] == 4)
	{
		//a.箱子的前面是空地
		if (g_map[g_nCurrentLevel][pos.x][pos.y + 2] == 0)
		{
			g_map[g_nCurrentLevel][pos.x][pos.y + 2] = 4;
			g_map[g_nCurrentLevel][pos.x][pos.y + 1] = 6;

			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
		}
		//b.箱子的前面是目的地
		if (g_map[g_nCurrentLevel][pos.x][pos.y + 2] == 3)
		{
			g_map[g_nCurrentLevel][pos.x][pos.y + 2] = 7;
			g_map[g_nCurrentLevel][pos.x][pos.y + 1] = 6;
			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
		}
	}


	//4.人的前面是是箱子和目的地的重合
	if (g_map[g_nCurrentLevel][pos.x][pos.y + 1] == 7)

	{
		//a.箱子的前面是空地
		if (g_map[g_nCurrentLevel][pos.x][pos.y] == 0)
		{
			g_map[g_nCurrentLevel][pos.x][pos.y + 2] = 4;
			g_map[g_nCurrentLevel][pos.x][pos.y + 1] = 9;
			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;

		}
		//b.箱子的前面是目的地
		if (g_map[g_nCurrentLevel][pos.x][pos.y + 2] == 3)
		{
			g_map[g_nCurrentLevel][pos.x][pos.y + 2] = 7;
			g_map[g_nCurrentLevel][pos.x][pos.y + 1] = 9;

			//原来人的位置还原
			if (g_map[g_nCurrentLevel][pos.x][pos.y] == 9)
				g_map[g_nCurrentLevel][pos.x][pos.y] = 3;
			else
				g_map[g_nCurrentLevel][pos.x][pos.y] = 0;
		}
	}
}

int GetSpareBox() //计算空余箱子个数
{
	int nCount = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (g_map[g_nCurrentLevel][i][j] == 4)
			{
				nCount++;
			}
		}
	}
	return nCount;
}
