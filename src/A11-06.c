#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SLENGTH 255

void str_toupper(const char*);
void str_tolower(const char*);

char *input_string(char*,int);

int main(){
	char *st[2];
	int i;

	for(i=0;i<2;i++){
		/* ポインタを利用する場合は予めメモリを確保する。 */
		if((st[i]=(char *)malloc(sizeof(char)*SLENGTH))==NULL){
			printf("エラー: メモリが確保できません。\n");
			exit(1);
		}

		printf("%dつ目の文字列を入力してください: ",i+1);
		if(input_string(st[i],SLENGTH)==NULL){
			printf("エラー: 文字列の取得に失敗しました。\n");
			exit(1);		
		}
	}

	str_toupper(st[0]);
	printf("  1つ目の文字列を全て大文字に変えると\n");
	printf("%sとなります。\n",st[0]);

	str_tolower(st[1]);
	printf("  2つ目の文字列を全て小文字に変えると\n");
	printf("%sとなります。\n",st[1]);

	return 0;
}


void str_toupper(const char *str){
	char *ptr=(char *)str;

	while(*ptr!='\0'){
		if(*ptr>=97&&*ptr<=122){
			*ptr-=32;
		}
		*ptr++;
	}
}

void str_tolower(const char *str){
	char *ptr=(char *)str;

	while(*ptr!='\0'){
		if(*ptr>=65&&*ptr<=90){
			*ptr+=32;
		}
		*ptr++;
	}
}

char *input_string(char *str,int n){
	char *ptr=(char*)str;

	if(fgets(str,n,stdin)==NULL){
		return NULL;
	}

	/* 余計な空白文字を削除 */
	while(*ptr!='\n'){
		*ptr++;
	}
	*ptr='\0';

	return str; // 文字列の先頭のポインタを返す
}