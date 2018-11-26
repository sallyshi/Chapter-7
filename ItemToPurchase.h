//  ItemToPurchase.h
//  Ch7 Shopping Cart

// Defines ItemToPurchase class

#ifndef ItemToPurchase_h
#define ItemToPurchase_h

#include <stdio.h>
#include <string>
using namespace std;

class ItemToPurchase {
    
public:
    // constructor
    ItemToPurchase(string inputName = "none", string inputDescription = "none", int inputPrice = 0, int inputQuantity = 0); // parameterized
    
    // mutators
    void SetName(string inputName);
    void SetPrice(int inputPrice);
    void SetQuantity(int inputQuantity);
    void SetDescription(string inputDescription);
    
    // accessors
    string GetName() const;
    int GetPrice() const;
    int GetQuantity() const;
    string GetDescription() const;
    
    // print functions
    void PrintItemCost();
    void PrintItemDescription();
    
private:
    string itemName;
    int itemPrice;
    int itemQuantity;
    string itemDescription;
    
};

#endif /* ItemToPurchase_h */
