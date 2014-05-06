#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SLENGTH 255

int str_equal(const char*, const char*);

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

	if(str_equal(st[0],st[1])){
		printf("これらの2つの文字列は一致しています。\n");
	}else{
		printf("これらの2つの文字列は一致していません。\n");
	}

	return 0;
}


int str_equal(const char *st1, const char *st2){
	char *pt1=(char *)st1;
	char *pt2=(char *)st2;

	while(*pt1==*pt2&&*pt1!='\0'){
		*pt1++; *pt2++;
	};

	if(*pt1=='\0'&&*pt2=='\0'){
	/* 一致するとき */
		return 1;
	}else{
	/* 一致していないとき */
		return 0;
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