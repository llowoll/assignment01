#include <stdio.h>

void powerset(char* list, int num, int n)
{
	int i;
	int j;
	int cnt = 0;
	if (n == num)  // n==num(0) {} ������ ���
		printf(" {}\n");

	else if (n == 3)
	{
		for (i = 0; i < n; i++)
		{
			printf("{%c}%s", list[i], (i == n-1) ? "\n" : ", ");
		}
	}
	else if (n == 2)
	{
		for (i = 0; i < n + 1; i++)
		{
			for (j = 0; j < n + 1; j++) {
				if (i != j) {
					printf("%c", list[j]);
					cnt++;
				}
				if (cnt % 2 == 0 && cnt!=0) {
					printf("%s", (i == n) ? "\n" : ", ");
				}
			}
		
		}
	}
	else if (n == 1)
	{
		for (i = 0; i < n + 2; i++)
		{
			printf("%c%s", list[i], (i == n + 1) ? "\n" : ", ");
		}
	}

	powerset(list, num, n - 1);  //�ڱ��� �Լ��� �ٽ� ȣ��(����Լ� recursion)


}


int main(void)
{
	int i = 3;
	int j = 0;
	char list[3] = { 'x','y','z' };  //�ڷ��� char�� ũ�Ⱑ 3�� �迭 a�� �����ϰ� 'x','y','z'����
	powerset(list, j, i);  //powerset�Լ�ȣ��,�迭�� �ּ� ���� call-by-refenence
		 //int�� �迭��ũ�� 3 ���� call-by-value


	return 0;
}