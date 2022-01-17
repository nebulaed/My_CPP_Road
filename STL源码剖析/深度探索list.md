## 深度探索list

list中迭代器的重载操作符

```c++
//prefix form ++
self& operator++()
{
	node = (link_type)((*node).next);    
}
//postfix form ++
self operator++(int)
{
    self tmp = *this;
    ++*this;
    return tmp;
}
reference operator*() const
{
    return (*node).data;
}
pointer operator->() const
{
    return &(operator*());
}
```

G4.9中的迭代器相比G2.9中的迭代器减少了传进的参数：

```c++
//G2.9
template<class T, class Alloc = alloc>
class list{
public:
    typedef __list_iterator<T, T&, T*> iterator;
};
//G4.9
template<typename _Tp, typename _Alloc = std::allocator<_Tp>>
class list: protected _List_base<_Tp, _Alloc>
{
    public: typedef _List_iterator<_Tp> iterator;
};
```

list实际上是环状双向链表，其中end指向的是一个list自带的节点`_List_node_base<_Tp>`，不可访问。list上有数据的节点是继承自`_List_node_base<_Tp>`的`_List_node<_Tp>`。

迭代器的traits用来分离class iterators和non-class iterators。

这个traits机器必须有能力分辨它所获得的iterator是(1) class iterator T或是(2) native pointer to T。

分离利用的是偏特化，范围的偏特化，如果传入的是native pointer to const T，那用

```c++
template <class T>
struct iterator_traits<T*>
     typedef T value_type;
};
template <class T>
struct iterator_traits<const T*>
    typedef T value_type;	//注意是T而不是const T
};
```

如果传入的是class iterators：

```c++
template <class T>
struct iteratro_traits{
    typedef typename I::value_type value_type;	//直接访问该class中的自带变量v
};
```

