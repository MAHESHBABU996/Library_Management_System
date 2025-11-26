#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "library.dat"

typedef struct {
    int id;
    char title[50];
    char author[50];
    int quantity;
    int issued;
} Book;

void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void deleteBook();

int main() {
    int choice;

    while (1) {
        printf("\n======================================\n");
        printf("        LIBRARY MANAGEMENT SYSTEM\n");
        printf("======================================\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: deleteBook(); break;
            case 7: exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void addBook() {
    FILE *fp = fopen(FILE_NAME, "ab");
    Book b;

    printf("\nEnter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", b.title);
    printf("Enter Author Name: ");
    scanf(" %[^\n]", b.author);
    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);

    b.issued = 0;

    fwrite(&b, sizeof(Book), 1, fp);
    fclose(fp);

    printf("Book added successfully!\n");
}

void displayBooks() {
    FILE *fp = fopen(FILE_NAME, "rb");
    Book b;

    if (!fp) {
        printf("No books available.\n");
        return;
    }

    printf("\n%-5s %-30s %-20s %-10s %-10s\n", "ID", "Title", "Author", "Qty", "Issued");
    printf("--------------------------------------------------------------------------\n");

    while (fread(&b, sizeof(Book), 1, fp)) {
        printf("%-5d %-30s %-20s %-10d %-10d\n", b.id, b.title, b.author, b.quantity, b.issued);
    }

    fclose(fp);
}

void searchBook() {
    FILE *fp = fopen(FILE_NAME, "rb");
    int id, found = 0;
    Book b;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
            printf("\nBook Found!\n");
            printf("ID: %d\n", b.id);
            printf("Title: %s\n", b.title);
            printf("Author: %s\n", b.author);
            printf("Quantity: %d\n", b.quantity);
            printf("Issued: %d\n", b.issued);
            found = 1;
            break;
        }
    }

    if (!found) printf("Book not found!\n");

    fclose(fp);
}

void issueBook() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    int id, found = 0;
    Book b;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {

            if (b.issued < b.quantity) {
                b.issued++;
                fseek(fp, -sizeof(Book), SEEK_CUR);
                fwrite(&b, sizeof(Book), 1, fp);
                printf("Book issued successfully!\n");
            } else {
                printf("All copies are already issued!\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) printf("Book not found!\n");

    fclose(fp);
}

void returnBook() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    int id, found = 0;
    Book b;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(Book), 1, fp)) {

        if (b.id == id) {
            if (b.issued > 0) {
                b.issued--;
                fseek(fp, -sizeof(Book), SEEK_CUR);
                fwrite(&b, sizeof(Book), 1, fp);
                printf("Book returned successfully!\n");
            } else {
                printf("No issued copies to return.\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) printf("Book not found!\n");

    fclose(fp);
}

void deleteBook() {
    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    int id, found = 0;
    Book b;

    printf("\nEnter Book ID to delete: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
            found = 1;
            continue;
        }
        fwrite(&b, sizeof(Book), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found)
        printf("Book deleted successfully!\n");
    else
        printf("Book not found!\n");
}
