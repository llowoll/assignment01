#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int i;
	char* tempString;
	int temp = 0, result = 0;

	for (i = 1; i < argc; i++) {
		if (i > 201) // 연산자 정수 쌍이 100개를 넘어가면 반복 중단
			break;
		if (!strcmp(argv[i], "+")) { // 이전 인자가 +일 경우
			temp = atoi(argv[i+1]); // 문자배열을 정수형으로 변환
			result += temp; // result변수에 누산
		}
		if (!strcmp(argv[i], "-")) { // 이전 인자가 -일 경우
			temp = atoi(argv[i+1]); // 문자배열을 정수형으로 변환
			result -= temp; // result변수에 누산
		}
	}
	printf("%d", result); // 결과 출력

	printf("\n**************"); // 저작자 사인 출력
	printf("\n*20191242*"); // 학번
	printf("\n*Lim Chanyeong*"); // 이름
	printf("\n**************\n");
}