#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int compare(const void* a, const void* b);
int main(void)
{
	int N, M, ans;
	int sum1 = 0;

	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d ", &arr[i]);
	scanf("%d", &M);

	//�������� ����
	qsort(arr, N, sizeof(int), compare);

	for (int i = 0; i < N; i++)
	{
		sum1 += arr[i];
	}

	//1������ - ��� ��û ������ �� �ִ� ���
	if(sum1<=M)
	{
		printf("%d", arr[N - 1]);
		exit(0);
	}


	//2������ - ��� ��û ������ �� ���� ���
	//�ʱ� ���Ѿ�(���)
	int avg = arr[N-1];
	int sum2 = 0;
	
	while (1)
	{
		for (int i = 0; i < N; i++)
		{
			if (arr[i] <= avg)
				sum2 += arr[i];
			else if (arr[i] >= avg)
				sum2 += avg;
		}
		//���Ѿ����� ����ؼ� �ѿ��꺸�� �۰ų� ������ ���Ѿ� ���
		if (sum2 <= M)
		{
			printf("%d", avg);
			break;
		}
		//�ѿ��꺸�� ũ�ٸ� ���Ѿ�-1
		else
		{
			avg--;
			sum2 = 0;
		}
	}




	return 0;
}
int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}