#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <malloc.h>

#define ARRAY_LENGTH 50

//��һ���ַ�����ת(ָ�룩
void RevertStringP()
{
	char src[50] ;
	printf("��������Ҫ��ת���ַ���: \n");
	//scanf("%s", src);
	gets_s(src,ARRAY_LENGTH);
	printf("�ɹ������ַ���: %s\n", src);

	//��ת�ַ���
	int	len = strlen(src);
	printf("�ַ����ĳ���Ϊ: %d\n", len);
	char *dest = (char *)malloc(len + 1);
	char *s = &src[len - 1];
	char *d = dest;
	while (len-- != 0)
		*d++ = *s--;
	*d = '\0';
	printf("��ת����ַ���Ϊ: %s\n", dest);
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

//��һ���ַ�����ת�����飩
void RevertStringA()
{
	char src[50];
	printf("��������Ҫ��ת���ַ���: \n");
	//scanf("%s", src);
	gets_s(src, ARRAY_LENGTH);
	printf("�ɹ������ַ���: %s\n", src);

	//��ת�ַ���
	int	len = strlen(src);
	printf("�ַ����ĳ���Ϊ: %d\n", len);
	char temp;
	for (int i = 0; i < len / 2; i++)
	{
		temp = src[i];
		src[i] = src[len - 1 - i];
		src[len - 1 - i] = temp;
	}

	printf("��ת����ַ���Ϊ: %s\n", src);
	return;
}


//��һ���ַ�����ת���ݹ飩
void Inverse(const char *p)
{
	if (*p == '\0')
		return;
	Inverse(p + 1);
	printf("%c", *p);
	return;

}

//��������������ֵ����ʹ�õ���������
void Swap()
{
	int a, b;
	printf("��������Ҫ������������ֵ�� \n");
	scanf("%d %d", &a,&b);
	printf("�������ֵΪ��a = %d, b = %d\n", a, b);

	//����
	/* //����
	a = a + b;
	b = a - b;
	a = a - b;
	*/
	//���
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("�����������Ϊ: a = %d, b = %d\n", a, b);
}

/*
�Ծ��Ե�ַ0x100000��ֵ�����ó�����ת�����Ե�ַ��0x100000��ִ��
(unsigned int *)0x100000 = 1234;
(void(*)())0x100000
*((void(*)())0x100000)()

typedef void(*)() voidFuncptr;
*(voidFuncPtr)0x100000)();
*/

//ͳ��һ�����Ķ������ж��ٸ�1
void CountOne()
{
	int Num;
	printf("��������Ҫͳ�Ƶ���: \n");
	scanf("%d", &Num);

	//ͳ��
	int count = 0;
	while (Num)
	{
		count++;
		Num = Num & (Num - 1);
	}
	printf("�������Ķ������к��� %d �� 1\n", count);
}

//���ļ�file1.txt���ݵ�file2.txt
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

//�����Ϊһ�������������������
void total()
{
	unsigned long int i, j, k;
	printf("������һ������\n");
	scanf("%d", &i);

	if (i % 2 == 0)
		j = i / 2;
	else
		j = i / 2 + 1;
	printf("����Ľ��Ϊ��\n");
	for (k = 0; k < j; k++)
		printf("%d = %d + %d\n", i, k, i - k);
	return;
}


