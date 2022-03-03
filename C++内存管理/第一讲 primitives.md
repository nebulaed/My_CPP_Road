

<img src="D:\Data\OneDrive\C++\My_CPP_Road\C++内存管理\image-20220216124238250.png" alt="image-20220216124238250" style="zoom:67%;" />

本课程主要讨论CRT及CRT之上的内容。

## C++ memory primitives

| 分配                       | 释放                         | 类属      | 可否重载                 |
| :------------------------- | :--------------------------- | :-------- | :----------------------- |
| `malloc()`                 | `free()`                     | C函数     | 不可                     |
| `new`                      | `delete`                     | C++表达式 | 不可                     |
| `::operator new()`         | `::operator delete()`        | C++函数   | 可                       |
| `allocator<T>::allocate()` | `allocator<T>::deallocate()` | C++标准库 | 可自由设计并搭配任何容器 |

用法示例：

```cpp
//malloc-free
void *p1 = malloc(512);	//512 bytes
free(p1);
//new-delete
complex<int>* p2 = new complex<int>;	//one object
delete p2;
//::operator new-::operator delete
void *p3 = ::operator new(512);	//512 bytes
::operator delete(p3);
//allocator<int>().allocate()-allocator<int>().deallocate()
#ifdef _MSC_VER
	int *p4 = allocator<int>().allocate(3, (int*)0);	//分配3个ints
	allocator<int>().deallocate(p4, 3);
#endif
#ifdef __BORLANDC__
	int *p4 = allocator<int>().allocate(5);	//分配5个ints
	allocator<int>().deallocate(p4, 5);
#endif
//GCC2.9
#ifdef __GNUC__
	void *p4 = alloc::allocate(512);	//分配512bytes
	alloc::deallocate(p4, 512);
#endif
//GCC4.9
#ifdef __GNUC__
	void *p4 = allocator<int>().allocate(7);	//分配7个ints
	allocator<int>().deallocate((int*)p4, 7);
	
	void *p5 = __gnu_cxx::__pool_alloc<int>().allocate(9);	//分配9个ints
	__gnu_cxx::__pool_alloc<int>().deallocate((int*)p5, 9);
```

## new expression

new操作符本质上是先调用`operator new`(内部调用了`malloc`)执行内存分配，然后执行该类的构造函数(若有)。 

```cpp
Complex *pc = new Complex(1,2);
```

编译器转为:

```cpp
Complex *pc;
try{
    void *mem = ::operator new(sizeof(Complex));
    pc = static_cast<Complex*>(mem);
    pc->Complex::Complex(1,2);
    //注意：只有编译器才能像上面那样直接呼叫构造函数
}
catch(std::bad_alloc){
    //若allocation失败就不执行构造函数
}
```

## delete expression

```cpp
Complex* pc = new Complex(1,2);
...
delete pc;
```

编译器转为

```cpp
pc->~Complex();
operator delete(pc);
```

即先执行析构函数，然后调用`operator delete`(内含`free`)释放内存

## Ctor(构造函数) & Dtor(析构函数)直接调用

Ctor不能直接通过指针调用，Dtor可以直接通过指针调用。

## array new, array delete

```cpp
Complex* pca = new Complex[3];
//唤起三次ctor
//无法借由参数给予初值
...
delete[] pca;	//唤起3次dtor
```

此处若将`delete[]`误写为`delete`，会导致只唤起一次dtor。这对class without ptr member可能没影响，但对class with pointer member通常有影响。

因为new底层调用了malloc，malloc在为任何东西(包括数组)分配内存时，会给一块cookie记录分配内存的长度，delete底层调用的free会根据cookie里记录的长度去释放内存。

测试用例：

```cpp
class A{
public:
    int id;
	A() : id(0) { cout<< "default ctor.this=" << this << "id="<< id << endl; }
    A(int i) : id(i) { cout << "ctor.this=" << this << "id=" << id << endl; }
    ~A() { cout << "dtor.this=" << this << "id=" << id << endl; }
};
```

尝试使用array new和array delete：

```cpp
A* buf = new A[size];	//default ctor 3次，[0]先于[1]先于[2]
A* tmp = buf;
cout << "buf=" << buf << " tmp=" << tmp << endl;
for (int i = 0; i < size; ++i){
    new(tmp++)A(i);	//ctor 3次
}
cout << "buf=" << buf << " tmp=" << tmp << endl;
delete[] buf;	//dtor 3次，次序逆反，[2]先于[1]先于[0]
```

`new(tmp++)A(i)`是placement new。

<img src="D:\Data\OneDrive\C++\My_CPP_Road\C++内存管理\image-20220217205717259.png" alt="image-20220217205717259" style="zoom:75%;" />

黄色的是在debug mode下才会出现的，上下分别是32个字节和4个字节，上下两个61h代表两个cookie，里面放着整块的大小，61h表示记录这一整块的大小为60h。

为什么是60h?

因为这一整块的大小需要与16对齐，整块的长度为(32+4)+(4(int)\*10)+4\*2=84->96，因此pad为12 bytes，96转换为16进制就是60h。

