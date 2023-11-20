#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// All User define Data type and database Here:

struct menu {
    int itemID;
    char name[25];
    int price;
    int slotstatus;
};
struct item {
    char name[20];
    int price;
    int quantity;
    bool slotstatus;
};
struct Table {
    struct item I[50];
    bool slotstatus;
};

// All Functions Declaration here:

void setTextColor(int color);
void resetTextColor();

int homescreen();
int choosetable();
void generatebill();
void showmenu();
void additem();
void retry();
void removeitem();
void orderhistory();
void changeprice();
void additeminmenu();
void removeitemfrommenu();
void MenuManagement();
void TableManagement();
void addtable();
void cleartabledata();
void tablestatus();
void viewalltable();
void removetable();
void BillManagement();
void back();

void setTextColor(int color) {
    printf("\033[1;%dm", color);
}

void resetTextColor() {
    printf("\033[0m");
}

int homescreen() {
    int i;
    system("cls");

    setTextColor(36); // Set text color to cyan
    printf("\n###################################");
    printf("\n#      HOTEL MANAGEMENT          #");
    printf("\n###################################");
    resetTextColor();

    setTextColor(33); // Set text color to yellow
    printf("\n\n******** Choose an option ********\n\n");
    resetTextColor();

    setTextColor(32); // Set text color to green
    printf("\t 1. Bill Management\n");
    printf("\t 2. Menu Management\n");
    printf("\t 3. Table Management\n");
    printf("\t 4. Exit the program\n\n");
    resetTextColor();

    setTextColor(31); // Set text color to red
    printf("Enter Your option: ");
    scanf("%d", &i);
    resetTextColor();

    return i;
}

void BillManagement(int table, struct Table *T, struct menu *M) {
    int i;
    system("cls");

    printf("\033[1;35m"); // Set text color to blue for the banner
    printf("\n###################################");
    printf("\n#       BILL MANAGEMENT          #");
    printf("\n###################################");
    printf("\033[0m"); // Reset text color

    printf("\n\n\033[1;32m"); // Set text color to green
    printf(" 1. Add Item\n");
    printf(" 2. Remove Item\n");
    printf(" 3. Generate Bill\n");
    printf(" 4. View Order History\n");
    printf(" 5. Back\n\n");
    printf("\033[0m"); // Reset text color

    printf("\033[1;33m"); // Set text color to yellow
    printf("Enter your choice: ");
    scanf("%d", &i);
    printf("\033[0m"); // Reset text color

    switch (i) {
        case 1: {
            additem(table, T, M);
            break;
        }
        case 2: {
            removeitem(table, T);
            break;
        }
        case 3: {
            generatebill(table, T);
            break;
        }
        case 4: {
            showaddeditems(table, T,M);
            break;
        }
        case 5: {
            back();
            break;
        }
        default: {
            retry();
        }
    }
}

void MenuManagement(struct menu *M) {
    int i;
    system("cls");

    printf("\033[1;35m"); // Set text color to blue for the banner
    printf("\n###################################");
    printf("\n#     MENU MANAGEMENT            #");
    printf("\n###################################");
    printf("\033[0m"); // Reset text color

    printf("\n\n\033[1;32m"); // Set text color to green
    printf(" 1. Add Item in Menu\n");
    printf(" 2. Remove Item from Menu\n");
    printf(" 3. Change Price\n");
    printf(" 4. Display Menu\n");
    printf(" 5. Back\n\n");
    printf("\033[0m"); // Reset text color

    printf("\033[1;33m"); // Set text color to yellow
    printf("Enter your choice: ");
    scanf("%d", &i);
    printf("\033[0m"); // Reset text color

    switch (i) {
        case 1: {
            additeminmenu(M);
            break;
        }
        case 2: {
            removeitemfrommenu(M);
            break;
        }
        case 3: {
            changeprice(M);
            break;
        }
        case 4: {
            showmenu(M);
            break;
        }
        case 5: {
            back();
            break;
        }
        default: {
            retry();
        }
    }
}

void TableManagement(struct Table *T) {
    int i;
    system("cls");

    printf("\033[1;35m"); // Set text color to magenta for the banner
    printf("\n###################################");
    printf("\n#       TABLE MANAGEMENT          #");
    printf("\n###################################");
    printf("\033[0m"); // Reset text color

    printf("\n\n\033[1;32m"); // Set text color to green
    printf(" 1. Add Table\n");
    printf(" 2. Remove Table\n");
    printf(" 3. View all Tables\n");
    printf(" 4. Change Table Status\n");
    printf(" 5. Clear Table Data\n");
    printf(" 6. Back\n\n");
    printf("\033[0m"); // Reset text color

    printf("\033[1;33m"); // Set text color to yellow
    printf("Enter your choice: ");
    scanf("%d", &i);
    printf("\033[0m"); // Reset text color

    switch (i) {
        case 1: {
            addtable(T);
            break;
        }
        case 2: {
            removetable(T);
            break;
        }
        case 3: {
            viewalltable(T);
            break;
        }
        case 4: {
            tablestatus(T);
            break;
        }
        case 5: {
            cleartabledata(T);
            break;
        }
        case 6: {
            back();
            break;
        }
        default: {
            retry();
            break;
        }
    }
}

