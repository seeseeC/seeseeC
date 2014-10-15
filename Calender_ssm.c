#include<stdio.h>
#include<windows.h>
void input(int*, int*);
int yearCheck(int);//윤년체크
int totalDays(int, int);//총 일수 체크
void output(int, int, int);
void gotoxy(int, int);//입력할 곳을 지정해주는 함수
int main()
{
	int year, month, count = 0;
	int y, res, beforeTot;
	printf("*년도와 월을 입력하시오 : ");
	input(&year, &month);
	for (y = 1; y == year; y++)
		res = yearCheck(year);
	beforeTot = totalDays(year, month);//그 해 구하려는 달의 전달까지의 총 날수를 저장하는 변수
	output(year, month, beforeTot);
	return 0;
}
void input(int *year, int *month)
{
	scanf("%d %d", year, month);
	return;
}
int yearCheck(int year)
{
	int a;//윤년이면 1,평년이면 0
	if (year % 4 != 0)
	{
		a = 0;
	}
	else
	{
		if (year % 100 != 0)
		{
			a = 1;
		}
		else
		{
			if (year % 400 != 0)
			{
				a = 0;
			}
			else
			{
				a = 1;
			}
		}
	}
	return a;
}

int totalDays(int Y, int M)
{
	int totdays=0, y, m;
	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (y = 1; y <= Y - 1; y++)
	{
		if (yearCheck(y) == 1)
			totdays += 366;
		else
			totdays += 365;
	}
	for (m = 0; m < M - 1; m++)//그 전달까지의 날 수를 계산계산
	{
		totdays += months[m];
		if ((yearCheck(Y) == 1) && M >= 3)
			++totdays;
	}
	return totdays;
}
void output(int year, int month, int beforeTot)
{
	int i;

	gotoxy(30, 2);
	printf("[%d .  %d]", year, month);

	gotoxy(20, 3);
	printf("SUN MON TUE WED THU FRI SAT");

	gotoxy(18, 4);
	printf("-------------------------------");

	//일 출력 시작
	switch (beforeTot % 7)
	{
	case 0:gotoxy(24, 5); printf("%3d %3d %3d %3d %3d %3d", 1, 2, 3, 4, 5, 6); break;
	case 1:gotoxy(28, 5); printf("%3d %3d %3d %3d %3d", 1, 2, 3, 4, 5); break;
	case 2:gotoxy(32, 5); printf("%3d %3d %3d %3d", 1, 2, 3, 4); break;
	case 3:gotoxy(36, 5); printf("%3d %3d %3d", 1, 2, 3); break;
	case 4:gotoxy(40, 5); printf("%3d %3d", 1, 2); break;
	case 5:gotoxy(44, 5); printf("%3d", 1); break;
	case 6:gotoxy(20, 5); printf("%3d %3d %3d %3d %3d %3d %3d", 1, 2, 3, 4, 5, 6, 7); break;
	}
	gotoxy(20, 6);
	if (beforeTot % 7<6)
	{
		for (i = 7; i<14; i++)
			printf("%3d ", i - (beforeTot % 7));
	}
	else
	{
		for (i = 15; i<22; i++)
			printf("%3d ", i - (beforeTot % 7));
	}
	gotoxy(20, 7);
	if (beforeTot % 7<6)
	{
		for (i = 14; i<21; i++)
			printf("%3d ", i - (beforeTot % 7));
	}
	else
	{
		for (i = 22; i<29; i++)
			printf("%3d ", i - (beforeTot % 7));
	}
	gotoxy(20, 8);
	if (beforeTot % 7<6)
	{
		for (i = 21; i<28; i++)
			printf("%3d ", i - (beforeTot % 7));
	}
	else
	{
		for (i = 29; i<36; i++)
			printf("%3d ", i - (beforeTot % 7));
	}


}
void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
