#include<stdio.h>
#include<stdlib.h>

#define SLENGTH 255

void del_digit(const char*);

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

	del_digit(str);
	printf("%s\n",str); //put_rstring関数では改行されない

	return 0;
}


void del_digit(const char *st){
	char *ptr=(char *)st;
	char *temp=(char *)st;

	// 数字の部分を先に出てきた数字以外の文字に置き換える
	while(*temp!='\0'){
		while(*temp>=48&&*temp<=57){
			*temp++; // 数字以外の文字が出てくるまで進める
		}
		*ptr++=*temp++;
	};

	// 余った部分を終端文字'\0'で埋める
	while(*ptr!='\0'){
		*ptr++='\0';
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