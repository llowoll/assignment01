#include<stdio.h>
#include<share.h>
#include<stdlib.h>

int recursiveSum(int point, int* psize, int* intArray) {
	if (*psize <= (point-1))
		return 0;
	else {
		--(*psize);
		return intArray[*psize] + recursiveSum(point, psize, intArray);
	}
}

int main(int argc, char* argv[]) {
	FILE* readFp = NULL;
	FILE* writeFp = NULL;

	char tempBuffer[20];
	int size;
	int point;
	int* psize;
	int* intArray = NULL;

	if (argv[1] == NULL || argv[2] == NULL) {
		printf("���� �̸��� �����ּ���.");
		return 0;
	}
	else {
		
		if ((readFp = _fsopen(argv[1], "r", _SH_DENYNO)) == NULL) {
			printf("������ ���� �Ϳ� �����Ͽ����ϴ�.");
			return 0;
		}
		
		if ((writeFp = _fsopen(argv[2], "wt", _SH_DENYNO)) == NULL) {
			printf("������ ���� �Ϳ� �����Ͽ����ϴ�.");
			return 0;
		}
	}
	
	fgets(tempBuffer, sizeof(tempBuffer), readFp);
	size = atoi(tempBuffer);

	psize = &size;
	
	intArray = (int*)malloc(sizeof(int)*size); // ù�ٿ� �ִ� ũ��� �����Ҵ�

	for (int i = 0; i < size; i++) { // ù�ٿ� �ִ� ũ��� ���� �ޱ�
		fgets(tempBuffer, sizeof(tempBuffer), readFp);
		intArray[i] = atoi(tempBuffer);
	}

	for (int i = size; i > 0; i--) {
		size = 15;
		point = i;
		fprintf_s(writeFp, "[%04d] %d \n", i, recursiveSum(point, psize, intArray));
	}

	fprintf_s(writeFp, "\n**************");
	fprintf_s(writeFp, "\n*20191242*");
	fprintf_s(writeFp, "\n*Lim Chanyeong*");
	fprintf_s(writeFp, "\n**************\n");

	// ���� �ݱ�
	fclose(readFp);
	fclose(writeFp);

	// �޸� ����
	free(intArray);

	return 0;
}