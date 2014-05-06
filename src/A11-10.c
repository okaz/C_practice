#include<stdio.h>

/*
	================ 注意 =====================
	stdlib.hをインクルードすると
	strtoi, strtol, strtof関数が競合してしまう。
*/

#define SLENGTH 255


int strtoi(const char*);
long strtol(const char*);
double strtof(const char*);

int is_number(char c);

char *input_string(char*, int);

int main()
{
	char st[SLENGTH];
	int i;
	int in;
	long l;
	double d;

	printf("文字を入力してください: ");
	if (input_string(st, SLENGTH) == NULL) {
		printf("エラー: 文字列の取得に失敗しました。\n");
		return 1;		
	}

	printf("----作成した関数------\n");

	in=strtoi(st);
	printf("strtoi(): %d\n",in);

	l=strtol(st);
	printf("strtol(): %d\n",l);

	d=strtof(st);
	printf("strtof(): %lf\n",d);

	printf("----ライブラリ関数----\n");

	printf("atoi(): %d\n",atoi(st));
	printf("atol(): %d\n",atol(st));
	printf("atof(): %lf\n",atof(st));

	return 0;
}

int strtoi(const char *nptr)
{
	char *ptr = (char *)nptr;
	long num = 0;

	num = (int)strtol(ptr);

	return num;
}

long strtol(const char *nptr)
{
	char *ptr = (char *)nptr;
	int sign;
	long num = 0;

	// 先頭の空白を無視するようにする
	while (*ptr == ' ')
		*ptr++;

	// 正負を調べる
	if (*ptr == '-') {
		sign = -1;
		*ptr++;
	} else if (*ptr == '+') {
		sign = 1;
		*ptr++;
	} else
		sign = 1;

	while (*ptr != '\0') {
		if (!(is_number(*ptr)))
			break;

		num *= 10;
		num += (int)*(ptr++) - 48;
	}

	return sign*num;
}

double strtof(const char *nptr)
{
	char *ptr = (char *)nptr;
	double inte = 0.0;
	double demi = 0.0;

	// 整数部の処理
	inte = (double)strtol(ptr);
	while (*ptr != '\0' && *ptr != '.') {
		if (!(is_number(*ptr)))
			return inte;

		*ptr++;
	}

	// 小数部の処理
	if (inte<0)
		*ptr='-';
	else
		*ptr='+';
	
	demi = (double)strtol(ptr++);
	while (*ptr != '\0' && *ptr != '.') {
		if (!(is_number(*ptr++)))
			return inte+demi;

		demi /= 10;
	}
	
	return inte + demi;
}

char *input_string(char *str,int n)
{
	char *ptr = (char*)str;

	if (fgets(str,n,stdin) == NULL)
		return NULL;


	/* 余計な改行文字を削除 */
	while (*ptr != '\n')
		*ptr++;
	*ptr = '\0';

	return str; // 文字列の先頭のポインタを返す
}

// 文字が数字かどうかを調べる
int is_number(char c)
{
	return c >= 48 && c <= 57;
}
