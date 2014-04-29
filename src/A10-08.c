#include<stdio.h>
#include<math.h>
#include<string.h>

#define NUMBER 10

int comp(int*,int,int);
int diff(int*,int,int);

void print_array(int*);

int main(){
	int vc[10]={50,10,20,30,40,50,60,70,80,30};
	int a,b;
	int com,dif;

	printf("配列の要素は\n");
	print_array(vc);
	printf("\nです。\n");

	printf("========================================\n");

	printf("1つ目の要素の番号(1から10まで): ");
	scanf("%d",&a);

	printf("2つ目の要素の番号(1から10まで): ");
	scanf("%d",&b);

	com=comp(vc,a-1,b-1);
	dif=diff(vc,a-1,b-1);

	printf("----------------------------------------\n");

	if(com==1){
		printf("%d番目の要素の方が%d番目の要素よりも大きいです。\n",a,b);
	}else if(com==0){
		printf("%d番目の要素と%d番目の要素は同じです。\n",a,b);
	}else{
		printf("%d番目の要素の方が%d番目の要素よりも大きいです。\n",b,a);
	}

	printf("そして、この2つの要素の値の差は%dです。\n",abs(dif));

	return 0;
}

int comp(int vc[],int a,int b){

	if(*(vc+a)>*(vc+b)){
		return 1;
	}else if(*(vc+a)==*(vc+b)){
		return 0;
	}else{
		return -1;
	}
}

int diff(int vc[],int a,int b){

	return *(vc+a)-*(vc+b);
}

void print_array(int vc[]){
	int i;

	printf("[");
	for(i=0;i<NUMBER;i++){
		printf("%d",*(vc+i));
		if(i!=NUMBER-1){
			printf(",");
		}
	}
	printf("]");

}