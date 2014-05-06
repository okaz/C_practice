#include<stdio.h>
#include<stdlib.h>

#define SLENGTH 255

void put_rstring(const char*);

char *input_string(char*,int);

int main(){
	char *str;
	char c;
	char *temp;

	/* ポインタを利用する場合は予めメモリを確保する。 */
	if((str=(char *)malloc(sizeof(char)*SLENGTH))==NULL){
		printf("エラー: メモリが確保できません。\n");
		exit(1);
	}

	printf("文字を入力してください: ");

	if(input_string(str,SLENGTH)==NULL){
		printf("エラー: 文字列の取得に失敗しました。\n");
		exit(1);		
	}

	put_rstring(str);
	printf("\n"); //put_rstring関数では改行されない

	return 0;
}


void put_rstring(const char *st){
	char *ptr=(char *)st;
	int n=0;
	int i;

	/* 文字数を数える */
	while(*ptr!='\0'){
		n++;
		*ptr++;
	};

	/* 文字列を逆さに表示 */
	for(i=0;i<n+1;i++){
		printf("%c",*(ptr--));
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