#include<stdio.h>
#include<process.h>
#include<malloc.h>

// self referential structure
struct Book{
	int bookno;
	char title[51];
	double price;
	struct Book *next; // pointer to next record
};


// global variable to hold address of first and last records
struct Book *first, *last;

void addBook(){
	struct Book *ptr=(struct Book *) malloc(sizeof(struct Book));
	if(ptr==NULL){
		printf("Unable to allocate memory");
		return;
	}
	
	// data input
	printf("Book No : ");
	fflush(stdin); // clear the keyboard buffer
	scanf("%d",&ptr->bookno);
	
	printf("Title : ");
	fflush(stdin); // clear the keyboard buffer
	gets(ptr->title);
	
	printf("Price : ");
	fflush(stdin); // clear the keyboard buffer
	scanf("%lf",&ptr->price);
	
	// next address is NULL
	ptr->next=NULL;
	
	if(first==NULL){
		first=last=ptr;
	}else{
		last->next=ptr;
		last=ptr;
	}
	
	printf("Record Added\n");
	
}

void showBooks(){ // Traversing
	if(first==NULL){
		printf("Sorry! No books found\n");
	}else
	{
		struct Book *ptr;
		ptr=first;
		while(ptr!=NULL){
			printf("%d %s %.2f\n",ptr->bookno, ptr->title, ptr->price);
			ptr=ptr->next;
		}		
	}	
}

void searchBook(){
	if(first==NULL){
		printf("Sorry! No books found\n");
	}else
	{
		struct Book *ptr;
		int n,found=0;
		
		printf("Book no to search : ");
		fflush(stdin);
		scanf("%d",&n);
		
		ptr=first;
		while(ptr!=NULL){
			if(ptr->bookno==n){
				found=1;
				break;
			}
			ptr=ptr->next;
		}	
		if(found){
			printf("Book found :\n");
			printf("%d %s %.2f\n",ptr->bookno, ptr->title, ptr->price);
		}	
		else{
			printf("Sorry! Book Not found\n");			
		}
	}	
}

void updateBook(){
	
}

void deleteBook(){
	
}
main(){
	int choice;
	first=last=NULL; // initalize the global variable
	
	for(;;){
		system("cls");
		printf(">>> Main Menu <<<\n");
		printf("1 : Add Book\n");
		printf("2 : Show all books\n");
		printf("3 : Search a book\n");
		printf("4 : Update a book\n");
		printf("5 : Delete a book\n");
		printf("6 : Exit\n");
		printf("Enter choice : ");
		fflush(stdin); // clear the keyboard buffer
		scanf("%d",&choice);
		switch(choice){
			case 1: addBook();break;
			case 2: showBooks();break;
			case 3: searchBook();break;
			case 4: updateBook();break;
			case 5: deleteBook();break;
			case 6: exit(0);
		}
		system("pause");
	}		
}
