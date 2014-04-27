#include<stdio.h>

int main(){
	int a=45,b=876;
	int *p,*r;
	int temp;

	printf("変数a: %d\n",a);
	printf("変数b: %d\n",b);

	printf("ポインタを用いて上記の変数の値を交換します。\n");

	p = &a; /* 変数aのポインタを*pに記憶 */
	r = &b; /* 変数bのポインタを*rに記憶 */

	/* ポインタ変数p,rを利用して変数aと変数bの値を交換する */
	temp = a;
	*p = b;
	*r = temp;

	printf("変数a: %d\n",a);
	printf("変数b: %d\n",b);

	return 0;
}