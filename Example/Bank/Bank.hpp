class BankAccount
{
    public:
    BankAccount(float amount);
    void Withdraw(float cash);
    void Deposit(float cash);
    void ShowBalance();
    
    private:
        float total;
};
