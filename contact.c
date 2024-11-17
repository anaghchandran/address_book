#include "contact.h"

void listContacts(AddressBook *addressBook) 
{
    printf("\n------------------------------------------------------------------------------------\n");
    printf("Name\t\t\t\tPhone\t\t\t\tEmail");						
    printf("\n------------------------------------------------------------------------------------\n");
    for( int i=0; i < addressBook->contactCount; i++)   		//running the loop for contactcount times
    {
	printf("\n%d.%s\t\t\t%s\t\t\t%s",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email); // pritnting all the contacts
    }
    printf("\n------------------------------------------------------------------------------------\n");

    printf("\n");
}


void createContact(AddressBook *addressBook) 
{
    // addressBook->contactCount++;
    int count=addressBook->contactCount;
    char name[30]; 				//to store new name ,phone, email
    char email[30];
    char phone[30];
    int flag=0;


    printf("\nEnter the name : ");                    //taking the input from uses
    getchar();
    scanf("%[^\n]",name);                               //store it in name


    do
    {
	flag=1;

	//checking user enter 10 digits
	printf("\nEnter the phone : ");                //taking phone number 
	getchar();
	scanf("%[^\n]",phone);
	if( strlen(phone) != 10) 				//validation the enter the phone number contain 10 digits 
	{
	    printf("\ninvalid : phone number should be 10 digits.\n");
	    flag=0;
	}
	else
	{
	    for( int i=0;i<10;i++) 					//validating the phone number contain any letter 
	    {
		if( phone[i] >= 'a' && phone[i] <= 'z' || phone[i] >= 'A' && phone[i] <= 'Z')
		{
		    flag=0;
		    break;
		}
	    }
	    if(flag == 0)
	    {
		printf("\ninvalid : phone number don't contain letters\n");
	    }
	    else
	    {
		for( int i=0;i< addressBook->contactCount;i++)
		{
		    if( strcmp( phone,addressBook->contacts[i].phone) == 0)		//checking the phone number is already exist or not
		    {
			flag=0;
		    }
		}
		if( flag == 0)
		{
		    printf("\nEnter the phone number is already exist.\n");
		}
	    }
	}




    }
    while(  flag == 0);


    //email


    do
    {

	printf("\nEnter the email : ");    //taking the email
	getchar();
	scanf("%[^\n]",email);
	flag=0;

	char validation1[20]="@";                
	char validation2[20]=".com";
	int len=strlen(email);
	char temp[30];
	for( int i=1;i<len;i++)
	{
	    if( email[i] == '@' )  //checking the email contain @ 
	    {
		flag=1;
		break;
	    }
	}
	if( len < 5 || strcmp( email +len-4, ".com") != 0) 		//it will be like example@gamil.com it take only last 4 and compare 
	{
	    printf("\nmust contain '@' and end with .com\n");
	    flag=0;
	}
	for( int i=0;i< addressBook->contactCount; i++)
	{
	    if( strcmp( email,addressBook->contacts[i].email) == 0) 		//checking the email is already exist
	    {
		flag=0;
	    }
	    if( flag==0)
	    {
		printf("\nEntered email is already exist\n");
	    }
	}








    }while( flag ==0  );




    strcpy( addressBook->contacts[count].name,name);
    strcpy( addressBook->contacts[count].phone,phone);    //if all validation pass the it store it into file
    strcpy( addressBook->contacts[count].email,email);

    addressBook->contactCount++;                            //incrementing count



}


