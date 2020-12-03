#include"Header.h"

// overflow issue hasnt been solved yet

int main()
{
	char s1[200], s2[200];
	gets(s1);
	gets(s2);
	//puts(s1);
	//puts(s2);
	int i, j;
	unsigned long n1=0 ,n2=0 ,base;

	base = strlen(s1) + strlen(s2) + 1;
	char *s;
	s = (char*)malloc(base * sizeof(char));
	for (i = 0; i < base; i++)		//set every s[i] to 0
		s[i] = 0;
	
	for (i = 0; i < strlen(s1); i++)	//convert s1 to n1;
	{
		base = 1;
		for (j = 0; j < strlen(s1) - i-1; j++)
			base *= 10;
		n1 += (s1[i]-'0') * base;
	}

	for (i = 0; i < strlen(s2); i++)	//convert s2 to n2;
	{
		base = 1;
		for (j = 0; j < strlen(s2)-i-1; j++)
			base *= 10;
		n2 += (s2[i]-'0') * base;
	}
	
	//printf("\n%d\n\n", n1*n2);

	n1 = n1 * n2;
	
	if (n1<=9)
	{
		printf("\n%c\n", n1+'0');
		return 0;
	}
	else
	{
		base = 1;
		while (n1 > base)
			base *= 10;
		base /= 10;


		for (i = 0 ; base>0 ; base/=10, i++)
		{
			s[i] = (n1/base) + '0';
			n1 %= base;
		}
	}
	printf("\n%s\n\n",s);

	free(s);
	system("pause");
	return 0;
}
