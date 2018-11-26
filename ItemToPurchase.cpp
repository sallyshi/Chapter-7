//  ItemToPurchase.cpp
//  Ch7 Shopping Cart

//Builds the ItemToPurchase class with a default constructor

#include "ItemToPurchase.h"
#include <iostream>
using namespace std;

// Parameterized constructor
ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity) {
    itemName = name;
    itemPrice = price;
    itemQuantity = quantity;
    itemDescription = description;
}

void ItemToPurchase::SetName(string name) {
    itemName = name;
}

void ItemToPurchase::SetPrice(int price) {
    itemPrice = price;
}

void ItemToPurchase::SetQuantity(int quantity){
    itemQuantity = quantity;
}

void ItemToPurchase::SetDescription(string description){
    itemDescription = description;
}

string ItemToPurchase::GetName() const {
    return itemName;
}

int ItemToPurchase::GetPrice() const {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}

string ItemToPurchase::GetDescription() const {
    return itemDescription;
}

void ItemToPurchase::PrintItemCost() {
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity*itemPrice << endl;
}

void ItemToPurchase::PrintItemDescription() {
    cout << itemName << ": " << itemDescription << endl;
}
