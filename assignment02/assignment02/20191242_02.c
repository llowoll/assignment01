#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int i;
	char* tempString;
	int temp = 0, result = 0;

	for (i = 1; i < argc; i++) {
		if (i > 201) // ������ ���� ���� 100���� �Ѿ�� �ݺ� �ߴ�
			break;
		if (!strcmp(argv[i], "+")) { // ���� ���ڰ� +�� ���
			temp = atoi(argv[i+1]); // ���ڹ迭�� ���������� ��ȯ
			result += temp; // result������ ����
		}
		if (!strcmp(argv[i], "-")) { // ���� ���ڰ� -�� ���
			temp = atoi(argv[i+1]); // ���ڹ迭�� ���������� ��ȯ
			result -= temp; // result������ ����
		}
	}
	printf("%d", result); // ��� ���

	printf("\n**************"); // ������ ���� ���
	printf("\n*20191242*"); // �й�
	printf("\n*Lim Chanyeong*"); // �̸�
	printf("\n**************\n");
}