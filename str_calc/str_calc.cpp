#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define Max_Len_Str 100
#define Max_Count_Operators 50
#define Count_Operators 4
#define Count_Cifri 10
#define Max_Number 50

struct Obj
{
	char type;
	int index;
};

int main()
{
	char str[Max_Len_Str]="100   +20  - 51";
	char operators_list[Count_Operators+1] = "/+-*";
	struct Obj operators[Max_Count_Operators];
	struct Obj cifri[Count_Cifri];


	int cnt3 = 0;
	char str_not_probels[Max_Len_Str];

	for (int i = 0;i < Max_Len_Str;i++)
	{
		if (str[i] != ' ') {
			str_not_probels[cnt3] = str[i];
			cnt3++;
		}
	}

	char numbers_list[Max_Number];

	char cifri_list[Count_Cifri+1] = "0123456789";

	int cnt1 = 0,cnt2 = 0;

	for (int i = 0;i < Max_Len_Str;i++)
	{
		for (int j = 0;j < Count_Operators;j++)
		{
			if (str_not_probels[i] == operators_list[j])
			{
				operators[cnt1].index = i;
				operators[cnt1].type = operators_list[j];
				cnt1++;
			}
		}
	}

	for (int i = 0;i < Max_Len_Str;i++)
	{
		for (int j = 0;j < Count_Cifri;j++)
		{
			if (str_not_probels[i] == cifri_list[j])
			{
				cifri[cnt2].index = i;
				cifri[cnt2].type = cifri_list[j];
				cnt2++;
			}
		}
	}
	

	int start1, end1;

	start1 = 0;
	end1 = operators[0].index;
	int meed1 = end1 - start1 - 1;


	if (start1 == operators[0].index)
	{
		printf("error!\n");
		return -1;
	}
	int count_number_meed = end1 - start1 - 1;

	printf("%s\n", str_not_probels);

	for (int i = 0;i < cnt1;i++)
		printf("%c;", operators[i].type);
	printf("\n");
	for (int i = 0;i < cnt2;i++)
		printf("%c;", cifri[i].type);
	printf("\n");



}
