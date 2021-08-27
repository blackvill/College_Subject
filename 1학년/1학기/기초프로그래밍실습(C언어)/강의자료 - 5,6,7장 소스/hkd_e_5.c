
#include <stdio.h>

int uppercase_lowercase();
int sum_oddsum_evensum(void);
int even_odd_check(void);
int even_odd_check_continue(void);
int cal_factorial(void);
int cal_factorial_multi(void);
int total_menu(void);


int main(void)
{
	printf("*********************************************\n");
	printf("*       �������� 5-16  uppercase_lowercase  *\n");
	printf("*********************************************\n");
	uppercase_lowercase();
	printf("*********************************************\n");
	printf("*       �������� 5-17  sum_oddsum_evensum   *\n");
	printf("*********************************************\n");
	sum_oddsum_evensum();
	printf("*********************************************\n");
	printf("*       �������� 5-18    even_odd_check     *\n");
	printf("*********************************************\n");
	even_odd_check();
	printf("*********************************************\n");
	printf("*      �������� 5-19 even_odd_check_continue*\n");
	printf("*********************************************\n");
	even_odd_check_continue();
	printf("*********************************************\n");
	printf("*       �������� 5-20  cal_factorial        *\n");
	printf("*********************************************\n");
	cal_factorial();
	printf("*********************************************\n");
	printf("*       �������� 5-21  cal_factorial_mult   *\n");
	printf("*********************************************\n");
	cal_factorial_multi();
	printf("*********************************************\n");
	printf("*       �������� 5-22   total_menu          *\n");
	printf("*********************************************\n");
	total_menu();

}

int uppercase_lowercase()
{
    char ch;

    while ( 1 )
    {
        printf("�����ڸ� �Է��ϼ��� : ");
        scanf_s("%c", &ch);
        fflush(stdin);

        if( ch == '.' )
            break;

        if( ch >= 'A' && ch <= 'Z' )
            printf("�빮���Դϴ�.\n");
        else if( ch >= 'a' && ch <= 'z' )
            printf("�ҹ����Դϴ�.\n");
        else
            printf("�����ڰ� �ƴմϴ�.\n");
    }

    return 0;
}

int sum_oddsum_evensum(void)
{
    int num;
    int total = 0, odd_total = 0, even_total = 0;
    int i;

    printf("������ �Է��ϼ��� : ");
    scanf_s("%d", &num);

    for( i = 1 ; i <= num ; i++ )
        total += i;

    i = 1;
    while( i <= num )
    {
        odd_total += i;
        i += 2;
    }

    i = 2;
    do {
        even_total += i;
        i += 2;
    }
    while( i <= num );

    printf("1���� %d������ �հ� : %d\n", num, total);
    printf("1���� %d������ Ȧ���� �հ� : %d\n", num, odd_total);
    printf("1���� %d������ ¦���� �հ� : %d\n", num, even_total);

    return 0;
}
int even_odd_check(void)
{
    int num;
    printf("������ �Է��ϼ��� : ");
    scanf_s("%d", &num);

    if( num % 2 == 0 )
        printf("%d�� ¦���Դϴ�.\n", num);
    else
        printf("%d�� Ȧ���Դϴ�.\n", num);

    return 0;
}

int even_odd_check_continue(void)
{
    int num;
    char choice;

    while( 1 ) 
    {
        printf("������ �Է��ϼ��� : ");
        scanf_s("%d", &num);
        fflush(stdin);

        if( num % 2 == 0 )
            printf("%d�� ¦���Դϴ�.\n", num);
        else
            printf("%d�� Ȧ���Դϴ�.\n", num);
        
        printf("��� �Ͻðڽ��ϱ�? (Y/N) : ");
        scanf_s("%c", &choice);
        if( choice == 'N' || choice == 'n' )
            break;
    }

    return 0;
}

int cal_factorial(void)
{
    int n = 0;
    int fact = 1;
    int i;

    printf("������ �Է��ϼ��� : ");
    scanf_s("%d", &n);

    for( i=1 ; i <= n ; i++)
        fact *= i;

    printf("%d!�� %d�Դϴ�.\n", n, fact);

    return 0;
}

int cal_factorial_multi(void)
{
    int n = 0;
    int fact = 1;
    int i;

    printf("������ �Է��ϼ��� : ");
    scanf_s("%d", &n);

    printf("0!�� %d�Դϴ�.\n", fact);

    for( i=1 ; i <= n ; i++) 
    {
        fact *= i;
        printf("%d!�� %d�Դϴ�.\n", i, fact);
    }

    return 0;
}

int total_menu(void)
{
    int menu;
    int num;
    int sum, fact;
    int i;

    while( 1 )
    {
        printf("1. Ȧ�� ¦�� Ȯ��\n");
        printf("2. N������ �հ� ���ϱ�\n");
        printf("3. N ���丮�� ���ϱ�(N!)\n");
        printf("0. ����\n");
        printf("���� : ");

        scanf_s("%d", &menu);
        if( menu == 0 )
            break;

        switch( menu )
        {
        case 1:
            printf("������ �Է��ϼ��� : ");
            scanf_s("%d", &num);
            if( num % 2 == 0 )
                printf("%d�� ¦���Դϴ�.\n", num);
            else
                printf("%d�� Ȧ���Դϴ�.\n", num);
            break;
        case 2:
            printf("������ �Է��ϼ��� : ");
            scanf_s("%d", &num);
            sum = 0;
            for( i = 1 ; i <= num ; i++)
                sum += i;
            printf("1~%d������ �հ�� %d�Դϴ�.\n", num, sum);
            break;
        case 3:
            printf("������ �Է��ϼ��� : ");
            scanf_s("%d", &num);
            fact = 1;
            for( i = 1 ; i <= num ; i++)
                fact *= i;
            printf("%d!�� %d�Դϴ�.\n", num, fact);
            break;
        default:
            printf("�߸� �Է��ϼ̽��ϴ�.\n");
            continue;
        }
    }

    return 0;
}