void additem(int table, struct Table *T, struct menu *M) {
    int itemid, itemquantity, i;
    system("cls");

    i=0;
    while(M[i].slotstatus)
    {
        i++;
    }

    setTextColor(36); // Set text color to cyan
    printf("\n###################################");
    printf("\n#        ADD ITEM                #");
    printf("\n###################################");
    resetTextColor();

    printf("\n\nEnter product id: ");
    scanf("%d", &itemid);
    //i--;
    itemid--;
    if (itemid > i) {
        printf("\nEnter itemID Bound In Menu !");
        getch();
        BillManagement(table, T, M);
    }
    printf("\nEnter quantity: ");
    scanf("%d", &itemquantity);

    int emptyslot = -1;
    for (i = 0; i < 50; i++) {
        if (!(T[table].I[i].slotstatus)) {
            T[table].I[i].slotstatus = true;
            emptyslot = i;
            break;
        }
    }

    if (emptyslot != -1) {
        strcpy(T[table].I[emptyslot].name, M[itemid].name);
        T[table].I[emptyslot].quantity = itemquantity;
        T[table].I[emptyslot].price = M[itemid].price;
        T[table].I[i].slotstatus = true;
        printf("\nSuccessfully added %s\n", T[table].I[emptyslot].name);
    } else {
        printf("No empty slots available in the table.\n");
    }

    printf("\nEnter any keyboard key to continue.");
    getch();
    BillManagement(table, T, M);
}


void removeitem(int table, struct Table *T) {
    int slotid, i;
    system("cls");

    printf("\033[1;36m"); // Set text color to cyan for the banner
    printf("\n###################################");
    printf("\n#       REMOVE ITEM               #");
    printf("\n###################################");
    printf("\033[0m"); // Reset text color

    printf("\nItemID\tName\tQuantity");
    for (i = 0; i < 50; i++) {
        if (T[table].I[i].slotstatus == false)
            break;
        printf("\n%d\t%s\t%d", i + 1, T[table].I[i].name, T[table].I[i].quantity);
    }

    printf("\n\nEnter slot no to delete.\n");
    scanf("%d", &slotid);

    for (i = slotid - 1; T[table].I[i].slotstatus; i++) {
        strcpy(T[table].I[i].name, T[table].I[i + 1].name);
        T[table].I[i].quantity = T[table].I[i + 1].quantity;
    }

    T[table].I[i].slotstatus = false;
    T[table].I[i].quantity = 0;
    strcpy(T[table].I[i].name, "");

    printf("\nUpdated list");
    printf("\nitemID\t  name  \tquantity");
    for (i = 0; i < 50; i++) {
        if (T[table].I[i].slotstatus == false)
            break;
        printf("\n%d  \t%s  \t%d", i + 1, T[table].I[i].name, T[table].I[i].quantity);
    }

    getch();
}

void generatebill(int table,struct Table *T)
{
   int i;
   int *pt;
   system("cls");
   FILE *gb=NULL;
   fopen("Generated Bill.txt","w");
    if (gb == NULL)
    {
        system("cls");
        printf("There is an error creating file or opening file. Make sure 'Generated Bill.txt' is present in project folder.If not create a text file named as mentioned. and try again.");
    }
    else
    {
        for(i=0;i<50;i++)
        {

        }
    }
    fclose(gb);
   getch();
}

void showaddeditems(int table, struct Table *T,struct menu *M) {
    system("cls");

    printf("\033[1;36m"); // Set text color to cyan for the banner
    printf("\n###################################");
    printf("\n#     SHOW ADDED ITEMS            #");
    printf("\n###################################");
    printf("\033[0m"); // Reset text color

    printf("\nItemID\tName\tQuantity");
    for (int i = 0; T[table].I[i].slotstatus; i++) {
        printf("\n%d\t%s\t%d", i + 1, T[table].I[i].name, T[table].I[i].quantity);
    }

    getch();
    BillManagement(table, T, M);
}

