#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define Debug

#define Max_Len_Str 100
#define Max_Count_Operators 50
#define Count_Operators 4
#define Count_Cifri 10
#define Max_Number 50
#define Len_Number 10

struct Obj
{
	char type;
	int index;
};

int main()
{
	char str[Max_Len_Str]="200.512*3-11";
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

	char numbers_list[Max_Number][Len_Number];

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
	int meed1 = end1 - start1;

	//printf("%d\n",meed1);

	for(int i=0;i<meed1;i++)
	{
		numbers_list[0][i]=str_not_probels[i];
	}

	numbers_list[0][meed1]='\0';

	//printf("%s\n",numbers_list[0]);

	for(int i=0;i<cnt1-1;i++)
	{
		int starti,endi;
		starti=operators[i].index;
		endi=operators[i+1].index;
		int meedi=endi-starti-1;

		for(int j=0;j<meedi;j++)
		{
			numbers_list[i+1][j]=str_not_probels[starti+1+j];
		}
		numbers_list[i+1][meedi]='\0';
	}

	for(int i=0;i<cnt1-1;i++)
	{
		//printf("%s\n",numbers_list[i+1]);
	}


	int startend=operators[cnt1-1].index;
	int endend=strlen(str_not_probels)-1;
	int meedend=endend-startend;

	for (int i = 0; i < meedend; i++)
	{
		numbers_list[cnt1][i]=str_not_probels[startend+1+i];
	}

	numbers_list[cnt1][meedend]='\0';

	//printf("%s\n",numbers_list[cnt1]);


	if (start1 == operators[0].index)
	{
		printf("error!\n");
		return -1;
	}
	int count_number_meed = end1 - start1 - 1;

	#ifndef Debug
		printf("%s\n", str_not_probels);
		for (int i = 0;i < cnt1;i++)
			printf("%c;", operators[i].type);
		printf("\n");
		for (int i = 0;i < cnt2;i++)
			printf("%c;", cifri[i].type);
		printf("\n");
	#endif



	//я скоро тут добавлю свою либу которая будет считать большие числа

	double Int_Number_List[Max_Number];

		//printf("\n\n");

		for(int i=0;i<(cnt1+1);i++)
		{
			Int_Number_List[i]=atof(numbers_list[i]);
	#ifndef Debug
			printf("%g\n",Int_Number_List[i]);
	#endif
		}

	double result=0;
	switch (operators[0].type)
	{
		case '+':
		{
			result=Int_Number_List[0]+Int_Number_List[1];
			break;
		}
		case '-':
		{
			result=Int_Number_List[0]-Int_Number_List[1];
			break;
		}
		case '*':
		{
			result=Int_Number_List[0]*Int_Number_List[1];
			break;
		}
		case '/':
		{
			result=Int_Number_List[0]/Int_Number_List[1];
			break;
		}
	}

	for(int i=0;i<cnt1+1-2;i++)
	{
		switch (operators[i+1].type)
		{
			case '+':
			{
				result+=Int_Number_List[i+2];
				break;
			}
			case '-':
			{
				result-=Int_Number_List[i+2];
				break;
			}
			case '*':
			{
				result*=Int_Number_List[i+2];
				break;
			}
			case '/':
			{
				result/=Int_Number_List[i+2];
				break;
			}
		}
	}

	printf("\n%f\n",result);

}
