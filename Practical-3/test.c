#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Product {
    int productId;
    char productName[50];
    int productQty;
    float productPrice;
    float productTotalPrice;
    struct Product* next;
};

void displayProduct(struct Product* product) {
    printf("%d\t%s\t%d\t%.2f\t%.2f\n", product->productId, product->productName, product->productQty,
           product->productPrice, product->productTotalPrice);
}

void insertProduct(struct Product** head, int id, const char* name, int qty, float price) {
    struct Product* newProduct = malloc(sizeof(struct Product));
    if (newProduct == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newProduct->productId = id;
    strcpy(newProduct->productName, name);
    newProduct->productQty = qty;
    newProduct->productPrice = price;
    newProduct->productTotalPrice = qty * price;
    newProduct->next = *head;
    *head = newProduct;
}

struct Product* searchById(struct Product* head, int id) {
    struct Product* current = head;
    while (current != NULL) {
        if (current->productId == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct Product* searchByName(struct Product* head, const char* name) {
    struct Product* current = head;
    while (current != NULL) {
        if (strcmp(current->productName, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleteById(struct Product** head, int id) {
    struct Product* current = *head;
    struct Product* prev = NULL;

    while (current != NULL && current->productId != id) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            *head = current->next;
        }
        free(current);
        printf("Product record deleted successfully.\n");
    } else {
        printf("Product with ID %d not found.\n", id);
    }
}

void deleteByName(struct Product** head, const char* name) {
    struct Product* current = *head;
    struct Product* prev = NULL;

    while (current != NULL && strcmp(current->productName, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            *head = current->next;
        }
        free(current);
        printf("Product record deleted successfully.\n");
    } else {
        printf("Product with Name %s not found.\n", name);
    }
}

void displayAllProducts(struct Product* head) {
    printf("=========== Purchased Output Product Information =============\n");
    printf("PID\tPName\tPQty\tPprice\tPTprice\n");

    struct Product* current = head;
    while (current != NULL) {
        displayProduct(current);
        current = current->next;
    }
}

int main() {
    struct Product* head = NULL;

    int numProducts;
    printf("How many products you want to purchase: ");
    scanf("%d", &numProducts);

    for (int i = 0; i < numProducts; ++i) {
        int id, qty;
        float price;
        char name[50];

        printf("Enter product_id, product_name, product_qty, product_price for product %d: ", i + 1);
        scanf("%d %s %d %f", &id, name, &qty, &price);

        insertProduct(&head, id, name, qty, price);
    }

    displayAllProducts(head);

    char searchChoice;
    printf("Do you want to find individual product information (y/n)?: ");
    scanf(" %c", &searchChoice);

    if (searchChoice == 'y' || searchChoice == 'Y') {
        int searchType;
        printf("How do you want to find product information by ID or by Name: 1 for ID and 2 for Name: ");
        scanf("%d", &searchType);

        if (searchType == 1) {
            int searchId;
            printf("Enter product Id: ");
            scanf("%d", &searchId);

            struct Product* foundProduct = searchById(head, searchId);

            if (foundProduct != NULL) {
                printf("PID\tPName\tPQty\tPprice\tPTprice\n");
                displayProduct(foundProduct);
            } else {
                printf("Product with ID %d not found.\n", searchId);
            }
        } else if (searchType == 2) {
            char searchName[50];
            printf("Enter product Name: ");
            scanf("%s", searchName);

            struct Product* foundProduct = searchByName(head, searchName);

            if (foundProduct != NULL) {
                printf("PID\tPName\tPQty\tPprice\tPTprice\n");
                displayProduct(foundProduct);
            } else {
                printf("Product with Name %s not found.\n", searchName);
            }
        } else {
            printf("Invalid search type.\n");
        }
    }

    char deleteChoice;
    printf("Do you want to delete product record (y/n): ");
    scanf(" %c", &deleteChoice);

    if (deleteChoice == 'y' || deleteChoice == 'Y') {
        int deleteType;
        printf("How do you want to delete record by ID or By name? 1 for by ID and 2 for by Name: ");
        scanf("%d", &deleteType);

        if (deleteType == 1) {
            int deleteId;
            printf("Enter Product ID to delete: ");
            scanf("%d", &deleteId);

            deleteById(&head, deleteId);
        } else if (deleteType == 2) {
            char deleteName[50];
            printf("Enter Product Name to delete: ");
            scanf("%s", deleteName);

            deleteByName(&head, deleteName);
        } else {
            printf("Invalid delete type.\n");
        }

        printf("============= Updated Record ============\n");
        printf("PID\tPName\tPQty\tPprice\tPTprice\n");

        displayAllProducts(head);
    }

    // No explicit memory cleanup here to keep it simple. 
    // Note: In a real-world scenario, you should free the allocated memory.

    return 0;
}