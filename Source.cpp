#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_LEN 40

char * check_day(int day);
char * check_month(int month);

const char * days[31] = { "�����", "�����", "����", "��������", "�'���", "�����", "�����", "������", "������", "������", "�����������", "����������",
"����������", "������������", "�'���������", "����������", "���������", "����������", "���'���������", "��������", "�������� �����", "�������� �����",
"�������� ����", "�������� ��������", "�������� �'���", "�������� �����", "�������� �����", "�������� ������", "�������� ���'���", "��������", "�������� �����" };
const char * mount[12] = { "�i���", "������", "�������", "��i���", "������", "������", "�����", "������", "�������", "������", "���������", "������" };
char * str_day, *str_month;

int main()
{

	setlocale(LC_ALL, "ukr");
	int day, month, grap;

	
	
		printf("����i�� ���� �������(� ������i �� ��): ");
		scanf_s("%d%d", &day, &month);
		if (month == 2 && day >= 30) {
			printf("�������! � ������ ������ 28 ��i�, � i���i 29, � ���������� �i�\n");
			return 0;
		}
		str_day = (char*)calloc(MAX_LEN, sizeof(char));
		str_month = (char*)calloc(MAX_LEN, sizeof(char));
		str_day = check_day(day);
		str_month = check_month(month);
		if (str_day == NULL || str_month == NULL) return 0;
		strcat(str_day, " ");
		strcat(str_day, str_month);
		printf("���������: %s\n", str_day);
	    return 0;
}

char * check_day(int day)
{
	int num_1, num_2;
	if (day <= 0 || day>31) {
		printf("������� ���� ���i���\n");
		return NULL;
	}
	strcpy(str_day, days[day - 1]);
	return str_day;
}

