#include<stdio.h>
#include<time.h>

void put_date(void);

char *week_to_ja(char*);

int main ()
{
	put_date();

	return 0;
}

void put_date (void)
{
	time_t now;
	struct tm *ts;
	char date[80];
	char week[5];

	now = time(NULL);

	ts = localtime(&now);
	strftime(date, sizeof(date), "%Y年%m月%d日", ts);
	strftime(week, sizeof(date), "%w", ts);
	printf("今日は %s %s曜日 です。\n", date, week_to_ja(week));
}

char *week_to_ja (char *week)
{
	int w = *week - 48;

	switch ( w ) {
		case 0:
			return "日";
		case 1:
			return "月";
		case 2:
			return "火";
		case 3:
			return "水";
		case 4:
			return "木";
		case 5:
			return "金";
		case 6:
			return "土";
		default:
			return "曜日ではない";
	}
}