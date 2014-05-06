#include<stdio.h>

int str_chnum(const char*, int);

int main(){
	char *str="Integer Float String";
	char c;

	int n;

	printf("検索する文字列は「%s」です。\n",str);

	printf("----------------------------\n");

	printf("文字を入力してください: ");
	scanf("%c",&c);

	n=str_chnum(str, c);

	if(n==0){
		printf("その文字は存在していません。\n");
	}else{
		printf("その文字は%d個存在しています。\n",n);
	}

	return 0;
}


int str_chnum(const char *str, int c){
	char *ptr=(char *)str;
	int n=0;


	while(*ptr!='\0'){
		if(*ptr==c){
			/* 文字が見つかるたびにカウントアップ */
			n++;
		}
		*ptr++;
	};

	return n;
}