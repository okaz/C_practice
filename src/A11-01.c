#include<stdio.h>

int main(){
	char str[3]="ARY";
	char *ptr="PTR";

	printf("配列strに格納されている文字列は%sです。\n",str);
	printf("ポインタptrが指している文字列は%sです。\n",ptr);

	return 0;
}