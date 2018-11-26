//
//  ShoppingCart.cpp
//  Ch7 Shopping Cart
//
//  Created by Sally Shi on 11/13/18.
//  Copyright © 2018 Sally Shi. All rights reserved.
//

#include <iostream>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"

using namespace std;

// Parameterized constructor
ShoppingCart::ShoppingCart(string customer_name, string current_date, vector<ItemToPurchase> cart_items) {
    customerName = customer_name;
    currentDate = current_date;
    cartItems = cart_items;
}

// Accessors
string ShoppingCart::GetCustomerName() {
    return customerName;
}

string ShoppingCart::GetDate() {
    return currentDate;
}

int ShoppingCart::GetNumItemsInCart() {
    int n = 0;
    for (unsigned i = 0; i < cartItems.size(); i++) {
        n += cartItems.at(i).GetQuantity();
    }
    return n;
}

int ShoppingCart::GetCostOfCart() {
    int c = 0;
    for (unsigned i = 0; i < cartItems.size(); i++) {
        c += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
    }
    return c;
}

// Mutators
void ShoppingCart::AddItem(ItemToPurchase item_to_add) {
    cartItems.push_back(item_to_add);
}

void ShoppingCart::RemoveItem(string item_name) {
    unsigned i = 0;
    bool itemFound = false;
    
    while (i < cartItems.size()) {
        if(cartItems.at(i).GetName() == item_name) {
            itemFound = true;
            cartItems.erase(cartItems.begin() + i);
        }
        i++;
    }
    if (!itemFound){
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::ModifyItem(ItemToPurchase item_to_modify) {
    unsigned i = 0;
    bool itemFound = false;
    while (i < cartItems.size()) {
        if(cartItems.at(i).GetName() == item_to_modify.GetName()) {
            itemFound = true;
            if(item_to_modify.GetQuantity() != 0) {
                cartItems.at(i).SetQuantity(item_to_modify.GetQuantity());
            }
            if(item_to_modify.GetPrice() != 0) {
                cartItems.at(i).SetPrice(item_to_modify.GetPrice());
            }
            if(item_to_modify.GetDescription() != "none") {
        cartItems.at(i).SetDescription(item_to_modify.GetDescription());
            }
        }
        i++;
    }
    if(!itemFound) {
    cout << "Item not found in cart. Nothing modified." << endl;
    }
    }

// Print Functions
void ShoppingCart::PrintTotal() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl;
    if(GetNumItemsInCart()==0) {
        cout << endl;
        cout << "SHOPPING CART IS EMPTY";
    }
    cout << endl;
    for (unsigned i = 0; i < cartItems.size(); i++) {
        cartItems.at(i).PrintItemCost();
    }
    cout << endl;
    cout << "Total: $" << GetCostOfCart() << endl;
}

void ShoppingCart::PrintDescriptions() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << endl;
    cout << "Item Descriptions" << endl;
    for (unsigned i = 0; i < cartItems.size(); i++) {
        cartItems.at(i).PrintItemDescription();
    }
}
