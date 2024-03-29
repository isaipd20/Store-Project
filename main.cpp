#include <string>
#include <iostream>
#include <vector>
#include "vendor.h"

struct cartValues {
    std::string item;
    int quantity;
};

std::vector<cartValues> cart;

void addItems(cartValues x) {
    cart.push_back(x);
}

void removeItems(int num) {
    cart.erase(cart.begin() + num);
}

void showItems() {
    
    for (unsigned int i = 0; i < cart.size(); i++) {
        std::cout << "item[" << i << "]: " << cart[i].item << ", Quantity: " << cart[i].quantity << std::endl;
    }

}

void changeItem(int num) {
    cartValues x;

    std::cin.ignore();
    std::cout << "What item do you want to add to your cart?" << std::endl;
    std::cout << "water \napples \nwatermelon \nchips \n";
    std::getline(std::cin, x.item);
    std::cout << "Enter quantity: ";
    std::cin >> x.quantity;
    cart[num].item = x.item;
    cart[num].quantity = x.quantity;
}

void checkAvailability(std::string item) {
    std::vector<std::string> itemsList;
    bool x = false;

    itemsList.push_back("water");
    itemsList.push_back("apples");
    itemsList.push_back("watermelon");
    itemsList.push_back("chips");

    for (unsigned int i = 0; i < itemsList.size(); i++) {
        if (itemsList[i] == item) {
            std::cout << "item is available" << std::endl;
            x = true;
        }
    }

    if (x == false) {
        std::cout << "item is not available" << std::endl;
    }
}

void menu(int choise) {
    cartValues Cart;

    switch (choise) {
    case 1:
        std::cin.ignore();
        std::cout << "What item do you want to add to your cart?" << std::endl;
        std::cout << "water \napples \nwatermelon \nchips \n";
        std::getline(std::cin, Cart.item);
        std::cout << "Enter quantity: ";
        std::cin >> Cart.quantity;
        addItems(Cart);
        break;

    case 2:
        int number;

        if (cart.size() >= 1) {
            std::cout << "What item do you want to remove from your cart?" << std::endl;
            showItems();
            std::cin >> number;
            removeItems(number);
        }
        
        else {
            std::cout << "Your Cart is empty. Add items!!" << std::endl;
        }
        break;

    case 3:
        std::cout << "Thanks for shopping!!" << std::endl;
        break;

    case 4:
        int numItem;

        if (cart.size() >= 1) {
            std::cout << "What item do you want to change from your cart?" << std::endl;
            showItems();
            std::cin >> numItem;
            changeItem(numItem);
        }

        else {
            std::cout << "Your Cart is empty. Add items!!" << std::endl;
        }
        break;

    case 5:

        if (cart.size() >= 1) {
            showItems();
        }

        else {
            std::cout << "Your Cart is empty. Add items!!" << std::endl;
        }
        break;

    case 6:
        std::string item;

        std::cout << "What item do you want to check for availability?" << std::endl;
        std::cin >> item;

        checkAvailability(item);
        break;
    }
}

//Needs modification
int main()
{
    int choise = 0;

    while (choise != 3) {
        std::cout << "Welcome to the store. Options available: " << std::endl;
        std::cout << " 1: add item to cart \n 2: remove item from cart \n 3: quit \n 4: change item \n 5: show items \n 6: check availability \n";
        std::cin >> choise;
        menu(choise);
    }
    
    return 0;
}
