#include<stdio.h>

char *str_chr(const char*, int);

int main(){
	char *str="String";
	char c;

	char *c1;

	printf("検索する文字列は「%s」です。\n",str);

	printf("----------------------------\n");

	printf("文字を入力してください: ");
	scanf("%c",&c);

	c1=str_chr(str, c);

	if(c1==NULL){
		printf("その文字は存在していません。\n");
	}else{
		printf("その文字は%d番目に存在しています。\n",c1-str);
	}

	return 0;
}


char *str_chr(const char *str, int c){
	char *ptr=(char *)str;

	while(*ptr!='\0'&&*ptr!=c){
		*ptr++;
	};

	if(*ptr==c){
		/* 見つかった場合 */
		return ptr;
	}else{
		/* 見つからなかった場合 */
		return NULL;	
	}
}