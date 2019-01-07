#include <stdio.h>
struct polynomial{
	int coef;
	int pow;
	struct polynomial* next;
};

void insertPolynomial(struct polynomial** poly,int coef, int exp)
{
	struct polynomial* new_node = NULL;
	new_node = (struct polynomial*)malloc(sizeof(struct polynomial));
	if(new_node == NULL)
		return;
	new_node->coef = coef;
	new_node->pow = exp;

	if( (*poly) == NULL)
	{
		new_node->next = (*poly);
		(*poly) = new_node;
	}
	else
	{
		struct polynomial* temp = (*poly);
		while((temp)->next != NULL)
		{
			(temp) = (temp)->next;
		}
		new_node->next = NULL;
		(temp)->next = new_node;

	}
}

void printPolynomial(struct polynomial* poly)
{
	struct polynomial* temp = poly;
	while(temp)
	{
		printf("%dx^%d",temp->coef,temp->pow);
		if(temp && temp->next)
			printf(" + ");
		temp = temp->next;

	}
	printf("\n");
}

struct polynomial* addPolynomial(struct polynomial* poly1,struct polynomial* poly2,struct polynomial* result)
{
	while( poly1 && poly2)
	{
		static int counter = 0;
		printf("counter : %d\n",++counter);
		if(poly1->pow > poly2->pow)
		{
			result->pow = poly1->pow;
			result->coef = poly1->coef;
			poly1 = poly1->next;
		}
		else if(poly1->pow < poly2->pow)
		{
			result->pow = poly2->pow;
			result->coef = poly2->coef;
			poly2 = poly2->next;
		}
		else // equal
		{
			result->pow = poly1->pow;
			result->coef = poly1->coef + poly2->coef;
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
		if(poly1 || poly2)
		{
			result->next = (struct polynomial*)malloc(sizeof(struct polynomial));
			result = result->next ;
			result->next = NULL;
		}

	}
	while((poly1) || (poly2))
	{

		if( poly1)
		{
			printf("poly1\n");
			result->pow = poly1->pow;
			result->coef = poly1->coef;
			poly1 = poly1->next;
		}
		if( poly2)
		{
			printf("poly2\n");
			result->pow = poly2->pow;
			result->coef = poly2->coef;
			poly2 = poly2->next;
		}
		if(poly1 || poly2)
		{
			result->next = (struct polynomial*)malloc(sizeof(struct polynomial));
			result = result->next ;
			result->next = NULL;
		}
	}
	return result;
}

//10x³+7x²+3x+1
//7x³+10x²+2x+8
int main(void) {

	struct polynomial* poly1 = NULL, *poly2 = NULL;
	insertPolynomial(&poly1,1,4);
	insertPolynomial(&poly1,10,3);
	insertPolynomial(&poly1,7,2);
	insertPolynomial(&poly1,3,1);
	insertPolynomial(&poly1,1,0);

	insertPolynomial(&poly2,1,7);
	insertPolynomial(&poly2,1,6);
	insertPolynomial(&poly2,7,3);
	insertPolynomial(&poly2,10,2);
	insertPolynomial(&poly2,2,1);
	insertPolynomial(&poly2,8,0);

	printPolynomial(poly1);
	printPolynomial(poly2);
	struct polynomial* result = NULL;
	result = (struct polynomial*)malloc(sizeof(struct polynomial));
	addPolynomial(poly1,poly2,result);
	printPolynomial(result);
	return 0;
}
