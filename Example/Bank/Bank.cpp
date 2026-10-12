    #include "Bank.hpp"
    #include<iostream>


    BankAccount::BankAccount(float amount)
    {
        total = amount;
    }
    void BankAccount::Withdraw(float cash)
    {
        if (cash > total)
        {
            std::cout<<"Not Enough Money"<<std::endl;
        }
        else if (0 > cash)
        {
            std::cout<<"i cant gice u money on Negative"<<std::endl;
        }
        else
        {
            total= total - cash;
        }
       
    }
    void BankAccount::Deposit(float cash)
    {        
        if (0 > cash)
        {
            std::cout<<"how can u give me money on negative"<<std::endl;
        }
        else
        {
            total= total + cash;
        }
  
    }
    void BankAccount::ShowBalance()
    {
        std::cout<<"total Balance is " << total << "\n";
    }