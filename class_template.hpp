template <typename T>
class Box {
public:
    explicit Box(T value) : value_(value) {}
    T get() const { return value_; }
    void set(T value) { value_ = value; }
private:
    T value_;
};

/*

 Box b(42);      
 Box b2("hello");
 
`"hello"` is a `const char*`, not `std::string`, so `Box b2("hello")` gives you
 `Box<const char*>`,which is probably not what you wanted. 
 You'd write a **deduction guide** to fix this:

 Box(const char*) -> Box<std::string>;

*/
