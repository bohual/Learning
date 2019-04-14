#include <stdio.h>
#include <Windows.h>

//不用库函数，用C语言实现将一个整形数字转换成字符串
//获取字符串长度
int getlen(char *s)
{
	int n;
	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}

void reverse(char s[])
{
	int i, j;
	for (i = 0, j = getlen(s) - 1; i < j; i++, j--)
	{
		int temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	printf("转换后的字符串为: \n");
	for (i = 0; i <= getlen(s) - 1; i++)
		printf("%c", s[i]);
}

//转换时需要考虑负数
void itoa(int n, char s[])
{
	int i, sign;
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do
	{
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/*
求等比数列前n项和

*/
double getvalue(int value)
{
	double result = 0;
	int i = 2;
	if (value % 2 == 0)
	{
		while (i <= value)
		{
			result += 1.0 / i;
			i = i + 2;
		}
		return result;
	}
	else
		return 0.000000;
}


/*
实现strcmp
0:相等
1：str1 > str2
-1: str1 < str2
*/
int strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	if (*str1 && *str2)
		return (*str1 > *str2 ? 1 : -1);
	else if (*str1 && *str2 == 0)
		return 1;
	else if (*str1 == 0 && *str2)
		return -1;
	else
		return 0;

}

/*
实现strcpy
*/
char *stpy(char *dest, const char  *src)
{
	char *d = dest;
	while ((*d++ = *src) != '\0');
	return d;
}

int main(int argc, char *argv[])
{
//	int a;
//	char dest[30];
//	printf("请输入一个数字：\n");
//	scanf("%d", &a);
//	itoa(a, dest);

	
	//char str1[30];
	//char str2[20] = "I want a job";
	//char *a = strcpy(str1, str2);
	//printf("%s\n", a);

	system("pause");
	return 0;
}