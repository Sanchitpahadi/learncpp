
#include<iostream>
#include "Bank.hpp"

int main()
{
    BankAccount b(10000.4);
    int n = 9;
    float amt = 0;
    std::cout<<"1. Deposit"<<std::endl;
    std::cout<<"2. Withdraw"<<std::endl;
    std::cout<<"3. Show balance"<<std::endl;
    std::cout<<"4. Exit"<<std::endl;
  
    while(n != 0)
    {
        std::cout<<"What do you want to do"<<std::endl;
        std::cin>>n;

        switch (n)
        {
        case 1:
            std::cout<<"How much do u want to Deposit"<<std::endl;
            std::cin >> amt;
            b.Deposit(amt);
            break;
        case 2:
            std::cout<<"How much do u want to withdraw"<<std::endl;
            std::cin >> amt;
            b.Withdraw(amt);
        break;
        case 3:
             b.ShowBalance();
        break;
        
        
        default:
         std::cout<<"What do you want to do"<<std::endl;
            break;
        }
    }
    return 0;
}