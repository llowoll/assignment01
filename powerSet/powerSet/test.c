#include <stdio.h>

void powerset(char* list, int num, int n)
{
	int i;
	int j;
	int cnt = 0;
	if (n == num)  // n==num(0) {} 공집합 출력
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

	powerset(list, num, n - 1);  //자기의 함수를 다시 호출(재귀함수 recursion)


}


int main(void)
{
	int i = 3;
	int j = 0;
	char list[3] = { 'x','y','z' };  //자료형 char인 크기가 3인 배열 a를 선언하고 'x','y','z'대입
	powerset(list, j, i);  //powerset함수호출,배열의 주소 전달 call-by-refenence
		 //int형 배열의크기 3 전달 call-by-value


	return 0;
}