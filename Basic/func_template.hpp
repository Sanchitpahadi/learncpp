#pragma once

template <typename T>

T Max(T a, T b) 
{
    return (a > b) ? a : b;
}

template <typename T>
T zero(T a) 
{ 
    return T{a}; 
}

template <typename T, typename U>
auto add(T a, U b)
{
    return a + b;
}

// How the template pass by value and pass by refrences
template <typename T>
void byValue(T x) { /* copies x */ }

template <typename T>
void byRef(T& x) { /* no copy, can modify caller's variable */ }

template <typename T>
void byConstRef(const T& x) { /* no copy, read-only */ }

