#include<iostream>


class Shape 
{

    public:

    virtual void Draw()
    {
        std::cout << "drawing shapes";
    }
};

class Circle : public Shape 
{

    void Draw( ) override
    {
        std::cout << "drawing Circle";
    }
};

class Square : public Shape 
{

    void Draw( ) override
    {
        std::cout << "drawing Circle";
    }
};
int main()
{

    Shape * s = new Square;
    s->Draw();    

    return 0;
}