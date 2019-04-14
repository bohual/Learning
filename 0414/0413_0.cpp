#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <malloc.h>

#define ARRAY_LENGTH 50

//将一个字符串反转(指针）
void RevertStringP()
{
	char src[50] ;
	printf("请输入需要反转的字符串: \n");
	//scanf("%s", src);
	gets_s(src,ARRAY_LENGTH);
	printf("成功输入字符串: %s\n", src);

	//反转字符串
	int	len = strlen(src);
	printf("字符串的长度为: %d\n", len);
	char *dest = (char *)malloc(len + 1);
	char *s = &src[len - 1];
	char *d = dest;
	while (len-- != 0)
		*d++ = *s--;
	*d = '\0';
	printf("反转后的字符串为: %s\n", dest);
	free(dest);
	return;

}

void Reverse(char *str)
{
	int length = strlen(str);
	char *p1 = str;
	char *p2 = str + length - 1;
	while (p1 < p2)
	{
		char c = *p1;
		*p1 = *p2;
		*p2 = c;
		++p1;
		--p2;
	}
}

//将一个字符串反转（数组）
void RevertStringA()
{
	char src[50];
	printf("请输入需要反转的字符串: \n");
	//scanf("%s", src);
	gets_s(src, ARRAY_LENGTH);
	printf("成功输入字符串: %s\n", src);

	//反转字符串
	int	len = strlen(src);
	printf("字符串的长度为: %d\n", len);
	char temp;
	for (int i = 0; i < len / 2; i++)
	{
		temp = src[i];
		src[i] = src[len - 1 - i];
		src[len - 1 - i] = temp;
	}

	printf("反转后的字符串为: %s\n", src);
	return;
}


//将一个字符串反转（递归）
void Inverse(const char *p)
{
	if (*p == '\0')
		return;
	Inverse(p + 1);
	printf("%c", *p);
	return;

}

//交换两个变量的值，不使用第三个变量
void Swap()
{
	int a, b;
	printf("请输入需要交换的两个数值： \n");
	scanf("%d %d", &a,&b);
	printf("输入的数值为：a = %d, b = %d\n", a, b);

	//交换
	/* //算数
	a = a + b;
	b = a - b;
	a = a - b;
	*/
	//异或
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("交换后的数据为: a = %d, b = %d\n", a, b);
}

/*
对绝对地址0x100000赋值且想让程序跳转到绝对地址是0x100000处执行
(unsigned int *)0x100000 = 1234;
(void(*)())0x100000
*((void(*)())0x100000)()

typedef void(*)() voidFuncptr;
*(voidFuncPtr)0x100000)();
*/

//统计一个数的二进制有多少个1
void CountOne()
{
	int Num;
	printf("请输入需要统计的数: \n");
	scanf("%d", &Num);

	//统计
	int count = 0;
	while (Num)
	{
		count++;
		Num = Num & (Num - 1);
	}
	printf("输入数的二进制中含有 %d 个 1\n", count);
}

//读文件file1.txt内容到file2.txt
void ReadFile()
{
	int i, j = 0;
	int MAX = 10;
	int *a = (int *)malloc(MAX * sizeof(int));
	int *b;
	FILE *fp1;
	FILE *fp2;
	fp1 = fopen("a.txt", "r");
	if (fp1 == NULL)
	{
		printf("open error1\n");
		exit(-1);
	}
	fp2 = fopen("b.txt", "w");
	if (fp2 == NULL)
	{
		printf("open error2\n");
		exit(-1);
	}
	while (fscanf(fp1, "%d", &a[i]) != EOF)
	{
		i++;
		j++;
		if (i >= MAX)
		{
			b = (int *)realloc(a, MAX * sizeof(int));
			if (b == NULL)
			{
				printf("realloc error\n");
				exit(-1);
			}
		}
	}
	for (; --j >= 0;)
	{
		fprintf(fp2, "%d\n", a[j]);
	}
	fclose(fp1);
	fclose(fp2);
	return;
}

//输出和为一个给定整数的所有组合
void total()
{
	unsigned long int i, j, k;
	printf("请输入一个整数\n");
	scanf("%d", &i);

	if (i % 2 == 0)
		j = i / 2;
	else
		j = i / 2 + 1;
	printf("输出的结果为：\n");
	for (k = 0; k < j; k++)
		printf("%d = %d + %d\n", i, k, i - k);
	return;
}


