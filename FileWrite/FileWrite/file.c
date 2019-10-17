#include <stdio.h>

void subset(char* set[], int n) {

	if (n == 0) {
		wprintf(L"[%04d] ∅", 1);
		//wprintf(L"[%04d] %c", 1, \u2205);
		printf("\n");
	}
	else {
		int pow = 1 << n;

		int i, j;

		for (i = 0; i < pow; i++) {
			printf("[%04d]", i + 1);

			if (i == 0) {
				wprintf(L"∅");
				//wprintf(L"[%04d] %c", 1, \u2205);
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