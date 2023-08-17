#include <stdio.h>
#include <stdlib.h>

#include "modules/inventory.h"
#include "modules/fileio.h"
#include "modules/fileio.h"
void adminUI();
void userUI();
void ui();
int adminOptions();
int userOptions();
int options();
void pause();
void login();

int main()
{
    user newUser= user_init(-1,"admin","admin");
    user_add(&newUser,"admin.txt");
    login();

    return 0;
}

void login(){
    while (1) {
        printf("1. User Login\n");
        printf("2. Admin Login\n");
        printf("0. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char username[16];
                char password[32];

                printf("Enter username: ");
                scanf("%s", username);

                printf("Enter password: ");
                scanf("%s", password);

                int userId = authenticateUser("user.txt", username, password);
                if (userId != -1) {
                    userUI();
                } else {
                    printf("User Login failed. Invalid username or password.\n");
                    pause(1);
                }
                break;
            }

            case 2: {
                char username[16];
                char password[32];

                printf("Enter admin username: ");
                scanf("%s", username);

                printf("Enter admin password: ");
                scanf("%s", password);

                int adminId = authenticateUser("admin.txt", username, password);
                printf("admin id: %d\n",adminId);
                if (adminId != -1) {
                    adminUI();
                } else {
                    printf("Admin Login failed. Invalid username or password.\n");
                    pause(1);
                }
                break;
            }
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
}

void userUI()
{
    while(1)
    {
        int selected = userOptions();
        if (selected == 0)
        {
            break;
        }
        switch(selected)
        {
            case 1:
                printf("\n");
                books_print_all();
                pause(1);
                break;
            case 2:
                printf("\n");
                inventory_find();
                pause(1);
                break;
            case 3:
                printf("\n");
                inventory_lend();
                pause(0);
                break;
            case 4:
                printf("\n");
                inventory_return();
                pause(0);
                break;
            default:
                printf("Incorrect option..\n");
                pause(1);
        }
    }
}
void adminUI(){
    while(1)
    {
        int selected = adminOptions();
        if (selected == 0)
        {
            break;
        }
        switch(selected)
        {
            case 1:
                printf("\n");
                fgetc(stdin);
                book_read_and_add();
                pause(0);
                break;
            case 2:
                printf("\n");
                books_print_all();
                pause(1);
                break;
            case 3:
                printf("\n");
                book_find();
                pause(1);
                break;
            case 4:
                printf("\n");
                fgetc(stdin);
                inventory_read_and_add();
                pause(0);
                break;
            case 5:
                printf("\n");
                fgetc(stdin);
                inventory_read_and_remove();
                pause(0);
                break;
            case 6:
                printf("\n");
                inventory_find();
                pause(1);
                break;
            case 7:
                printf("\n");
                inventory_lend();
                pause(0);
                break;
            case 8:
                printf("\n");
                inventory_return();
                pause(0);
                break;
            case 9:
                printf("\n");
                inventory_print_all();
                pause(1);
                break;
            case 10:
                registerUser("user.txt");
                pause(1);
                break;
            case 11:
                registerUser("admin.txt");
                pause(1);
                break;
            default:
                printf("Incorrect option..\n");
                pause(1);
        }
}
}
int adminOptions()
{
    printf("\n");
    printf("----------MENU------------\n");
    int i = 1;
    printf("%d:\t Add book\n", i); // 1
    i++;
    printf("%d:\t Print all books\n", i); // 2
    i++;
    printf("%d:\t Find book\n", i); // 3
    i++;
    printf("%d:\t Add to inventory\n", i); // 4
    i++;
    printf("%d:\t Remove from inventory\n", i); // 5
    i++;
    printf("%d:\t Check availability of book\n", i); // 6
    i++;
    printf("%d:\t Lend Book\n", i); // 7
    i++;
    printf("%d:\t Return Book\n", i); // 8
    i++;
    printf("%d:\t Print all inventory\n", i); // 9
    i++;
    printf("%d:\t Add User\n", i); // 10
    i++;
    printf("%d:\t Add Admin\n", i); // 11

    printf("0:\t Logout\n");
    printf("Enter option: ");
    fscanf(stdin, "%d", &i);
    return i;
}
int userOptions()
{
    printf("\n");
    printf("----------MENU------------\n");
    int i = 1;
    printf("%d:\t Print all books\n", i); // 1
    i++;
    printf("%d:\t Check availability of book\n", i); // 2
    i++;
    printf("%d:\t Lend Book\n", i); // 3
    i++;
    printf("%d:\t Return Book\n", i); // 4
    i++;
    printf("0:\t Logout\n");
    printf("Enter option: ");
    fscanf(stdin, "%d", &i);
    return i;
}

void pause(int do_get)
{
    printf("Press Enter to continue...");
    while(do_get--)
    {
        fgetc(stdin);
    }
    while(fgetc(stdin) != '\n');
    printf("\n");
}