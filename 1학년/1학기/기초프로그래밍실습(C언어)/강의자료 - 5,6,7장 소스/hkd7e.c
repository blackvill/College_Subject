#include <stdio.h>
#define MAX 10

int hkd7_e13(void);
int hkd7_e14(void);
int hkd7_e18(void);
int hkd7_e20(void);
int hkd7_e21(void);

int main(void)
{
	printf("*********************************************\n");
	printf("*�������� 7-13 �迭�� min/max ���ϱ�        *\n");
	printf("*********************************************\n");
	hkd7_e13();

	printf("*********************************************\n");
	printf("*�������� 7-14 �빮��,�ҹ���=>�ҹ���,�빮�� *\n");
	printf("*********************************************\n");
	hkd7_e14();

	printf("*********************************************\n");
	printf("*�������� 7-18 10���� => ���ڿ��� �ٲ�      *\n");
	printf("*********************************************\n");
	hkd7_e18();

	printf("*********************************************\n");
	printf("*�������� 7-20  ���ڿ����� ���� ����        *\n");
	printf("*********************************************\n");
	hkd7_e20();

	printf("*********************************************\n");
	printf("*�������� 7-21  �Ǽ��� 10�� �Է� �޾� ���  *\n");
	printf("*********************************************\n");
	hkd7_e21();
}

int hkd7_e13(void)
{
    int arr[MAX];
    int i;
    int min, max;

    printf("%d���� ������ �Է��ϼ��� :\n", MAX);
    for( i = 0 ; i < 10 ; i++)
        scanf("%d", &arr[i]);
	fflush(stdin);
    min = max = arr[0];
    for( i = 1 ; i < 10 ; i++)
    {
        if( arr[i] < min )
            min = arr[i];
        if( arr[i] > max )
            max = arr[i];
    }
    printf("�ִ밪 : %d, �ּҰ� : %d\n", max, min);

    return 0;
}


int hkd7_e14(void)
{
    char str[80];
    int diff;
    int i = 0;

    printf("���ڿ��� �Է��ϼ��� : ");
    gets(str);

    diff = 'a' - 'A';
    while( str[i] != '\0' )
    {
        if( str[i] >= 'A' && str[i] <= 'Z' )
            str[i] = str[i] + diff;
        else if( str[i] >= 'a' && str[i] <= 'z' )
            str[i] = str[i] - diff;
        i++;
    }
    printf("��ȯ�� ���ڿ� : %s\n", str);

    return 0;
}

int hkd7_e18(void)
{
    int num;
	char str[10];    

    printf("10���� ������ �Է��ϼ��� : ");
    scanf("%d", &num);
	fflush(stdin);
	sprintf(str, "%d", num);
    printf("���� %d�� ���ڿ� \"%s\"�Դϴ�.\n", num, str);
        
    return 0;
}

int hkd7_e20(void)
{
    char str[256];
    char result[256];
    int i, j;

    printf("���ڿ��� �Է��ϼ��� : ");
    gets(str);

    for(i = 0, j = 0 ; str[i] != 0 ; i++)
    {
        if( str[i] != ' ' )
            result[j++] = str[i];
    }
    result[j] = 0;

    printf("���� �� ���ڿ� : ");
    puts(result);

    return 0;
}

int hkd7_e21(void)
{
    double arr[10];
    int i;
    double sum, average;

    printf("10���� �Ǽ��� �Է��ϼ��� : ");
    for(i = 0 ; i < 10 ; i++)
        scanf("%lf", &arr[i]);
	fflush(stdin);
    sum = 0.0;
    for(i = 0 ; i < 10 ; i++)
        sum += arr[i];

    average = sum / 10;
    printf("��� : %lf\n", average);

    return 0;
}

