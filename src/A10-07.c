#include<stdio.h>

int main(){
	int *ptr;
	int vc[5]={11,22,33,44,55};
	int i;

	ptr = &vc[0];

	printf("配列の要素の値を表示します。\n\n");

	printf("====添字演算子 [] を適応した場合====\n");
	for(i=0;i<5;i++){
		printf("%d番目の数値: %d\n",i+1, vc[i]);
	}


	printf("====間接演算子 * を適応した場合=====\n");
	for(i=0;i<5;i++){
		printf("%d番目の数値: %d\n",i+1, *(ptr+i));
	}

	return 0;
}