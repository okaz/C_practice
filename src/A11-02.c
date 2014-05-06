#include<stdio.h>

#define NUMBER 3


int main(){
	char str[NUMBER][255]={"star","moon","sun"}; // 配列で実現した文字列の配列
	char *ptr[NUMBER]={"abc","def","xyz"};  // ポインタで実現した文字列の配列
	int i;

	printf("=====配列で実現した文字列の配列===========\n");
	for(i=0;i<NUMBER;i++){
		printf("%d番目の文字列: %s\n",i+1,str[i]);
	}


	printf("=====ポインタでで実現した文字列の配列=====\n");
	for(i=0;i<NUMBER;i++){
		printf("%d番目の文字列: %s\n",i+1,ptr[i]);
	}

	return 0;
}
