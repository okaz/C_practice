#include<stdio.h>
#include<string.h>
#include<time.h>

void put_time(void);

char *meridian_to_ja(char*);

int main ()
{
	put_time();

	return 0;
}

void put_time(void)
{
	time_t now;
	struct tm *ts;
	char t[80];
	char twh[5];

	now = time(NULL);

	ts = localtime(&now);
	strftime(t, sizeof(t), "%I時%M分", ts);
	strftime(twh, sizeof(t), "%p",ts);
	printf("現在の時刻は%s%sです。\n", meridian_to_ja(twh),t);
}

char *meridian_to_ja(char *m)
{
	if (strcmp(m, "AM") == 0)
		return "午前";
	else if (strcmp(m,"PM") == 0)
		return "午後";
	else
		return "エラー";
}