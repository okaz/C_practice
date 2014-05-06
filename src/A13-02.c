#include <stdio.h>

int main(){
	FILE *fp;
	char fname[255];

	printf("ファイル名を入力: ");
	if(fgets(fname,255,stdin) == NULL) {
		printf("エラー: 文字の取得に失敗しました。\n");
		exit(1);
	}

	if(fp = fopen(fname,"r") == NULL) {
		printf("そのファイルは存在しません。\n");
		exit(1);
	} else {
		printf("そのファイルは存在します。\n");
	}

	fclose(fp);

	return 0;
}