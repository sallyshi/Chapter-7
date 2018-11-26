//
//  ShoppingCart.hpp
//  Ch7 Shopping Cart
//
//  Created by Sally Shi on 11/13/18.
//  Copyright © 2018 Sally Shi. All rights reserved.
//

#ifndef ShoppingCart_h
#define ShoppingCart_h

#include <stdio.h>
#include <string>
#include <vector>
#include "ItemToPurchase.h"

class ShoppingCart {
public:
    // Constructor
    ShoppingCart(string customer_name = "none", string current_date = "January 1, 2016", vector<ItemToPurchase> cartItems = {});

    // Accessors
    string GetCustomerName();
    string GetDate();
    int GetNumItemsInCart();
    int GetCostOfCart();
    
    // Mutators
    void AddItem(ItemToPurchase item_to_add);
    void RemoveItem(string item_name);
    void ModifyItem(ItemToPurchase item_to_modify);
    
    // Print Functions
    void PrintTotal();
    void PrintDescriptions();

private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
};


#endif /* ShoppingCart_h */
