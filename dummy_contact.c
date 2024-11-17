#include "contact.h"
void initialize(AddressBook *addressBook) {
    FILE *fptr;
    addressBook->contacts = NULL;
    addressBook->contactCount = 0;

    if ((fptr = fopen("contact.csv", "r")) == NULL)   
    {
        printf("Failed to open file: contact.csv\n");
        return;
    }

    int n;
    fscanf(fptr, "#%d#\n", &n);

    // Allocate memory for contacts
    addressBook->contacts = (Contact *)malloc(n * sizeof(Contact));
    if (addressBook->contacts == NULL) {
        printf("Memory allocation failed\n");
        fclose(fptr);
        return;
    }

    // Read contacts from file
    for (int i = 0; i < n; i++) {
        if (fscanf(fptr, "%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email) != 3) {
            printf("Error reading contact data\n");
            free(addressBook->contacts);
            addressBook->contacts = NULL;
            addressBook->contactCount = 0;
            fclose(fptr);
            return;
        }
        addressBook->contactCount++;
    }

    fclose(fptr);
}


