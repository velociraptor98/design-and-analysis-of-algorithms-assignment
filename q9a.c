#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<limits.h>
int **arr;
int **brr;
int n;
void bmul()
{
	int **c = (int**)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		c[i] = (int*)calloc(n, sizeof(int));
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				sum += arr[i][k] * brr[k][j];
			}
			c[i][j] = sum;
			sum = 0;
		}
		
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}

			

int main()
{
	srand(time(0));
	printf("enter the size of the n*n matrix : ");
	scanf("%d", &n);
	arr= (int)calloc(n , sizeof(int));
	brr = (int)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int)calloc(n ,sizeof(int));
		brr[i] = (int)calloc(n, sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 10000;
			brr[i][j] = rand() % 10000;
		}
	}
	time_t s, e, s1, e1;
	s = clock();
	bmul();
	e = clock();
	s1 = clock();
	//bmus();
	e1 = clock();
}