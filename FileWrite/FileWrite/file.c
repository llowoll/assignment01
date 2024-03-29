#include <stdio.h>
#include <share.h>

void subset(char* set[], int n, FILE* fp) {

	if (n == 0) {
		fprintf_s(fp, "[%04d] ", 1);
		fprintf_s(fp, "%c", 0x2205);
		printf("\n");
	}
	else {
		int pow = 1 << n;

		int i, j;
		
		for (i = 0; i < pow; i++) {
			fprintf_s(fp, "[%04d]", i + 1);

			if (i == 0) {
				fprintf_s(fp, " %c", 0x2205);
			}

			for (j = 0; j < n; j++) {
				if (i & (1 << j)) fprintf_s(fp, " %s,", set[j]);
			}
			fprintf_s(fp, "\n");
		}
	}

}

int main(int argc, char* argv[]) {
	char* set[10] = { "0" };
	FILE* fp;

	if (argv[1] == NULL)
		printf("파일 이름을 적어주세요.");
	else {
		if ((fp = _fsopen(argv[1], "w", _SH_DENYNO)) == NULL) {
			printf("파일을 여는 것에 실패하였습니다.");
			return 0;
		}

		for (int i = 2; i < argc; i++) {
			set[i - 2] = argv[i];
		}

		subset(set, argc - 2, fp);

		fprintf_s(fp, "\n**************");
		fprintf_s(fp, "\n*20191242*");
		fprintf_s(fp, "\n*Lim Chanyeong*");
		fprintf_s(fp, "\n**************\n");

		fclose(fp);
	}

	return 0;
}