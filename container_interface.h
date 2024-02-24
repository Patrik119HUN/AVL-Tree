#pragma once
#include <bits/stdc++.h>
template<typename T>
class IContainer{
public:
    virtual bool empty() const;
    virtual size_t size() const;
    virtual void clear() noexcept;

    virtual void insert(const T& value);
    virtual size_t erase(const T& value);
};