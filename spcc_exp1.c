#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of the Symbol Table
struct SymbolEntry {
    char symbol;
    void *address;
    char type[40]; // Type of the symbol (e.g., "identifier", "operator")
};

void insertSymbol(struct SymbolEntry symbolTable[], int *symbolCount, char newSymbol) {
    // Search for duplicate symbol
    for (int i = 0; i < *symbolCount; i++) {
        if (symbolTable[i].symbol == newSymbol) {
            printf("Duplicate Symbol. Cannot insert.\n");
            return;
        }
    }

    // Dynamically allocate memory for the new symbol
    symbolTable[*symbolCount].address = malloc(sizeof(int));
    if (symbolTable[*symbolCount].address == NULL) {
        printf("Memory allocation failed. Cannot insert.\n");
        return;
    }

    // Infer the type based on the symbol
    char newType[40];
    if (isalpha(newSymbol)) {
        strcpy(newType, "identifier");
    } else {
        strcpy(newType, "operator");
    }

    // Insert the new symbol
    symbolTable[*symbolCount].symbol = newSymbol;
    strcpy(symbolTable[*symbolCount].type, newType);
    (*symbolCount)++; // important 
    printf("Symbol inserted successfully.\n");
}

void displaySymbolTable(const struct SymbolEntry symbolTable[], int symbolCount) {
    printf("\nSymbol Table\n");
    printf("Symbol \t Address \t Type\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("%c \t %p \t %s\n", symbolTable[i].symbol, symbolTable[i].address, symbolTable[i].type);
    }
}

void deleteSymbol(struct SymbolEntry symbolTable[], int *symbolCount, char symbolToDelete) {
    int foundIndex = -1;
    // Search for the symbol to delete
    for (int i = 0; i < *symbolCount; i++) {
        if (symbolTable[i].symbol == symbolToDelete) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Symbol not found. Cannot delete.\n");
    } else {
        // Free the memory for the symbol
        free(symbolTable[foundIndex].address);
        // Delete the symbol by shifting elements
        for (int i = foundIndex; i < *symbolCount - 1; i++) { //important
            symbolTable[i] = symbolTable[i + 1];
        }
        (*symbolCount)--;
        printf("Symbol deleted successfully.\n");
    }
}

void searchAndDisplaySymbol(struct SymbolEntry symbolTable[], int symbolCount, char symbolToSearch) {
    int foundIndex = -1;
    // Search for the symbol to display
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].symbol == symbolToSearch) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex == -1) {
        printf("Symbol not found. Cannot display.\n");
    } else {
        // Display information about the symbol
        printf("\nSymbol Information\n");
        printf("Symbol: %c\n", symbolTable[foundIndex].symbol);
        printf("Address: %p\n", symbolTable[foundIndex].address);
        printf("Type: %s\n", symbolTable[foundIndex].type);
    }
}

void modifySymbol(struct SymbolEntry symbolTable[], int symbolCount, char symbolToModify) {
    int foundIndex = -1;
    // Search for the symbol to modify
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].symbol == symbolToModify) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Symbol not found. Cannot modify.\n");
    } else {
        // Modify the symbol (Set the type to "modified")
        printf("Symbol found. Modifying symbol type.\n");
        strcpy(symbolTable[foundIndex].type, "modified");
        printf("Symbol modified. New type: %s\n", symbolTable[foundIndex].type);
    }
}

int main() {
    struct SymbolEntry symbolTable[50];
    int symbolCount = 0;
    int choice;
    char newSymbol;
    do {
        // Display menu
        printf("\nSymbol Table Operations\n");
        printf("1. Insert Symbol\n");
        printf("2. Display Symbol Table\n");
        printf("3. Delete Symbol\n");
        printf("4. Search Symbol\n");
        printf("5. Modify Symbol\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter symbol to insert: ");
                scanf(" %c", &newSymbol);
                insertSymbol(symbolTable, &symbolCount, newSymbol);
                break;
            case 2:
                displaySymbolTable(symbolTable, symbolCount);
                break;
            case 3:
                printf("Enter symbol to delete: ");
                scanf(" %c", &newSymbol);
                deleteSymbol(symbolTable, &symbolCount, newSymbol);
                break;
            case 4:
                printf("Enter symbol to search: ");
                scanf(" %c", &newSymbol);
                searchAndDisplaySymbol(symbolTable, symbolCount, newSymbol);
                break;
            case 5:
                printf("Enter symbol to modify: ");
                scanf(" %c", &newSymbol);
                modifySymbol(symbolTable, symbolCount, newSymbol);
                break;
            case 6:
                // Free memory for all symbols before exiting
                for (int i = 0; i < symbolCount; i++) {
                    free(symbolTable[i].address);
                }
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}
