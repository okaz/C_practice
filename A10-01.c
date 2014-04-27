#include <stdio.h>

int main(){
	static int x = 0;

	printf("静的記憶域期間が与えられた\nオブジェクトxのアドレスは%dです。\n",&x);

	return 0;
}