#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int K;
	scanf("%d", &K);

	int c = 2;
	for(int i=0;i<21;i++)
	{
		if (c >= K)
			break;
		c *= 2;
		
	}
	
		
	int ansC = c;
	int cnt = 0;
	int ans = 0;
	
	while (1)
	{
		
		if (ans == K)	//2�� �����鼭 ans�� ���� ���� K�� ������ Ż��
			break;
		else if (ansC == K)	//���� c���� K�� ���ٸ� Ż��
			break;

		
		ansC = ansC / 2;	//��� 2�� ������
		if ((ans + ansC) > K)	//2�� ���� ���� ans�� ������ �� K������ Ŀ���� �Ѿ
		{
			cnt++;
			continue;
		}
		else
		{
			ans += ansC;	
			cnt++;
		}
		
	}

	printf("%d %d", c, cnt);

	return 0;
}