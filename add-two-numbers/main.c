#include"Header.h"

struct node
{
	int value;
	struct node* next;
};

int main()
{
	int input, overflow;
	struct node* list1, * list2, * newNode, * sum, * f, * p;

	list1 = NULL;
	list2 = NULL;
	sum = NULL;
	p = NULL;

	while (1)  //bulid a queue as list1
	{
		scanf("%d", &input);
		if (input == -1)
			break;

		newNode = (struct node*)malloc(sizeof(struct node));
		newNode->next = NULL;
		newNode->value = input;
		if (!list1)
		{
			list1 = newNode;
			p = newNode;
		}
		else
		{
			p->next = newNode;
			p = p->next;
		}
	}

	while (1)  //bulid a queue as list2
	{
		scanf("%d", &input);
		if (input == -1)
			break;

		newNode = (struct node*)malloc(sizeof(struct node));
		newNode->next = NULL;
		newNode->value = input;
		if (!list2)
		{
			list2 = newNode;
			p = newNode;
		}
		else
		{
			p->next = newNode;
			p = p->next;
		}
	}

	overflow = 0;
	while (list1 || list2)  //compute and build a stack
	{
		newNode = (struct node*)malloc(sizeof(struct node));
		newNode->next = NULL;
		if (!list1)
		{
			newNode->value = list2->value + 0;
			f = list2;
			list2 = list2->next;
			free(f);
		}
		else if (!list2)
		{
			newNode->value = list1->value + 0;
			f = list1;
			list1 = list1->next;
			free(f);
		}
		else   //both nonempty
		{
			newNode->value = list1->value + list2->value;
			f = list1;
			list1 = list1->next;
			free(f);
			f = list2;
			list2 = list2->next;
			free(f);
		}

		newNode->value += overflow;
		overflow = 0;
		if (newNode->value > 9)
		{
			overflow = 1;
			newNode->value -= 10;
		}

		if (!sum)
			sum = newNode;
		else
		{
			newNode->next = sum;
			sum = newNode;
		}
	}

	if (overflow)  // check last overflow
	{
		newNode = (struct node*)malloc(sizeof(struct node));
		newNode->value = 1;
		newNode->next = sum;
		sum = newNode;
	}

	printf("\n\n");
	while (sum)  // output
	{
		p = sum;
		sum = sum->next;
		printf("%d", p->value);
		free(p);
	}
	printf("\n\n");

	system("pause");
	return 0;
}

