 

## 一个万用的Hash Function

形式1：

```cpp
class Customer{
    ...
};
class CustomerHash
{
public:
	std::size_t operator()(const Customer& c) const{
        return ...
    }    
};
unordered_set<Customer, CustomerHash> custset;
```

形式2：

```cpp
size_t customer_hash_func(const Customer& c){
    return ...
};
unordered_set<Customer, size_t(*)(const Customer&)> custset(20,customer_hash_func);
```

1. 一个简单的办法：将类的所有成员变量的hash值加起来作为这个类的hash值，但这个hash function碰撞概率较大。

2. 更好的办法：调用hash_val函数：

```cpp
class CustomerHash{
public:
    std::size_t operator() (const Customer& c) const{
        return hash_val(c.fname, c.lname, c.no);
    }
};
```

这个hash_val函数可以接受任意个实参，因为hash_val是一个variadic templates(可变数量任意类型参数函数模板)：

```cpp
template<typename... Types>
inline size_t hash_val(const Types&... args){
    size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}
```

3. 以默认的struct hash偏特化形式实现Hash Function

## tuple

![image-20220215162250878](D:\Data\OneDrive\C++\My_CPP_Road\STL源码剖析\image-20220215162250878.png)

上面的tail()中`*this`本来是一个`tuple<Head, Tail...>`型的指针，由于tuple的地址分布是tail在前，head在后，所以指向最尾的位置，将该指针转换为`tuple<Tail...>`型，相当于让这个指针解引用后只包括前面的`"nico"`和`6.3`，把`Head`型的41抛掉。

## type traits

C++11提供了一系列的type traits，不需要自行typedef。

remove_cv的作用是把const和volatile拿掉，通过泛化和特化与typedef结合实现。

## cout

能使用`cout<<`是因为`cout`的类中定义了大量的操作符重载`operator<<`

## moveable元素对容器速度性能的影响

具有moveable元素的vector基本构造函数速度比具有非moveable元素的vector基本构造函数快，移动构造函数比拷贝构造函数快非常多。

除vector外的容器list，deque，set，map，unordered...，有以下性质：

具有moveable元素的list基本构造函数速度比具有非moveable元素的容器基本构造函数速度差不多，移动构造函数比拷贝构造函数快非常多。

但要注意，使用`std::move(container)`必须保证之后不再调用到`container`。 