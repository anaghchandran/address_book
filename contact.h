#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

//structure with member name , phone , email and typedef with new name Contact.

typedef struct {
    Contact *contacts; //contacts is member 
    int contactCount;
} AddressBook;
//its basicall array of size 100(define 100).typedef it to AddressBook.

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContacts(AddressBook *addressBook);

#endif