void searchContact(AddressBook *addressBook)  //searching 
{
    int opt;
    printf("Enter the search option:\n1.name\n2.phone\n3.Email\n");   
    scanf("%d",&opt);
    switch (opt)
    {
	case 1:
	    int flag=0;
	    char string[30];
	    printf("Enter the search Name :\n");
	    getchar();
	    scanf("%[^\n]",string);
	    printf("\n");
	    printf("\n------------------------------------------------------------------------------------\n");
	    for( int i=0; i< addressBook->contactCount; i++)
	    {
		if(strcmp( string,addressBook -> contacts[i].name))   //searching by name
		{
		    flag++;
		}
		else
		{
		    flag=0;
		    printf("%s\t%s\t%s",addressBook->contacts[i].name,addressBook->contacts[i].phone ,addressBook ->contacts[i].email); //if find
		    break;
		}


	    }
	    if(flag >1)
	    {
		printf("--404 not found--");
	    }

	    printf("\n------------------------------------------------------------------------------------\n");
	    break;
	case 2:
	    char string1[30];
	    printf("Enter the phone number:\n");   //searching by email
	    getchar();
	    scanf("%[^\n]",string1);
	    // getchar();
	    int flag1=0;
	    printf("\n");

	    printf("\n------------------------------------------------------------------------------------\n");
	    for(int i=0;i< addressBook->contactCount;i++)
	    {
		if( strcmp( addressBook->contacts[i].phone,string1) == 0)   //comparing entered email with already existing email
		{
		    flag=1;
		    printf("%s\t%s\t%s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
		    break;
		}
	    }if(flag1==0)
	    {
		printf("--404 not found--");
	    }

	    printf("\n------------------------------------------------------------------------------------\n");
	    break;
	case 3:
	    char string2[30];
	    printf("Enter the search number:\n");              //searching by number 
	    getchar();
	    scanf("%[^\n]",string2);
	    int flag2=0;
	    printf("\n");

	    printf("\n------------------------------------------------------------------------------------\n");
	    for( int i=0;i<addressBook->contactCount;i++)
	    {
		if( strcmp( addressBook->contacts[i].email,string2) == 0)
		{
		    flag2=1;

		    printf("%s\t%s\t%s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
		    break;
		}
	    }
	    if( flag2 == 0)
	    {
		printf("--404 not found-- ");
	    }

	    printf("\n------------------------------------------------------------------------------------\n");
	    break;




	default :

	    printf("\n------------------------------------------------------------------------------------\n");
	    printf("--404 not found--");

	    printf("\n------------------------------------------------------------------------------------\n");
	    break;
    }


}

void editContact(AddressBook *addressBook) 
{
    char string[30];
    char new_name[30];
    char new_email[30];            
    char new_phone[30];
    int option=0;
    // int flag=0;
    printf("Enter the edit option:\n1.name\n2.phone\n3.email\n");
    scanf("%d",&option);
    getchar();
    switch(option)
    {
	case 1:

	    printf("Enter the Name to edit\n");                  //taking name to search
	    getchar();
	    fgets(string,30,stdin);
	    string[strcspn(string, "\n")]=0;//is commonly used in C programming to remove the newline character from a string.
	    int flag=0;
	    for( int i=0;i< addressBook->contactCount; i++)
	    {
		if(strcmp( string,addressBook->contacts[i].name) ==0 )     //comparing name with already existing name
		{
		    printf("\nEnter the name : ");
		    fgets(new_name,30,stdin);
		    new_name[strcspn(new_name, "\n")]=0;
		    strcpy(addressBook->contacts[i].name, new_name);
		    flag=1;
		}
	    }
	    if(flag== 0)
	    {
		printf("\n-not found-\n");
	    }
	    break;
	case 2:
	    int flag1=0;
	    printf("Enter the phone number:\n");              //searching by number 
	    fgets(string,30,stdin);
	    string[strcspn(string, "\n")]=0;
	    for( int i=0;i<addressBook->contactCount;i++)
	    {
		if( strcmp(string,addressBook->contacts[i].phone) ==0)
		{
		    printf("Enter the phone number :\n");

		    fgets(new_phone,30,stdin);
		    new_phone[strcspn(new_phone, "\n")]=0;

		    strcpy(addressBook->contacts[i].phone,new_phone);
		    flag1=1;
		}
	    }
	    if( flag1==0)
	    {
		printf("not found");
	    }
	    break;
	case 3:
	    printf("Enter the email:\n");   		//searching by email
	    fgets(string,30,stdin);
	    string[strcspn(string, "\n")]=0;
	    int flag2=0;

	    for(int i=0;i<addressBook->contactCount;i++)
	    {
		if( strcmp(string,addressBook->contacts[i].email) ==0)
		{
		    printf("Enter the email:\n");
		    fgets(new_email,30,stdin);
		    new_email[strcspn(new_email, "\n")]=0; 
		    strcpy( addressBook->contacts[i].email,new_email);
		    flag2=1;
		}
	    }
	    if( flag2== 0)
	    {
		printf("not fount\n");
	    }
	    break;
	default:
	    printf("invalid");
	    break;
    }








}
void saveContacts(AddressBook *addressBook)  // to save all operatton
{
    FILE *fp;
    fp=fopen("contact.csv","w");                   //opening file
    int ind=addressBook->contactCount;              
    fprintf(fp,"#%d#\n",ind);                      //upadting contactcount
    for(int i=0; i<ind; i++)
    {
        fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fp);
    printf("Changes are saved succesfully!\n");
}
void deleteContact(AddressBook *addressBook) //to delete the contact
{
    char string[30];
    char warning[10]; 
    printf("Enter the name to be deleted :\n");
    getchar();
    scanf("%[^\n]",string);
    int flag=1;


    for( int i=0; i< addressBook->contactCount;i++)
    {
	if( strcmp( string,addressBook->contacts[i].name ) ==0)
	{
	    printf("Are you sure!(yes/no) \n");
	    getchar();
	    scanf("%[^\n]",warning);
	    if(strcmp(warning ,"yes")== 0)
	    {
		//flag=1;
		for(int j=i;j < (addressBook->contactCount);j++)
		{
		    strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);		//removing contact (by copy index+1 data)
		    strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
		    strcpy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);

		}
		flag=0;
	    }
	    else
	    {

		printf("\n------------------------------------------------------------------------------------\n");
		printf("\nOperation terminated\n");
		flag=0;

		printf("\n------------------------------------------------------------------------------------\n");
	    }
	}
    }
    (addressBook->contactCount)--;
    if(flag)
    {

	printf("\n------------------------------------------------------------------------------------\n");
	printf("--404 not found--");
	printf("\n------------------------------------------------------------------------------------\n");

    }
}
