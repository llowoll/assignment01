#include<stdio.h>

int combination(int n, int r) {
	if (n == r || r == 0)
		return 1;
	else
		return combination(n - 1, r - 1) + combination(n - 1, r);
}


int main(int argc, char* argv[]) {
	char* tempArr[1024];
	wchar_t *emptySet = L"\u2205";

	if (argc == 1) {
		printf("[%04d] %c", 1 , 155);
		wprintf(L"%s", emptySet);
		printf("\n");
	}
	else if (argc > 11)
		printf("최대 인자 개수인 10을 초과하였습니다."); 
	else{
		/*
		for (int i = 1; i <= argc; i++) {
			printf("[%04d]", i);
			printf("\n");
		}
		*/
		for (int i = 1; i < argc; i++) {

			for (int j = 1; j <= combination(argc-1, i); j++) {
				for (int k = 0; k < i; k++) {
					if (i > 1 && k < i - 1) {
						printf(" %s,", argv[j + k]);
					}
					else if (i > 1 && k == i-1) {
						printf(" %s\n", argv[j + k]);
					}
					else if (i == 1) {
						printf(" %s\n", argv[j + k]);
					}
				}
			}

		}
	}
	
}