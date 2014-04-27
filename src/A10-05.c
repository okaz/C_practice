#include<stdio.h>

void sort2(int*,int*);

int main(){
	int n[2];
	int i;

	for(i=0;i<2;i++){
		printf("%dつ目の整数: ",i+1); scanf("%d",&n[i]);
	}

	sort2(&n[0],&n[1]);

	printf("2つの整数を昇順に並べると%d,%dの順になります。\n",n[0],n[1]);

	return 0;
}

void sort2(int *n1,int *n2){
	int temp;

	if(*n1>*n2){
		/* 値を入れ替えることで2つの整数を昇順に並べる */
		temp=*n1;
		*n1=*n2;
		*n2=temp;
	}
}