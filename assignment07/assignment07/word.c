#include <stdio.h>
#include <string.h>
#include<share.h>

#define MAX_WORD 35000
#define MAX_LEN 25

int main(int argc, char* argv[])
{
	FILE* readFp = NULL;
	FILE* writeFp = NULL;

	char tempBuffer[1000];
	char dictionary[MAX_WORD][MAX_LEN];
	int wordnum[MAX_WORD];
	int isEnter = 1;

	int toknum = 0;
	int cnt = 0;
	char delimiters[65] = "";
	char * context = NULL;

	if (argv[1] == NULL || argv[2] == NULL) {
		printf("파일 이름을 적어주세요.");
		return 0;
	}
	else if ((readFp = _fsopen(argv[1], "r", _SH_DENYNO)) == NULL) {
		printf("파일을 여는 것에 실패하였습니다.");
		return 0;
	}
	else if ((writeFp = _fsopen(argv[2], "wt", _SH_DENYNO)) == NULL) {
		printf("파일을 여는 것에 실패하였습니다.");
		return 0;
	}

	for (int i = 0; i < MAX_WORD; i++) {
		wordnum[i] = 1;
		dictionary[i][0] = NULL;
	}

	for (int i = 1; i <= 127; i++) {
		if ((i >= 48 && i <= 57))
			continue;
		else if (i >= 65 && i <= 90)
			continue;
		else if (i >= 97 && i <= 122)
			continue;
		delimiters[cnt++] = (char)i;
	}

	while(1) {
		fgets(tempBuffer, sizeof(tempBuffer), readFp);

		if (tempBuffer[0] == NULL) {
			break;
		}

		if (tempBuffer[0] == '\n') {
			continue;
		}

		char *token = strtok_s(tempBuffer, delimiters, &context);

		while (token != NULL) {

			isEnter = 1;

			for (int i = 0; i < sizeof(token); i++) {
				if (token[i] >= 'A'&&token[i] <= 'Z') {
					token[i] = token[i] + 32;
				}
			}

			for (int i = 0; i < toknum; i++) { // 사전에 단어가 있는지 확인
				if (strcmp(dictionary[i], token) == 0) {
					wordnum[i]++;
					isEnter = 0;
				}
			}

			if (isEnter && toknum < MAX_WORD) {
				strcpy_s(dictionary[toknum++], MAX_LEN, token);
			}

			token = strtok_s(NULL, delimiters, &context);
		}

		for (int i = 0; i < 1000; i++) {
			tempBuffer[i] = NULL;
		}
	}

	int count = 0;

	while (dictionary[count][0]!=NULL && count< MAX_WORD) {
		fprintf_s(writeFp, "[%05d] %s (%d)\n", (count+1), dictionary[count], wordnum[count]);
		count++;
	}

	int total = 0;
	count = 0;

	while (dictionary[count][0] != NULL && count < MAX_WORD) {
		total += wordnum[count];
		count++;
	}

	fprintf_s(writeFp, "[total] %08d\n", total);

	fprintf_s(writeFp, "\n**************");
	fprintf_s(writeFp, "\n*20191242*");
	fprintf_s(writeFp, "\n*Lim Chanyeong*");
	fprintf_s(writeFp, "\n**************\n");

	fclose(readFp);
	fclose(writeFp);

	return 0;
}
