//
// Created by DELL on 10/31/2020.
//

#ifndef DATASTRUCTURESANDALGOS_ALIZALAB3Q3_H
#define DATASTRUCTURESANDALGOS_ALIZALAB3Q3_H

#endif //DATASTRUCTURESANDALGOS_ALIZALAB3Q3_H
#include <iostream>
using namespace std;




class CashRegister{
private:
    int cashOnHand;
public:

    CashRegister(){
        cashOnHand=500;

    }
    CashRegister(int cash){
        cashOnHand=cash;
    }
    int getCurrentBalance(){
        return cashOnHand;
    }
    void acceptAmount(int money){
        cashOnHand+=money;
    }

};
class DispenserType{
private:
    int numberOfItems;
    int cost;
public:

    DispenserType(int cost, int numofitems){
        cost=cost;
        numberOfItems=numofitems;
    }
    int getNoOfItems(){
        return numberOfItems;
    }
    int getCost(){
        return cost;
    }
    void makeScale(){
        numberOfItems=numberOfItems-1;
    }
};
void showSelection(){
    cout<<"candy shop" <<endl;
    cout<<"make choice" "\n 1. Gums \n2. Candy \n3. Chips \n4.Cookies \n5. QUIT"
        <<endl;
    cout<<"enter your choice :";

}
void sellProduct(DispenserType item, CashRegister counter){
    int money;
    std::cout<<"amount of product: "<<item.getCost()<<std::endl;
    cout<<"enter your amount: ";
    std::cin>>money;
    if(money>=item.getCost()){
        if(item.getNoOfItems()>0){
            item.makeScale();
            counter.acceptAmount(item.getCost());
            std::cout<<"item has been given to customer " <<std::endl;
            std::cout<<"amount left of customer : "<<money-item.getCost()<<std::endl;
            return;

        }
        else{
            std::cout << "No more items available." << std::endl;
            return;
        }
    }else{
        cout << "The entered amount is less than the item cost.\n";
        return;
    }




}

int notmain() {
    CashRegister countere;
    DispenserType candy(100, 50);
    DispenserType chips(100, 65);
    DispenserType gum(75, 45);
    DispenserType cookies(50, 85);
    int choice;
    showSelection();
    std::cin >> choice;
    while (choice != 5)
    {
        switch (choice)
        {
            case 1:
                sellProduct(candy,countere);
                break;
            case 2:
                sellProduct(chips, countere);
                break;
            case 3:
                sellProduct(gum, countere);
                break;
            case 4:
                sellProduct(cookies, countere);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid selection." << endl;
        }
        showSelection();
        std::cin >> choice;
    }
    return 0;





}