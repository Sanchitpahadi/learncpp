#include<iostream>


class Shape 
{

    public:

    virtual void Draw() = 0;
};

class Circle : public Shape 
{

    void Draw( ) 
    {
        std::cout << "drawing Circle\n";
    }
};

class Square : public Shape 
{

    void Draw( ) 
    {
        std::cout << "drawing Square\n";
    }
};
int main()
{

    Shape * s = new Square;
    Shape * c = new Circle;
    s->Draw();  
    c->Draw();      

    return 0;
}