对于int这种内置类型，`int* pi = new int[10]`后用了`delete pi`，不会有影响，因为int没有析构函数，不需要通过`delete[]`去多次调用析构函数。

## placement new

- placement new允许我们将object建构于已分配的内存中
-  没有placement delete，因为placement new根本没分配内存。

```cpp
#include<new>
char *buf = new char[sizeof(Complex)*3];
Complex* pc = new(buf)Complex(1,2);
...
delete[] buf;
```

placement new就等同于调用构造函数。

## C++应用程序分配内存的途径

<img src="D:\Data\OneDrive\C++\My_CPP_Road\C++内存管理\image-20220217223853748.png" alt="image-20220217223853748" style="zoom:50%;" />

<img src="D:\Data\OneDrive\C++\My_CPP_Road\C++内存管理\image-20220217224338129.png" alt="image-20220217224338129" style="zoom:50%;" />

## 重载::operator new / ::operator delete

```cpp
void* myAlloc(size_t size) { return malloc(size); }
void* myFree(void* ptr) { return free(ptr); }
inline void* operator new(size_t size){
    cout << "jjhou global new() \n";
    return myAlloc(size);
}
inline void* operator new[](size_t size){
    cout << "jjhou global new[]() \n";
    return myAlloc(size);
}
inline void* operator delete(void* ptr){
    cout << "jjhou global delete() \n";
    myFree(ptr);
}
inline void* operator new(void* ptr){
    cout << "jjhou global delete[]() \n";
    myFree(ptr);
}
```

## 重载作为member func的operator new / operator delete

```cpp
class Foo{
public:
    //以下static即使没写，C++编译器也会自动加上
    static void* operator new(size_t);
    static void* operator new[](size_t);
    static void* operator delete(void*, size_t);	//这个size_t可以不要
    static void* operator delete[](void*, size_t);	//这个size_t可以不要
};
```

> 注意：
>
> 如果这样使用：
>
> ```cpp
> Foo *p = ::new Foo(7);
> ::delete p;
> Foo *pArray = ::new Foo[5];
> ::delete[] pArrayl
> ```
>
> 也就是使用`::new`和`::delete`，调用全局作用域操作符::，会绕过所有重载的成员函数，强制使用全局版本的operator new / operatow delete。

## 重载placement new() / delete

可以重载class member operator new()，写出多个版本，前提是每一版本的声明都必须有独特的参数列，其中第一参数必须是size_t，其余参数以new指定的placement arguments为初值。出现于new(...)小括号内就似乎所谓placement arguments。

```cpp
Foo *pf = new(300, 'c')Foo;
```

可以重载class member operator delete()，写出多个版本。但它们绝不会被delete调用。只有当new所调用的ctor抛出异常，才会调用这些重载版的operator delete()。它只能这样被调用来归还未能完全创建成功的object所占用的内存。

```cpp
class Foo{
public:
    Foo() { cout << "Foo::Foo()" << endl; }
    Foo(int) {cout << "Foo::Foo(int)" << endl; throw Bad(); }//Bad()空类
    //(1)一般operator new()的重载
    void* operator new(size_t size){
        return malloc(size);
    }
    //(2)这个就是标准库已提供的placement new()的重载形式
    void* operator new(size_t size, void* start){
        return start;
    }
    //(3)这个才是崭新的placement new
    void* operator new(size_t size, long extra){
        return malloc(size+extra);
    }
    //(4)这又是一个placement new
    void* operator new(size_t size, long extra, char init){
        return malloc(size+extra);
    }
    //(5)这是一个故意写错第一参数类型的placement new，会报错!!
    void* operator new(long extra, char init){
        return malloc(extra);
    }
    //以下是搭配上述placement new的各个placement delete。
    //当ctor抛出异常，这儿对应的operator(placement) delete就会被调用。
    //以下是搭配上述placement new的各个placement delete
    //当ctor抛出异常，对应的operator (placement) delete就会被调用
    //其用途是释放对应的placement new分配所得的内存。
    //(1)这个是一般的operator delete()的重载
    void operator delete(void*, size_t)
    {
        cout << "operator delete(void*, size_t)" << endl;
    }
    //(2)这是对应上页的(2)
    void operator delete(void*, void*)
    {
        cout << "operator delete(void*, void*)" << endl;
    }
    //(3)这是对应上页的(3)
    void operator delete(void*, long)
    {
        cout << "operator delete(void*,long)" << endl;
    }
    //(4)这是对应上页的(4)
    void operator delete(void*, long, char)
    {
        cout << "operator delete(void*,long,char)" << endl;
    }
private:
	int m_i;
};
```

即使operator delete()未能一一对应于operator new()，也不会出现任何报错，这表示放弃处理ctor抛出的异常。

标准库中所含的`basic_string`也采用了重载`operator new()`，多malloc了extra大小的内存，用于放置引用计数等内容。

### 改造思路：

1. 降低malloc的调用次数，提升速度，通过member func的operator new和operator delete一次malloc大块的内存，然后切割一些小块分配给object。
2. 降低cookie的用量，降低空间浪费率。

