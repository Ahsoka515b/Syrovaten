#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_LEN 40

char * check_day(int day);
char * check_month(int month);

const char * days[31] = { "перше", "друге", "третЇ", "четверте", "п'€те", "шосте", "сьоме", "восьме", "дев€те", "дес€те", "одиннадц€те", "дванадц€те",
"тринадц€те", "чотирнадц€те", "п'€тнадц€те", "ш≥снадц€те", "с≥мнадц€те", "в≥с≥мнадц€те", "дев'€тнадц€те", "двадц€те", "двадц€ть перше", "двадц€ть друге",
"двадц€ть третЇ", "двадц€ть четверте", "двадц€ть п'€те", "двадц€ть шосте", "двадц€ть сьоме", "двадц€ть восьме", "двадц€ть дев'€те", "тридц€те", "тридц€ть перше" };
const char * mount[12] = { "сiчн€", "лютого", "березн€", "квiтн€", "травн€", "червн€", "липн€", "серпн€", "вересн€", "жовтн€", "листопада", "грудн€" };
char * str_day, *str_month;

int main()
{

	setlocale(LC_ALL, "ukr");
	int day, month, grap;

	
	
		printf("¬ведiть дату числами(у форматi дд мм): ");
		scanf_s("%d%d", &day, &month);
		if (month == 2 && day >= 30) {
			printf("ѕомилка! ¬ лютому всього 28 днiв, а iнодi 29, у високосний рiк\n");
			return 0;
		}
		str_day = (char*)calloc(MAX_LEN, sizeof(char));
		str_month = (char*)calloc(MAX_LEN, sizeof(char));
		str_day = check_day(day);
		str_month = check_month(month);
		if (str_day == NULL || str_month == NULL) return 0;
		strcat(str_day, " ");
		strcat(str_day, str_month);
		printf("–езультат: %s\n", str_day);
	    return 0;
}

char * check_day(int day)
{
	int num_1, num_2;
	if (day <= 0 || day>31) {
		printf("¬ведена дата невiрна\n");
		return NULL;
	}
	strcpy(str_day, days[day - 1]);
	return str_day;
}

