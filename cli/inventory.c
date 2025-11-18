#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This struct holds the memebrs of an item.
typedef struct 
{
    int itemId;
    char itemName[20];
    int quantity;
    double pricePerItem;
} Item;

// function prototypes
void insertItem(Item *inv, Item item);
void updateItem(Item *itemInventory, int itemID, int quantity);
void searchItem(Item *itemInventory, int itemID);
void printData(Item *itemInventory);
void quit(Item *itemInventory);

// define an initial array itemInventory of size N, where N=5.
Item *itemInventory;
int N = 5;
int currentIndex = 0;

int main() 
{
    itemInventory = calloc(N, sizeof(Item));
    if (itemInventory == NULL) {
        printf("Issues with allocating memory\n");
        return 1;
    }

    char choice;
    char buffer[100];

    while (1) {
        printf("*****************************************\n");
        printf("Enter your Choice:\n");
        printf("'i' - insert an item\n");
        printf("'u' - update the database\n");
        printf("'s' - search the database\n");
        printf("'d' - display the database\n");
        printf("'q' - quit the program\n");
        printf("*****************************************\n");

        printf("> ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, " %c", &choice);

        if (choice == 'i' || choice == 'I') 
        {
            Item newItem;

            printf("Enter Item ID\n");
            printf("> ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &newItem.itemId);

            printf("Enter Item Name\n");
            printf("> ");
            fgets(newItem.itemName, sizeof(newItem.itemName), stdin);
            newItem.itemName[strcspn(newItem.itemName, "\n")] = '\0';  // remove newline

            printf("Enter Item Quantity\n");
            printf("> ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &newItem.quantity);

            printf("Enter Price per Item\n");
            printf("> ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%lf", &newItem.pricePerItem);

            insertItem(itemInventory, newItem);
        }
        else if (choice == 'u' || choice == 'U') 
        {
            int id, qty;

            printf("Enter Item ID\n");
            printf("> ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &id);

            printf("Enter new quantity\n");
            printf("> ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &qty);

            updateItem(itemInventory, id, qty);
        }
        else if (choice == 's' || choice == 'S') 
        {
            int id;

            printf("Enter Item ID\n");
            printf("> ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &id);

            searchItem(itemInventory, id);
        }
        else if (choice == 'd' || choice == 'D') {
            printData(itemInventory);
        }

        else if (choice == 'q' || choice == 'Q') {
            quit(itemInventory);
        }

        else {
            printf("%c is not a valid choice\n", choice);
        }
    }
    return 0;
}

// insert a new item in the database after accepting all the necessary information about the item from the user
void insertItem(Item *inv, Item item) 
{
    // check if the ItemId is already in the database
    for (int i = 0; i < currentIndex; i++) {
        if (inv[i].itemId == item.itemId) {
            printf("Error Inserting an Item\n");
            return;
        }
    }

    // check if the database is full
    if (currentIndex == N) {
        N = N * 2;

        itemInventory = realloc(itemInventory, N * sizeof(Item));
        if (itemInventory == NULL) {
            printf("Error Inserting an Item\n");
            exit(1);
        }

        inv = itemInventory; // update local pointer
    }

    // insert the item
    inv[currentIndex] = item;
    currentIndex++;
}

// print a table showing all the items' information in the database
void printData(Item *itemInventory) 
{
    printf("*********************************************************\n");
    printf("Item ID     Item Name     Item Quantity     Item Price\n");
    printf("*********************************************************\n");

    for (int i = 0; i < currentIndex; i++) {
        printf("  %03d        %s         %d             %.2f\n",
               itemInventory[i].itemId,
               itemInventory[i].itemName,
               itemInventory[i].quantity,
               itemInventory[i].pricePerItem);
    }
}

// deallocate all the dynamic memory and exits the program
void quit(Item *itemInventory) {
    free(itemInventory);
    exit(0);
}

// prompt the user for the itemId and the new quantity and calls the updateItem()function
void updateItem(Item *itemInventory, int itemID, int quantity) {
    for (int i = 0; i < currentIndex; i++) {
        if (itemInventory[i].itemId == itemID) {
            itemInventory[i].quantity = quantity;
            return;
        }
    }
    printf("Item Not Found\n");
}

// search the database for the item information and display the id, name, the quantity, and price per item
void searchItem(Item *itemInventory, int itemID) {
    for (int i = 0; i < currentIndex; i++) {
        if (itemInventory[i].itemId == itemID) {
            printf("****************************\n");
            printf("Item ID: %03d\n", itemInventory[i].itemId);
            printf("Item Name: %s\n", itemInventory[i].itemName);
            printf("Item Quantity: %d\n", itemInventory[i].quantity);
            printf("Price per Item: %.2f\n", itemInventory[i].pricePerItem);
            printf("****************************\n");
            return;
        }
    }
    printf("Item Not Found\n");
}
