#include"Header.h"

struct block
{
	char ch; //character
	int count;
	struct block* next;
};

void* rearrange(struct block*,char);

void main()
{
	int max = 0, indicator = 0,flag,i;
	char s[50000],Str[1000]; //s is the input string 
	struct block* p=NULL,*last=NULL,*newBlock=NULL,*head=NULL,*k=NULL;
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
			strcpy(Str, (char[2]){(char)newBlock->ch,'\0'});
			head = newBlock;
		}
		else
		{
			flag = 0;	// flag=0 represents that no repeat is found
			newBlock->count = last->count+1;
			strcpy(Str, strcat(Str, (char[2]){(char)newBlock->ch,'\0'}) );
			//puts(Str);

			for (p = head;p; p = p->next)	//scan the previous queue
			{
				if (p->ch == newBlock->ch)	//if a repeat is found
				{
					if( (newBlock->count)-(p->count) > max )	//update max
						max = (newBlock->count)-(p->count);
					head=rearrange(head, p->ch);	//modify the head of the linked list
					
					/*	recount and reconstruct Str	*/
					i = 1;
					strcpy(Str, (char[1]) {'\0'});	//clear Str
					for (k=head ;k; k=k->next)	
					{
						k->count = i;
						strcpy(Str, strcat(Str, (char[2]) { (char)k->ch, '\0' }));
						i++;
						p = k;	//different use of p ,as last for k
					}
					if (head)
						p->next = newBlock;
					else		//if rearrange returned NULL
						head = newBlock;

					newBlock->count = i;
					strcpy(Str, strcat(Str, (char[2]) { (char)newBlock->ch, '\0' }));

					flag = 1;
					break;
				}
			}
			if (flag == 0)	//if no repeat is found, then enqueue
				last->next = newBlock;
		}

		printf("%s\n", Str);
		last=newBlock;
		if(newBlock->count >max)
			max = newBlock->count;
		indicator++;
	}

	printf("%d\n",max);

	system("pause");
	return;
}

void* rearrange(struct block* head, char target)
{
	struct block* p=NULL ,*p2=NULL;
	int found = 0;
	for (p = head; p; p = p2)
	{
		if (p->ch == target)	//the target is found
			found++;
		p2 = p->next;
		free(p);
		if (found)
			break;
	}
	return p2;
}