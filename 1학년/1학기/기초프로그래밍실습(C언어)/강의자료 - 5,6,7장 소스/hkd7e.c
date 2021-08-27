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
	printf("*연습문제 7-13 배열의 min/max 구하기        *\n");
	printf("*********************************************\n");
	hkd7_e13();

	printf("*********************************************\n");
	printf("*연습문제 7-14 대문자,소문자=>소문자,대문자 *\n");
	printf("*********************************************\n");
	hkd7_e14();

	printf("*********************************************\n");
	printf("*연습문제 7-18 10진수 => 문자열로 바꿈      *\n");
	printf("*********************************************\n");
	hkd7_e18();

	printf("*********************************************\n");
	printf("*연습문제 7-20  문자열에서 공백 제거        *\n");
	printf("*********************************************\n");
	hkd7_e20();

	printf("*********************************************\n");
	printf("*연습문제 7-21  실수값 10개 입력 받아 평균  *\n");
	printf("*********************************************\n");
	hkd7_e21();
}

int hkd7_e13(void)
{
    int arr[MAX];
    int i;
    int min, max;

    printf("%d개의 정수를 입력하세요 :\n", MAX);
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
    printf("최대값 : %d, 최소값 : %d\n", max, min);

    return 0;
}


int hkd7_e14(void)
{
    char str[80];
    int diff;
    int i = 0;

    printf("문자열을 입력하세요 : ");
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
    printf("변환된 문자열 : %s\n", str);

    return 0;
}

int hkd7_e18(void)
{
    int num;
	char str[10];    

    printf("10진수 정수를 입력하세요 : ");
    scanf("%d", &num);
	fflush(stdin);
	sprintf(str, "%d", num);
    printf("정수 %d는 문자열 \"%s\"입니다.\n", num, str);
        
    return 0;
}

int hkd7_e20(void)
{
    char str[256];
    char result[256];
    int i, j;

    printf("문자열을 입력하세요 : ");
    gets(str);

    for(i = 0, j = 0 ; str[i] != 0 ; i++)
    {
        if( str[i] != ' ' )
            result[j++] = str[i];
    }
    result[j] = 0;

    printf("변경 후 문자열 : ");
    puts(result);

    return 0;
}

int hkd7_e21(void)
{
    double arr[10];
    int i;
    double sum, average;

    printf("10개의 실수를 입력하세요 : ");
    for(i = 0 ; i < 10 ; i++)
        scanf("%lf", &arr[i]);
	fflush(stdin);
    sum = 0.0;
    for(i = 0 ; i < 10 ; i++)
        sum += arr[i];

    average = sum / 10;
    printf("평균 : %lf\n", average);

    return 0;
}