void additeminmenu(struct menu *M) {
    char name[20];
    int price, i;
    system("cls");

    printf("\033[1;36m"); // Set text color to cyan for the banner
    printf("\n###################################");
    printf("\n#    ADD ITEM IN MENU             #");
    printf("\n###################################");
    printf("\033[0m"); // Reset text color

    for (i = 0; M[i].slotstatus; i++) {
        printf("\n%d %s %d", M[i].itemID + 1, M[i].name, M[i].price);
    }

    printf("\n\nEnter name of item: ");
    fflush(stdin);
    gets(name);

    printf("\nEnter price of item: ");
    scanf("%d", &price);

    M[i].itemID = i;
    strcpy(M[i].name, name);
    M[i].price = price;
    M[i].slotstatus = true;

    printf("\nUpdated Menu: ");
    for (i = 0; M[i].slotstatus; i++) {
        printf("\n%d %s %d", M[i].itemID + 1, M[i].name, M[i].price);
    }

    getch();
    MenuManagement(M);
}

void removeitemfrommenu(struct menu *M) {
    int slotid, i;
    system("cls");

    printf("\033[1;36m"); // Set text color to cyan for the banner
    printf("\n###################################");
    printf("\n#   REMOVE ITEM FROM MENU         #");
    printf("\n###################################");
    printf("\033[0m"); // Reset text color

    for (i = 0; M[i].slotstatus; i++) {
        printf("\n%d %s %d", M[i].itemID + 1, M[i].name, M[i].price);
    }

    printf("\n\nEnter itemID of item to remove : ");
    scanf("%d", &slotid);

    for (i = slotid - 1; M[i].slotstatus; i++) {
        strcpy(M[i].name, M[i + 1].name);
        M[i].price = M[i + 1].price;
    }

    M[i - 1].slotstatus = false;
    M[i - 1].slotstatus = 0;
    strcpy(M[i - 1].name, "");

    printf("\n\nUpdated Menu: ");
    for (i = 0; M[i].slotstatus; i++) {
        printf("\n%d %s %d", M[i].itemID + 1, M[i].name, M[i].price);
    }

    getch();
    MenuManagement(M);
}

void changeprice(struct menu *M) {
    int price, itemid, i;
    system("cls");

    printf("\033[1;36m"); // Set text color to cyan for the banner
    printf("\n###################################");
    printf("\n#       CHANGE PRICE              #");
    printf("\n###################################");
    printf("\033[0m"); // Reset text color

    printf("\nitemID\tname\tprice");
    for (i = 0; M[i].slotstatus; i++) {
        printf("\n%d\t%s\t%d", M[i].itemID + 1, M[i].name, M[i].price);
    }

    printf("\n\nEnter itemID of item to change price: ");
    scanf("%d", &itemid);
    printf("\nEnter Updated Price: ");
    scanf("%d", &price);
    M[itemid - 1].price = price;

    printf("\n\nUpdated List");
    printf("\nitemID\t  name  \tprice");
    for (i = 0; M[i].slotstatus; i++) {
        printf("\n%d  \t%s  \t%d", M[i].itemID + 1, M[i].name, M[i].price);
    }

    getch();
    MenuManagement(M);
}

void showmenu(struct menu *M) {
    system("cls");

    printf("\033[1;36m"); // Set text color to cyan for the banner
    printf("\n###################################");
    printf("\n#         SHOW MENU               #");
    printf("\n###################################");
    printf("\033[0m"); // Reset text color

    printf("\nItemID\tName\tPrice");
    for (int i = 0; M[i].slotstatus; i++) {
        printf("\n%d\t%s\t%d", M[i].itemID + 1, M[i].name, M[i].price);
    }

    getch();
    MenuManagement(M);
}

void addtable(struct Table *T) {
    int i, tabletoadd, lasttableindex;
    system("cls");

    printf("\033[1;36m"); // Set text color to cyan for the banner
    printf("\n###################################");
    printf("\n#        ADD TABLES               #");
    printf("\n###################################");
    printf("\033[0m"); // Reset text color

    for (i = 0; T[i].slotstatus; i++) {
        printf("\nTable No %d \n", i + 1);
    }

    lasttableindex = i;
    printf("%d", lasttableindex);
    printf("\n\nEnter How many tables to add (max 20): ");
    scanf("%d", &tabletoadd);

    if ((lasttableindex + tabletoadd) > 20) {
        printf("\nMaximum 20 tables can be created");
        getch();
        TableManagement(T);
    }

    for (i = lasttableindex; i < (tabletoadd + lasttableindex); i++) {
        T[i].slotstatus = true;
    }

    for (i = 0; T[i].slotstatus; i++) {
        printf("Table No %d \n", i + 1);
    }

    getch();
    TableManagement(T);
}

void removetable(struct Table *T) {
    int Tableno, i;
    system("cls");

    printf("\033[1;36m"); // Set text color to cyan for the banner
    printf("\n###################################");
    printf("\n#       REMOVE TABLE              #");
    printf("\n###################################");
    printf("\033[0m"); // Reset text color

    Tableno = choosetable(T);
    T[Tableno].slotstatus = false;

    printf("\n\nUpdated Table: ");
    for (i = 0; T[i].slotstatus; i++) {
        printf("\nTable no %d ", i);
    }

    getch();
    TableManagement(T);
}

