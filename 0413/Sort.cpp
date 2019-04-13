#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#define ElementType int
void print(ElementType a[], ElementType n)
{
	for (ElementType i = 0; i < n; i++)
	{
		printf("%d\n", a[i]);
	}
}

void bubble(ElementType a[], ElementType n)
{
	ElementType i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				ElementType temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void InsertSort(ElementType a[], ElementType n)
{
	int j, p;
	ElementType temp;
	for (p = 1; p < n; p++)
	{
		temp = a[p];
		for (j = p; j > 0 && a[j - 1] < temp; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}
}

void ShellSort(ElementType a[], int n)
{
	int i, j, Increment;
	ElementType temp;
	for (Increment = n / 2; Increment > 0; Increment /= 2)
	{
		for (i = Increment; i < n; i++)
		{
			temp = a[i];
			for (j = i; j >= Increment; j -= Increment)
			{
				if (temp < a[j - Increment])
				{
					a[j] = a[j - Increment];
				}
				else
					break;
			}
			a[j] = temp;
		}
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int low, int high)
{
	int key = a[low];
	while (low < high)
	{
		while (low < high && key <= a[high])
			high--;
		swap(&a[low], &a[high]);
		while (low < high && key >= a[low])
			low++;
		swap(&a[low], &a[high]);
	}
	return low;
}

void QuickSort(int a[], int low, int high)
{
	int pos = partition(a, low, high);
	if (low < high)
	{
		QuickSort(a, low, pos - 1);
		QuickSort(a, pos + 1, high);
	}
}

int SelectKey(int a[], int n, int i)
{
	int k = i;
	for (int j = i + 1; j < n; j++)
	{
		if (a[j] > a[k])
			k = j;
	}
	return k;
}

void SelectSort(int a[],int n)
{
	int key;
	for (int i = 0; i < n; i++)
	{
		key = SelectKey(a, n, i);
		if (key != i)
		{
			int temp = a[i];
			a[i] = a[key];
			a[key] = temp;
		}
	}
}

void MergeSort(int a[], int af[], int i, int m, int n)
{
	int k, j;
	for (k = i, j = m + 1; i <= m && j <= n; k++)
	{
		if (a[i] < a[j])
			af[k++] = a[j++];
		else
			af[k++] = a[i++];
	}
	while (i <= m)
		af[k++] = a[i++];
	while (j <= n)
		af[k++] = a[j++];
}

int main()
{
	ElementType a[] = { 1,3,4,6,9,2,0,5,8,7,11 };
	int n = sizeof(a) / sizeof(a[0]);
	int *b = (int *)malloc(sizeof(a[0]) * n);
	MergeSort(a,b, 0,5,n);
	print(a, n);
	system("pause");
	return 0;
}