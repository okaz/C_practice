#include<stdio.h>

void sort3(int*,int*,int*);

int main(){
	int n[3];
	int i;

	for(i=0;i<3;i++){
		printf("%dつ目の整数: ",i+1); scanf("%d",&n[i]);
	}

	sort3(&n[0],&n[1],&n[2]);

	printf("3つの整数を昇順に並べると%d,%d,%dの順になります。\n",n[0],n[1],n[2]);

	return 0;
}

void sort3(int *n1,int *n2,int *n3){
/* バブルソートの要領で並び替える */
	int temp;


	if(*n1>*n2){
		/* 値を入れ替えることで2つの整数を昇順に並べる */
		temp=*n1;
		*n1=*n2;
		*n2=temp;
	}

	if(*n2>*n3){
		temp=*n2;
		*n2=*n3;
		*n3=temp;
		if(*n1>*n2){
			temp=*n1;
			*n1=*n2;
			*n2=temp;
		}

	}

}