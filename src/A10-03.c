#include<stdio.h>

void sum_diff_mul(int,int,int*,int*,int*);

int main(){
	int n1,n2;
	int sum,diff,mul;

	printf("n1の値: "); scanf("%d",&n1);
	printf("n2の値: "); scanf("%d",&n2);

	sum_diff_mul(n1, n2, &sum, &diff, &mul);

	printf("n1とn2の和: %d\n",sum);
	printf("n1とn2の差: %d\n",diff);
	printf("n1とn2の積: %d\n",mul);

	return 0;
}

void sum_diff_mul(int n1, int n2, int *sum, int *diff, int *mul){
	*sum  = n1+n2;
	*diff = n1-n2;
	*mul  = n1*n2;
}