void viewalltable(struct Table *T) {
    system("cls");

    printf("\033[1;36m"); // Set text color to cyan for the banner
    printf("\n###################################");
    printf("\n#     VIEW ALL TABLES             #");
    printf("\n###################################");
    printf("\033[0m"); // Reset text color

    for (int i = 0; T[i].slotstatus; i++) {
        printf("\nTable no %d", i + 1);
    }

    getch();
    TableManagement(T);
}

void tablestatus()
{
    system("cls");
    printf("table status function");
}

void cleartabledata(struct Table *T) {
    system("cls");
    int i, tableno;

    printf("\033[1;36m"); // Set text color to cyan for the banner
    printf("\n###################################");
    printf("\n#     CLEAR TABLE DATA            #");
    printf("\n###################################");
    printf("\033[0m"); // Reset text color

    tableno = choosetable(T);

    for (i = 0; T[tableno].I[i].slotstatus; i++) {
        T[tableno].I[i].slotstatus = false;
    }
    T[tableno].slotstatus = false;

    printf("\n\nSuccessfully cleared Table no %d data.", tableno + 1);
    getch();
    TableManagement(T);
}

int choosetable(struct Table *T)
{
    int i;
    system("cls");

    printf("\033[1;34m");
    printf("\n###################################");
    printf("\n#      TABLE SELECTION           #");
    printf("\n###################################");

    printf("\n\nAvailable Tables:\n\n");

    printf("\033[1;32m"); // Set text color to green
    for (i = 0; T[i].slotstatus; i++) {
        printf("Table No %d\n", i + 1);
    }
    printf("\033[0m"); // Reset text color

    printf("\n\033[1;33m"); // Set text color to yellow
    printf("Enter the table number: ");
    scanf("%d", &i);
    printf("\033[0m"); // Reset text color

    i--;

    return i;
}

void areyousure()
{
   int yon;
   system("cls");
   printf("\n------------------------------------------------------------------------------");
   printf("\n                                  Are You sure?");
   printf("\n------------------------------------------------------------------------------");
   printf("\n\n\n\n\n\n\t\t\t\t Generate Bill");
   printf("\n\n\n\n\n\t\t\t        Yes = 1 No = 0\n\n\n\t\t\t\t");
   scanf("%d",&yon);
   switch(yon)
   {
      case 1:
      {
	      //generatebill();
	      return;
      }
      case 0:
      {
	      return;
      }
      default:
      {
	      retry();
      }
   }
}

void menulist(struct menu *m)
{
    for(int i=0;i<10;i++)
    {
        m[i].itemID=i;
        m[i].slotstatus=true;
    }
    m[0].price=20;
    m[1].price=25;
    m[2].price=25;
    m[3].price=25;
    m[4].price=30;
    m[5].price=30;
    m[6].price=50;
    m[7].price=50;
    m[8].price=70;
    m[9].price=70;
    strcpy(m[0].name,"Regular Tea");
    strcpy(m[1].name,"Masala Tea");
    strcpy(m[2].name,"COffee");
    strcpy(m[3].name,"Cold Drink");
    strcpy(m[4].name,"Bread Butter");
    strcpy(m[5].name,"Bread Jam");
    strcpy(m[6].name,"Veg Sandwich");
    strcpy(m[7].name,"Veg Toast Sandwich");
    strcpy(m[8].name,"Cheese Toast Sandwich");
    strcpy(m[9].name,"Grilled Sandwich");
}

void back()
{
    system("cls");
    printf("Back");
}

void retry()
{
   system("cls");
   printf("\n\n\n\n\n\n\t\t\t\t Invalid Input");
   printf("\n\n\n\n\n\t\t       please choose from the option below.\n\n\n\n\t\t\t\t");
   getch();
   main();
}

void orderhistory()
{
    system("cls");
    printf("Order History");
}

int main()
{
   int option=0;
   int table;
   struct Table T[20];
   struct menu M[100];
   for(int i=0;i<50;i++)
   {
       for(int j=0;j<20;j++)
       {
           T[j].I[i].slotstatus=false;
           T[j].slotstatus=false;
       }
       M[i].slotstatus=false;
   }
   for(int j=0;j<5;j++)
   {
       T[j].slotstatus=true;
   }
   menulist(&M);
   system("cls");
   option=homescreen();
   switch(option)
   {
      case 1:
      {
	      table=choosetable(&T);
          BillManagement(table,&T,&M);
      }
      case 2:
      {
	      MenuManagement(&M);
	      break;
      }
      case 3:
      {
          TableManagement(&T);
      }
      case 4:
      {
	      abort();
	      break;
      }
      default:
	      retry();
   }

   getch();
   return 0;
}
