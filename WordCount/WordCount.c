#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getCharacterNumber(FILE *fp)
{
	char ch;
	int count = 0;
	while ((ch = fgetc(fp)) != EOF)
		count++;
	rewind(fp);
	return count;
}


int getWord(FILE *fp)
{
	int num = 0,flag = 0;		  
	char TheWord;			  
	while (feof(fp) == 0) 
	{
		TheWord = fgetc(fp); 
		if (flag == 0 && (TheWord == ' ' || TheWord == ','))
		{
			num++;
			flag = 1;
		}
		else if ((TheWord != 32 && TheWord != 44) && flag == 1) 
		{
			num++;
			flag = 0;
		}
	}
	rewind(fp);
	return num;
}


int main(int argc, char *argv[])
{
	FILE *fp;
	int num;
	char string;

	if (argc == 3)
	{
		
		fp = fopen(argv[2], "r");
		
		if (fp == NULL)
		{
			printf("无法打开%s\n", argv[2]);
			exit(1);
		}
		
		if (!strcmp(argv[1], "-c"))
		{ 
			num = getCharacterNumber(fp);
			printf("字符数：%d\n", num);
		}

		else if (!strcmp(argv[1], "-w"))
		{ 
			num = getWord(fp);
			printf("字符数：%d\n", num);
		}
		else
		{
			printf("参数错误！");
		}
	}
	else
	{
		printf("请重新输入:\n");
	}
}