## per-class allocator, 1

```cpp
#include<cstddef>
#include<iostream>
using namespace std;

class Screen{
public:
    Screen(int x) : i(x) {}
    int get() { return i; }
    
    static void* operator new(size_t);
    static void* operator delete(void*, size_t);
    //...
private:
    //为了去除cookie增加了next指针，增加了空间消耗
    Screen* next;
    static Screen* freeStore;
    static const int screenChunk;
private:
    int i;
};
//以下必须在.cpp中实现，私有static成员变量的初始化要用定义的方式实现
Screen* Screen::freeStore = 0;
const int Screen::screenChunk = 24;

void* Screen::operator new(size_t size)
{
    Screen *p;
    if(!freeStore){
        //linked list是空的，所以申请一大块，一次申请24倍大小的内存
        size_t chunk = screenChunk * size;
        freeStore = p = reinterpret_cast<Screen*>(new char[chunk]);
        //将一大块分割成片，当做linked list串接起来
        for(; p != &freeStore[screenChunk - 1]; ++p){
            p->next = p + 1;
        }
        p->next = 0;
    }
    p = freeStore;
    freeStore = freeStore->next;
    return p;
}

void* Screen::operator delete(void *p, size_t size)
{
    //将delete object插回free list前端
    (static_cast<Screen*>(p))->next = freeStore;
    freeStore = static_cast<Screen*>p;
}
```

使用了重载的member operator new/delete的结果，每个object间隔8，而不重载每个object间隔16，每个object包含前后两个cookie共8个字节。

## per-class allocator, 2

```cpp
class Airplane{
private:
    struct AirplaneRep{
        unsigned long miles;
        char type;
    };
private:
	union { AirplaneRep rep;	//此栏针对使用中的object
          	Airplane* next;		//此栏针对free list上的object
          };
public:
    unsigned long getMiles() { return rep.miles; }
    char getType() { return rep.type; }
    void set(unsigned long m, char t){
        rep.miles = m;
        rep.type = t;
    }
public:
    static void* operator new(size_t);
    static void* operator delete(void* deadObject, size_t size);
private:
    static const int BLOCK_SIZE;
    static Airplane* headOfFreeList;
};
Airplane* Airplane::headOfFreeList;
const int Airplane::BLOCK_SIZE = 512;

void* Airplane::operator new(size_t size)
{
    //如果大小有误，转交给::operator new(当继承发生时可能有这种情况)
    if(size != sizeof(Airplane)) return ::operator new(size);
    
    Airplane* p = headOfFreeList;
    if(p){	//若p有效，就把list头部下移一个元素
        headOfFreeList = p->next;
    }
    else{
        //freelist已空，申请一大块
        Airplane* newBlock = static_cast<Airplane*>(::operator new(BLOCK_SIZE * sizeof(Airplane)));
        //将小块串成一个free list
        for (int i = 1; i < BLOCK_SIZE-1; ++i){
            newBlock[i].next = &newBlock[i+1];
        }
        newBlock[BLOCK_SIZE-1].next = 0;
        p = newBlock;
        headOfFreeList = &newBlock[1];
    }
    return p;
}
```

这两个版本都没有new对应的delete，没有把空间还给操作系统。所有经过member operator delete的节点都会插入到头部。

## static allocator

单独定义一个class allocator，内有成员函数allocate，deallocate。其他需要自定义空间分配的类只需要在类中声明`static allocator myAlloc`，然后在`operator new()`和`operator delete() `中调用`myAlloc.allocate()`和`myAlloc.deallocate()`，并在类外定义`allocator class::myAlloc`。

这样就不必为不同的classes重写一遍几乎相同的member operator new和member operator delete。

可以用macro宏定义将以上部分宏定义，然后每次在类内只需要写上这段macro即可:

```cpp
#define DECLARE_POOL_ALLOC() \
public: \
	void* operator new(size_t size) { return myAlloc.allocate(size); } \
	void* operator delete(void* p) { myAlloc.deallocate(p, 0); } \
protected: \
	static allocator myAlloc;
#define IMPLEMENT_POOL_ALLOC(class_name) \
allocator class_name::myAlloc;

class Foo{
    DECLARE_POOL_ALLOC()
...
};
IMPLEMENT_POOL_ALLOC(Foo)
```

## new handler

当operator new没能力分配出所申请的内存，会抛一个std::bad_alloc异常。

抛出异常之前会先(不只一次)调用一个可由我们指定的handler，以下是new handler的形式和设定方法：

```cpp
typedef void (*new_handler)();
new_handler set_new_handler(new_handler p) throw();
```

设计良好的new handler只有两个选择：

- 让更多内存可用
- 调用abort()或exit()

## =default, =delete

```cpp
class Foo{
public:
    Foo() = default;
    Foo(const Foo&) = delete;
    Foo& operator=(const Foo&) = delete;
    ~Foo() = default;
};
```

构造函数和析构函数有默认版本，`=default`表示用编译器默认给的那个版本，`=delete`表示不用该版本。`operator new`(`new[]`)和`operator delete`(`delete[]`)也可以用这两个关键字。

