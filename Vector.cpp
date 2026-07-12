
#include<iostream>
#include<vector>
#include <iterator>

/*

std::vector<int> v;                    // default: empty, capacity 0
std::vector<int> v2(5);                 // 5 elements, value-initialized (0)
std::vector<int> v3(5, 42);             // 5 elements, all 42
std::vector<int> v4{1,2,3};             // initializer-list: {1,2,3}
std::vector<int> v5(v4);                // copy
std::vector<int> v6(std::move(v4));     // move (v4 now empty/valid-but-unspecified)
std::vector<int> v7(v4.begin(), v4.end()); // range constructor

// Element access
v.at(2);          // bounds-checked, throws std::out_of_range
v[2];              // unchecked, UB if out of bounds -> fastest, use in hot paths after validation
v.front(); v.back();
v.data();          // T* to underlying contiguous array -> feed to C APIs, GPU buffers, etc.

// Capacity
v.size(); v.empty(); v.capacity();
v.reserve(100);    // ensure capacity >= 100, no-op if already sufficient, NEVER shrinks
v.shrink_to_fit(); // non-binding request to release unused capacity
v.resize(10);      // grow/shrink to exactly 10 elements (new elements value-initialized)
v.resize(10, val); // grow/shrink, new elements = val

// Modifiers
v.push_back(x);          // copy/move-construct at end, may reallocate
v.emplace_back(args...); // construct IN PLACE at end using args - avoids a temporary + move
v.pop_back();             // remove last, O(1), no bounds check (UB if empty)
v.insert(pos, x);         // insert before pos, O(n) - shifts everything after pos
v.emplace(pos, args...);  // in-place insert before pos
v.erase(pos);             // O(n) - shifts everything after pos left
v.erase(first, last);     // erase range
v.clear();                 // destroy all elements, capacity UNCHANGED
v.swap(other);             // O(1) - swaps internal pointers, no element copies

**NOTE**

For cheap types (`int`, small structs) the difference is negligible. For expensive-to-move types, or
types with no move constructor, `emplace_back` avoids real work. Rule of thumb: prefer `emplace_back`
by default when constructing new elements from constructor args; use `push_back` when you already have
an object (especially if passing by `const&` avoids an unnecessary move anyway).
*/

int main()
{

    std::vector<int> v;

    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(14);
    v.push_back(14);
    v.push_back(14);
    v.push_back(14);


    for(auto it = v.begin();it!=v.end();++it)
    {
        std::cout << *it << "\n";
    }

    std::cout << v.size() << "\n"; // how many vectors are there

    for(int i = 0; i<v.size();i++)
    {
        std::cout << i << "."<< v.at(i) << "\n";

    }
    
    std::cout << v.front() << "\n";
    std::cout << v.back() << "\n";
    std::cout << v.data() << "\n";

    std::cout << "Before reserving capacity to 100 "<<v.capacity() << "\n";
    v.reserve(100);
    std::cout << "after reserving capacity to 100 "<<v.capacity() << "\n";
    v.shrink_to_fit();
    std::cout <<"after shrinking to fit exact number of vectors"<< v.capacity() << "\n";

    return 0;
}