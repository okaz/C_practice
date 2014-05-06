#include<stdio.h>

#define NUMBER 5

void one_two_three(int*);

void print_array(int*);

int main()
{
	int vc[NUMBER]={9,8,7,6,5};

	printf("配列の要素は、");
	print_array(vc);
	printf("です。\n");

	printf("配列の先頭3つの要素から1, 2, 3を代入します。\n");
	one_two_three(vc);

	printf("配列の要素は、");
	print_array(vc);
	printf("です。\n");

	return 0;
}

void one_two_three(int vc[])
{
	int i;

	for(i=0;i<3;i++){
		*(vc+i)=i+1;
	}

}

void print_array(int vc[])
{
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