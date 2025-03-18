#include<stdio.h>
#include<process.h>
#include<malloc.h>

// Stack implementation
struct Book{
	int bookno;
	char title[51];
	double price;
	struct Book *next;
};

struct Book *top;

void push(){
	struct Book *ptr=(struct Book *) malloc(sizeof(struct Book));
	
	printf("Book No : "); fflush(stdin); scanf("%d",&ptr->bookno);
	printf("Title : "); fflush(stdin); gets(ptr->title);
	printf("Price : "); fflush(stdin); scanf("%lf",&ptr->price);	
	ptr->next=NULL;

	if(top==NULL){
		top=ptr;
	}else{
		ptr->next=top;
		top=ptr;
	}	
	printf("Item pushed\n");
}
