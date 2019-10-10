#include <stdio.h>

wchar_t *emptySet = L"\u2205"; //유니코드를 찾아서 해보았지만 안됐습니다

void subset(char* set[], int n) {

	if (n == 0) {
		printf("[%04d] %c", 1, 155); //교수님이 주신 ascii코드값 사용(하지만 안됨)
		wprintf(L"%s", emptySet); //유니코드로 시도(하지만 안됨)
		printf("\n");
	}
	else{
		int pow = 1 << n;

		int i, j;

		for (i = 0; i < pow; i++) {
			printf("[%04d]", i + 1);

			if (i == 0) {
				wprintf(L" %s", emptySet);
			}

			for (j = 0; j < n; j++) {
				if (i & (1 << j)) printf(" %s,", set[j]);
			}
			printf("\n");
		}
	}

}



int main(int argc, char* argv[]) {
	char* set[10] = { "0" };

	for (int i = 1; i < argc; i++) {
		set[i - 1] = argv[i];
	}
	subset(set, argc - 1);

}