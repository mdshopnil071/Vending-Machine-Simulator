#include <stdio.h>
#include <string.h>

struct Item { char name[20]; float price; int stock; };

void showMenu(struct Item items[], int size) 
{
    printf("\n----- Vending Machine Menu -----\n");
      for(int i = 0; i < size; i++)
    printf("%d. %s - $%.2f (%d left)\n", i + 1, items[i].name, items[i].price, items[i].stock);
    printf("%d. Exit\n", size + 1);
}

void purchaseItemCash(struct Item items[], int choice, float money) 
{
      if (items[choice].stock > 0 && money >= items[choice].price) 
  {
    items[choice].stock--; 
printf("\nDispensing %s...\nYourchange: $%.2f\n", items[choice].name, money - items[choice].price);
  }
      else printf(items[choice].stock > 0 ? "Insufficient funds!\n" : "Out of stock!\n");
}

void purchaseItemOnline(struct Item items[], int choice, char method[]) 
{
char number[15]; 
printf("Enter your %s number: ", method); 
scanf("%s", number);
      if (items[choice].stock > 0) 
  {
        items[choice].stock--; 
printf("\nDispensing %s...\n$%.2f deducted from %s (%s).\n", items[choice].name, items[choice].price, method, number);
  }   else printf("Out of stock!\n");
}

int main() {
    struct Item items[] = { 
        {"Soda",1.50,5}, 
        {"Chips",1.00,3}, 
        {"Candy",0.75,7}, 
        {"Biscuit",2.75,10}, 
        {"Juice",1.75,12}, 
        {"Chocolate",2.00,20} };
    int choice, paymentChoice, onlineChoice; float money;

      while (1) {
        showMenu(items, 6); 
    printf("\nEnter choice (1-6) or 7 to exit: "); 
        scanf("%d", &choice);
     if (choice == 7) break;
     if (choice < 1 || choice > 6) 
  { printf("Invalid choice!\n"); continue; }

    printf("\nPayment Method: 1. Cash 2. Online\nEnter choice: "); scanf("%d", &paymentChoice);
     if (paymentChoice == 1) { printf("Insert money: $"); scanf("%f", &money); purchaseItemCash(items, choice - 1, money); }
     else if (paymentChoice == 2) 
{
    printf("\nOnline Payment: 1. Bkash 2. Nagad\nEnter choice: "); 
        scanf("%d", &onlineChoice);
     if (onlineChoice == 1) purchaseItemOnline(items, choice - 1, "Bkash");
     else if (onlineChoice == 2) purchaseItemOnline(items, choice - 1, "Nagad");
     else printf("Invalid choice!\n");
}    
     else printf("Invalid payment method!\n");
    }
    printf("Thank you for using the vending machine!\n");
return 0;
}
