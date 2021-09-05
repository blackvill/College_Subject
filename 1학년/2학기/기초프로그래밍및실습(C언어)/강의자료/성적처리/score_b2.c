#include <Stdio.h>
#include <string.h>
#define MAX 3

# define QUIT 0
# define SAVE_TEXT 1
# define SAVE_BIN 2
# define SCORE_TEXT 3
# define SCORE_BIN 4
# define NAME_TEXT 5
# define NAME_BIN 6

int GetMenu(void);

struct score_s{
	char name[20];
	int kor;
	int eng;
	int mat;
};
typedef struct score_s SCORE_S;

struct score_t{
	char name[
		20];
	int kor;
	int eng;
	int mat;
	int sum;
	float avg;
};
typedef struct score_t SCORE_T;

void SortScore(SCORE_T sco_t[]);
void SortName(SCORE_T sco_t[]);
int score_p(SCORE_S sco_s[]) ;
char tfname[20]="test.txt";
char bfname[20]="test.data";

int SORT_T;
int main(void)
{
	int i, menu;
	FILE *fp;
	int sum, avg;
	float kor_sum, eng_sum, mat_sum;
	float kor_avg, eng_avg, mat_avg;

	SCORE_S score_s[MAX];
	
	printf("이  름 국어 영어 수학 점수를 입력하세요(%d명)\n", MAX);
	printf("====== ==== ==== ==== \n");
	for(i=0;i<MAX;i++)
	{
		scanf("%s %d %d %d", score_s[i].name, &score_s[i].kor,&score_s[i].eng,&score_s[i].mat);
		fflush(stdin);
	}

    while( 1 )
    {
        menu = GetMenu();
        if( menu == QUIT )
            break;
        switch( menu )
		{
         case SAVE_TEXT:
   			fp = fopen("score.txt","w");
			for(i=0; i<MAX;i++)
				fprintf(fp, "%s  %d  %d  %d\n",score_s[i].name,score_s[i].kor, score_s[i].eng, score_s[i].mat );
			fclose(fp);			
       		break;
        case SAVE_BIN:
    		fp = fopen("score.dat","wb");
			fwrite(score_s, sizeof(SCORE_S), MAX, fp);
			fclose(fp);
    		break;
        case SCORE_TEXT:
   			fp = fopen("score.txt","r");
			for(i=0; i<MAX;i++)
				fscanf(fp, "%s  %d  %d  %d", score_s[i].name, &score_s[i].kor, &score_s[i].eng, &score_s[i].mat );
			fclose(fp);		
			SORT_T=SCORE_TEXT;
			score_p(score_s);
            break;
        case SCORE_BIN:
	    	fp = fopen("score.dat","rb");
			fread(score_s, sizeof(SCORE_S), MAX, fp);
			fclose(fp);
			SORT_T=SCORE_BIN;
			score_p(score_s);
            break;
        case NAME_TEXT:
	    	fp = fopen("score.txt","r");
			for(i=0; i<MAX;i++)
				fscanf(fp, "%s  %d  %d  %d", score_s[i].name, &score_s[i].kor, &score_s[i].eng, &score_s[i].mat );
			fclose(fp);
			SORT_T=NAME_TEXT;
			score_p(score_s);
            break;
     case NAME_BIN:
	    	fp = fopen("score.dat","rb");
			fread(score_s, sizeof(SCORE_S), MAX, fp);
			fclose(fp);
			SORT_T=NAME_BIN;
			score_p(score_s);
            break;
     }
  }
}

int score_p(SCORE_S sco_s[]) 
{

	SCORE_T score_t[MAX];
	int i, sum, avg;
	float kor_sum, eng_sum, mat_sum;
	float kor_avg, eng_avg, mat_avg;

	kor_sum=eng_sum=mat_sum=0;
	for(i=0;i<MAX;i++)
	{
		strcpy(score_t[i].name, sco_s[i].name);
		score_t[i].kor=sco_s[i].kor;
		score_t[i].eng=sco_s[i].eng;
		score_t[i].mat=sco_s[i].mat;
		score_t[i].sum=score_t[i].kor+score_t[i].eng+score_t[i].mat;
		score_t[i].avg=(float)score_t[i].sum/3;
		kor_sum=kor_sum+score_t[i].kor;
		eng_sum=eng_sum+score_t[i].eng;
		mat_sum=mat_sum+score_t[i].mat;
	}
	kor_avg=(float)kor_sum/MAX;
	eng_avg=(float)eng_sum/MAX;
	mat_avg=(float)mat_sum/MAX;


	switch(SORT_T)
	{
        case SCORE_TEXT:
  			SortScore(score_t);
			printf("\n\n 텍스트 파일 총점순 정렬 결과\n");
            break;
        case SCORE_BIN:
  			SortScore(score_t);
			printf("\n\n 바이너리 파일 총점순 정렬 결과\n");
            break;
        case NAME_TEXT:
			SortName(score_t);
			printf("\n\n 텍스트 파일 이름순 정렬 결과\n");
            break;
	    case NAME_BIN:
			SortName(score_t);
			printf("\n\n 바이너리 파일 총점순 정렬 결과\n");
            break;
     }
	printf("========================================\n\n");
	printf("이  름  국어  영어  수학  총점  평균\n");
	printf("======  ====  ====  ====  ====  ====\n");
	for(i=0;i<MAX;i++)
	{
		printf("%-6s  %4d  %4d  %4d  %4d  %4.1f\n",score_t[i].name,score_t[i].kor, score_t[i].eng, score_t[i].mat,score_t[i].sum, score_t[i].avg);
	}
	printf("평균     %4.1f  %4.1f  %4.1f\n",kor_avg, eng_avg, mat_avg);
	printf("\n\n");
	return 0;
}

void SortScore(SCORE_T sco_t[])
{
    int i, j, k, index;
	int size;
	SCORE_T temp;

	size=MAX;

    for(i = 0; i < size-1 ; i++)
    {
        index = i;  
        for(j = i+1 ; j < size ; j++)
        {
            if( sco_t[index].sum < sco_t[j].sum )
                index = j;
        }
        temp = sco_t[i];
        sco_t[i]=sco_t[index];
        sco_t[index] = temp;
    }
}      


void SortName(SCORE_T sco_t[])
{
    int i, j, k, index;
	int size;
	SCORE_T temp;

	size=MAX;

    for(i = 0; i < size-1 ; i++)
    {
        index = i;  
        for(j = i+1 ; j < size ; j++)
        {
            if(strcmp(sco_t[index].name, sco_t[j].name) >0) //이름으로 sorting
                index = j;
        }
        temp = sco_t[i];
        sco_t[i]=sco_t[index];
        sco_t[index] = temp;
    }
}      


int GetMenu(void)
{
    int choice;
 
    while( 1 )
    {
        printf("---------------------------------------\n");
        printf("1. 성적을 텍스트 파일로 저장\n");
        printf("2. 성적을 바이너리 파일로 저장\n");
        printf("3. 텍스트 파일을 읽어 성적처리(총점순)\n");
        printf("4. 바이너리 파일을 읽어 성적처리(총점순)\n");
        printf("5. 텍스트 파일을 읽어 성적처리(이름순)\n");
        printf("6. 바이너리 파일을 읽어 성적처리(이름순)\n");
        printf("0. 종료\n");
        printf("---------------------------------------\n");
        printf("선택 : ");
        scanf("%d", &choice);
        fflush(stdin);
        if( choice >= 0 && choice <= 6 )
                break;
        else 
                printf("0부터 5사이의 값을 입력하세요.\n");
	}
	return choice;
}
