#include "contact.h"

int main()
{
    //all function calls should be inside the main

    int option;
    AddressBook book;
    initialize(&book);

    printf("Address Book Menu :\n");
    do
    {
	printf("\n1.Create contact\n2.Search contact\n3.Edit contact\n4.Delete contact\n5.List all contact\n6.save \n7.Exit\n");
	scanf("%d",&option);
	switch (option)
	{
	    case 1:
		createContact(&book);  //to create contact
		break;
	    case 2:
		searchContact(&book);  //to search
		break;
	    case 3:
		editContact(&book); //edit contact
		break;
	    case 4:
		deleteContact(&book);		//delte the contact
		break;
	    case 5:
		listContacts(&book);    //to list 
		break;
	    case 6:
		saveContacts(&book);   //save the changes
		break;
	    default:
		printf("invalid\n");
		break;
	}
    } while( option != 6);

}

