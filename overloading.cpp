#include <iostream>

class Number 
{
    private:

    public:
    int value;

    Number(int n) : value(n) {}

    Number operator+(const Number& other)
    {
        return  Number(value + other.value);
    }

    void print()
    {
        std::cout << value << std :: endl;
    }

    friend Number operator-(const Number& a, const Number&b);

};

Number operator-(const Number& a, const Number& b)
{
    return Number(a.value - b.value);
}
int main ()
{
    Number a(10);
    Number b(20);
    a.print();
    a = a + b;
    a.print();
    Number c = a - b;
    c.print();


    return 0;
}