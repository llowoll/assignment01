#include<stdio.h>
#include<share.h>
#include<stdlib.h>

int cnt = 0;

void swapping(char* ele1, char* ele2) {
	char temp;

	temp = *ele1;
	*ele1 = *ele2;
	*ele2 = temp;
}

void printArray(char* charArray, int size,  FILE* writeFp) {
	for (int i = 0; i < size; i++) {
		fprintf_s(writeFp, "%c", charArray[i]);
	}
	fprintf_s(writeFp, "\n");
}

void permutation(char* charArray, int n, int size, int* cnt, FILE* writeFp) {
	if (n == 0) {
		(*cnt)++;
		fprintf_s(writeFp, "[%03d] ", *cnt);
		printArray(charArray, size, writeFp);
		return;
	}

	for (int i = 0; i < n ; i++) {
		swapping(&charArray[i], &charArray[n - 1]);
		permutation(charArray, n - 1, size, cnt, writeFp);
		swapping(&charArray[i], &charArray[n - 1]);
	}
}

int main(int argc, char* argv[]) {
	FILE* readFp = NULL;
	FILE* writeFp = NULL;

	char tempBuffer[20];
	int size;
	char* charArray = NULL;

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

	if (size > 6) {
		printf("������ ������ ���ġ�� �ʰ��Ͽ����ϴ�.");
		return 0;
	}

	charArray = (char*)malloc(sizeof(char)*size); // ù�ٿ� �ִ� ũ��� �����Ҵ�

	for (int i = 0; i < size; i++) { 
		fgets(tempBuffer, sizeof(tempBuffer), readFp);
		charArray[i] = tempBuffer[0];
	}

	permutation(charArray, size, size, &cnt, writeFp);

	fprintf_s(writeFp, "\n**************");
	fprintf_s(writeFp, "\n*20191242*");
	fprintf_s(writeFp, "\n*Lim Chanyeong*");
	fprintf_s(writeFp, "\n**************\n");

	// ���� �ݱ�
	fclose(readFp);
	fclose(writeFp);

	free(charArray);

	return 0;
}