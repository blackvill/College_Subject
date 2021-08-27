
#include <stdio.h>

int IsLeapYear(int year);
int GetDaysOfMonth(int year, int month);

int main(void)
{
    int year, mon, days;

    printf("������ ���� �Է��ϼ��� : ");
    scanf("%d %d", &year, &mon);

    days = GetDaysOfMonth(year, mon);
    printf("%d�� %d���� %d���Դϴ�.\n", year, mon, days);

    return 0;
}

int IsLeapYear(int year)
{
    return (((year%4==0) && (year%100!=0)) || (year%400==0)) ? 1 : 0;
}

int GetDaysOfMonth(int year, int month)
{
    switch( month )
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return 28 + IsLeapYear(year);
    default:
        return 31;
    }
}
