// main.cpp
// Ch7 Shopping Cart

//  Prompts user for 2 items and create 2 objects of the ItemToPurchase class.
// Returns total cost of the 2 items.

#include <iostream>
#include <string>
#include <sstream>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"
using namespace std;

void PrintMenu(ShoppingCart cart) {
    // User input variables
    string input_string;
    char input;
    string name;
    string description;
    string temp;
    int price;
    int quantity;
    
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;
    getline(cin, input_string);
    istringstream iss(input_string);
    iss >> input;
    while (input != 'q') {
        if(input == 'a') {
            cout << endl;
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, name);
            cout << "Enter the item description:" << endl;
            getline(cin, description);
            cout << "Enter the item price:" << endl;
            getline(cin,input_string);
            istringstream pstream(input_string);
            pstream >> price;
            cout << "Enter the item quantity:" << endl;
            getline(cin,input_string);
            istringstream qstream(input_string);
            qstream >> quantity;
            ItemToPurchase item(name, description, price, quantity);
            cart.AddItem(item);
        } else if (input == 'd') {
            cout << endl;
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:" << endl;
            getline(cin, name);
            cart.RemoveItem(name);
        } else if (input == 'c') {
            cout << endl;
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin,name);
            cout << "Enter the new quantity:" << endl;
            getline(cin,input_string);
            istringstream qstream(input_string);
            qstream >> quantity;
            ItemToPurchase item_modify;
            item_modify.SetName(name);
            item_modify.SetQuantity(quantity);
            cart.ModifyItem(item_modify);
        } else if (input == 'i') {
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            cart.PrintDescriptions();
        } else if (input == 'o') {
            cout << "OUTPUT SHOPPING CART" << endl;
            cart.PrintTotal();
        } else {
            cout << "Choose an option:" << endl;
            cin.sync();
            getline(cin, input_string);
            istringstream iss(input_string);
            iss >> input;
            continue;
        }
            cout << endl;
            cout << "MENU" << endl;
            cout << "a - Add item to cart" << endl;
            cout << "d - Remove item from cart" << endl;
            cout << "c - Change item quantity" << endl;
            cout << "i - Output items' descriptions" << endl;
            cout << "o - Output shopping cart" << endl;
            cout << "q - Quit" << endl;
            cout << endl;
            cout << "Choose an option:" << endl;
            cin.sync();
            getline(cin, input_string);
            istringstream iss(input_string);
            iss >> input;
    }
}

int main() {
    
    string inputCustomerName;
    string inputCurrentDate;
    
    cout << "Enter customer's name:" << endl;
    getline(cin, inputCustomerName);
    cout << "Enter today's date:" << endl;
    getline(cin, inputCurrentDate);
    cout << endl;
    
    ShoppingCart cart(inputCustomerName, inputCurrentDate);
    cout << "Customer name: " << cart.GetCustomerName() << endl;
    cout << "Today's date: " << cart.GetDate() << endl;
    cout << endl;
    
    PrintMenu(cart);
    
    return 0;
}
