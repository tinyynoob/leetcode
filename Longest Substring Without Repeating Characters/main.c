#include"Header.h"

struct block
{
	char ch; //character
	int count;
	char str[2000];
	struct block* next;
};

void clean(struct block*);

void main()
{
	int max = 0, indicator = 0,flag;
	char s[50000]; //input
	struct block* p=NULL,*last=NULL,*newBlock=NULL,*head=NULL;
	gets(s);
	//puts(s);
	
	/*	queue structure is used	*/
	while (indicator<strlen(s))
	{
		newBlock = malloc(sizeof(struct block));
		newBlock->next = NULL;
		newBlock->ch = s[indicator];
		if (!head)
		{
			newBlock->count = 1;
			strcpy(newBlock->str, (char[2]){(char)newBlock->ch,'\0'});
			head = newBlock;
		}
		else
		{
			flag = 0;	// flag=0 represents no repeat is found
			newBlock->count = last->count+1;
			strcpy(newBlock->str, strcat(last->str, (char[2]){(char)newBlock->ch,'\0'}) );
			//puts(newBlock->str);
			for (p = head;p->next; p = p->next)	//error for pwwkew
			{
				if (p->ch == newBlock->ch)	//if a repeat is found
				{
					if( (newBlock->count)-(p->count) > max )	//update max
						max = (newBlock->count)-(p->count);
					clean(head);	//kill the old queue
					newBlock->count = 1;	//recount
					strcpy(newBlock->str, (char[2]){(char)newBlock->ch,'\0'});	//reconstruct the string
					head = newBlock;
					flag = 1;
					break;
				}
			}
			if (flag == 0)	//if no repeat is found, then enqueue
				last->next = newBlock;
		}
		printf("%s\n", newBlock->str);
		last=newBlock;
		indicator++;
	}
	if (last->count > max)
		max = last->count;
	printf("%d\n",max);

	system("pause");
	return;
}

void clean(struct block* cp)
{
	struct block* p = cp->next;
	if (p)
		clean(p);
	free(p);
}