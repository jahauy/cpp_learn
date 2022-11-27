template<class T>
SmartPtr<T>::SmartPtr(T* ptr): ptr{ptr}
{}

template<class T>
SmartPtr<T>::~SmartPtr()
{
    if (ptr) {
        delete ptr;
        ptr = nullptr;
    }
}

template<class T>
SmartPtr<T>::SmartPtr(SmartPtr&& p) noexcept :ptr{p.ptr}
{
    p.ptr = nullptr;
}

template<class T>
T& SmartPtr<T>::operator*() const
{
    return *ptr;
}

template<class T>
T* SmartPtr<T>::operator->() const
{
    return ptr;
}

template<class T>
T* SmartPtr<T>::get() const
{
    return ptr;
}

template<class T>
T* SmartPtr<T>::release() const
{
    return std::exchange(ptr, nullptr);
}

template<class T>
void SmartPtr<T>::reset(T* q)
{
    if (q != ptr) {
        if (ptr) delete ptr;
        ptr = q;
    }
}

template<class T>
void SmartPtr<T>::swap(SmartPtr& p)
{
    std::swap(ptr, p.ptr);
}

template<class T>
SmartPtr<T>& SmartPtr<T>::operator=(SmartPtr&& p) noexcept
{
    swap(p);
    return *this;
}
