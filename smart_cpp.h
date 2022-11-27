// 自定义智能指针
template<class T>
class SmartPtr {
public:
    explicit SmartPtr(T* ptr);
    virtual ~SmartPtr();
    SmartPtr(SmartPtr&& p) noexcept;
    SmartPtr& operator=(SmartPtr&& p) noexcept;
    SmartPtr(const SmartPtr& p) = delete;               // 禁用拷贝构造函数
    SmartPtr& operator=(const SmartPtr& p) = delete;    // 禁用赋值

    T& operator*() const;
    T* operator->() const;

    T* get() const;
    T* release() const;
    void reset(T* q = nullptr);
    void swap(SmartPtr& p);
private:
    T* ptr;
};
