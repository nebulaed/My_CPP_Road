# 2 STL初识

## 2.1 STL的诞生

- 长久以来，软件界希望建立一种可重复利用的东西
- C++的**面向对象**和**泛型编程**思想，目的就是**复用性的提升**
- 大多情况下，数据结构和算法都未能有一套标准，导致被迫从事大量重复工作
- 为了建立数据结构和算法的一套标准，诞生了**STL**

## 2.2 STL基本概念

- STL(Standard Template Library)：标准模板库
- STL从广义上分为：容器(container)，算法(alogorithm)，迭代器(iterator)
- **容器**和**算法**之间通过**迭代器**进行无缝衔接
- STL几乎所有的代码都采用了模板类或者模板函数

## 2.3 STL六大组件

STL大体分为六大组件，分别是：容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器

1. 容器：各种数据结构，如vector、list、deque、set、map等，用来存放数据
2. 算法：各种常用的算法，如sort、find、copy、for_each等
3. 迭代器：扮演了容器和算法之间的胶合剂
4. 仿函数：行为类似函数，可作为算法的某种策略
5. 适配器：一种用来修饰容器或者仿函数或者迭代器接口的东西
6. 空间配置器：负责空间的配置和管理

## 2.4 STL中容器、算法、迭代器

容器：

STL容器就是将运用最广泛的一些数据结构实现出来

常用的数据结构：数组、链表、树、栈、队列、集合、映射表等

这些容器分为**序列式容器**和**关联式容器**两种：

- 序列式容器：强调值的排序，序列式容器中每个元素均有固定的位置
- 关联式容器：二叉树结构，各元素之间没有严格的物理上的顺序关系

算法：

有限的步骤，解决逻辑或数学上的问题，就叫做算法

算法分为 质变算法 和 非质变算法。

- 质变算法：指运算过程中会更改区间中的元素的内容。例如拷贝、替换、删除等

- 非质变算法：指运算过程中不会更改区间中的元素的内容。例如查找、计数、遍历、寻找极值等

迭代器：

容器和算法之间粘合剂

提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又需暴露该容器的内部表示方式。

每个容器都有专属的迭代器

迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针



迭代器种类：

| 种类           | 功能                                                     | 支持运算                                |
| -------------- | -------------------------------------------------------- | --------------------------------------- |
| 输入迭代器     | 对数据的只读访问                                         | 只读，支持++、==、!=                    |
| 输出迭代器     | 对数据的只写访问                                         | 只写，支持++                            |
| 前向迭代器     | 读写操作，并能向前推进迭代器                             | 读写，支持++、==、!=                    |
| 双向迭代器     | 读写操作，并能向前和向后操作                             | 读写，支持++、--                        |
| 随机访问迭代器 | 读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器 | 读写，支持++、--、[n]、-n、<、<=、>、>= |

常用的容器中迭代器种类为双向迭代器，和随机访问迭代器

## 2.5 容器算法迭代器初识

STL最常用的容器为Vector，可以理解为数组，下面我们将学习如何向这个容器中插入数组，并遍历这个容器

### 2.5.1 Vector存放内置数据类型

容器：`vector`

算法：`for_each`

迭代器：`vector<int>::iterator`

### 2.5.2 Vector存放自定义数据类型

学习目标：vector中存放自定义数据类型，并打印输出

### 2.5.3 Vector容器嵌套容器

学习目标：容器中嵌套容器，我们将所有数据进行遍历输出

## 3.1 string 容器

### 3.1.1 string基本概念

**本质：**

- string 是C++风格的字符串，而string本质是一个类

string和char*区别

- char*是一个指针
- string 是一个类，类内部封装了char*，管理这个字符串，是一个char\*型的容器

特点：

string类内部封装了很多成员方法

例如：查找find、拷贝copy、删除delete、替换replace、插入insert

string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

### 3.1.2 string构造函数

构造函数原型：

- `string();` // 创建一个空的字符串 例如：string str;

  `string(const char *s);` // 使用字符串s初始化

- `string(const string& str);` // 使用一个string对象初始化另一个string对象

- `string(int n, char c);` // 使用n个字符c初始化

总结：string的多种构造方式没有可比性，灵活使用即可

### 3.1.3 string赋值操作

功能描述：

- 给string字符串进行赋值

赋值的函数原型：

- `string& operator=(const char* s);` // char*类型字符串，赋值给当前的字符串
- `string& operator= (const string &s);` // 把字符串s赋给当前的字符串
- `string& operator= (char c);` // 字符赋值给当前的字符串
- `string& assign(const char *s);` // 把字符串s赋给当前的字符串
- `string& assign(const char *s, int n);` // 把字符串s的前n个字符赋给当前的字符串
- `string& assign(const string &s);` // 把字符串s赋给当前字符串
- `string& assign(int n, char c);` // 用n个字符c赋给当前字符串

总结：string的赋值方式很多，`operator=`这种方式是比较实用的

### 3.1.4 string字符串拼接

功能描述：

- 实现在字符串末尾拼接字符串

函数原型：

- `string& operator+=(const char* str);` // 重载+=操作符
- `string& operator+=(const char c);` // 重载+=操作符
- `string& operator+=(const string& str);` // 重载+=操作符
- `string& append(const char *s);` // 把字符串s连接到当前字符串结尾
- `string& append(const char *s, int n);` // 把字符串s的前n个字符连接到当前字符串结尾
- `string& append(const string &s);` // 同operator+=(const string& str)
- `string& append(const string &s, int pos, int n);` // 字符串s从pos开始的n个字符连接到字符串结尾 

总结：字符串拼接的重载版本很多，初学阶段记住几种即可。

### 3.1.5 string查找和替换

功能描述：

- 查找：查找指定字符串是否存在
- 替换：在指定的位置替换字符串

函数原型：

- `int find(const string& str, int pos = 0) const;` // 查找str第一次出现位置，从pos开始查找
- `int find(const char* s, int pos = 0) const;` // 查找s第一次出现位置，从pos开始查找
- `int find(const char* s, int pos, int n) const;` // 从pos位置查找s的前n个字符第一次位置
- `int find(const char c, int pos = 0) const;` // 查找字符c第一次出现位置
- `int rfind(const string& str, int pos = npos) const;` // 查找str最后一次位置，从pos开始查找
- `int rfind(const char* s, int pos = npos) const;` // 查找s最后一次出现位置，从pos开始查找
- `int rfind(const char* s, int pos， int n) const;` // 从pos查找s的前n个字符最后一次位置
- `int rfind(const char c, int pos = 0) const;` // 查找字符c最后一次出现位置
- `string& replace(int pos, int n, const string& str)` // 替换从pos开始的n个字符为字符串str
- `string& replace(int pos, int n, const char* s);` // 替换从pos开始的n个字符为字符串s

总结：

- find查找是从左往右，rfind从右往左
- find找到字符串后返回查找的第一个字符位置，找不到返回-1
- replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串

### 3.1.6 string字符串比较

功能描述：

- 字符串之间的比较

比较方式：

- 字符串比较是按字符的ASCII码进行对比

= 返回 0

\> 返回 1

< 返回 -1

函数原型：

- `int compare(const string &s) const;` // 与字符串s比较
- `int compare(const char *s) const;` // 与字符串s比较

总结：字符串对比主要是用于比较两个字符串是否相等，判断谁大谁小的意义并不是很大

### 3.1.7 string 字符存取

string中单个字符存取方式有两种

- `char& operator[] (int n);` // 通过[]方式取字符
- `char& at(int n);` // 通过at方法获取字符

总结：string字符串中单个字符存取有两种方式，利用[]或at

### 3.1.8 string插入和删除

功能描述：

- 对string字符串进行插入和删除字符操作

函数原型：

- `string& insert(int pos, const char* s);` //插入字符串
- `string& insert(int pos, const string& str);` //插入字符串
- `string& insert(int pos, int n, char c);` // 在指定位置插入n个字符c
- `string& erase(int pos, int n = npos);` // 删除从pos开始的n个字符

总结：插入和删除的起始下标都是从0开始

### 3.1.9 string子串

功能描述：

- 从字符串中获取想要的子串

函数原型：

- `string substr(int pos = 0, int n = npos) const;` // 返回由pos开始的n个字符组成的字符串

总结：灵活地运用求子串功能，可以在实际开发中获取有效的信息

## 3.2 vector容器

### 3.2.1 vector基本概念

功能：

- vector数据结构和数组非常相似，也称为**单端数组**

vector与普通数组区别：

- 不同之处在于数组是静态空间，而vector可以**动态扩展**

动态扩展：

- 并不是在原空间后续接新空间，而是找更大的内存空间，然后将原数据拷贝到新空间，然后释放原空间



- vector容器的迭代器是支持随机访问的迭代器

### 3.2.2 vector构造函数

功能描述：

- 创建vector容器

函数原型：

- `vector<T> v;` // 采用模板实现类实现，默认构造函数
- `vector(v.begin(),v.end());` // 将v[begin(), end()]区间中的元素拷贝给本身
- `vector(n,elem);` // 构造函数将n个elem拷贝给本身
- `vector(const vector &vec);` // 拷贝构造函数

总结：vector的多种构造方式没有可比性，灵活使用即可

### 3.2.3 vector赋值操作

功能描述：

- 给vector容器进行赋值

函数原型：

- `vector& operator=(const vector &vec);` // 重载等号操作符
- `assign(beg, end);` // 将[beg,end)区间中的数据拷贝赋值给本身
- `assign(n,elem);` // 将n个elem拷贝赋值给本身

总结：vector赋值方式比较简单，使用operator=，或者assign都可以

### 3.2.4 vector容量和大小

功能描述：

- 对vector容器的容量和大小操作

函数原型：

- `empty();` // 判断容器是否为空

- `capacity();` // 容器的容量

- `size();` // 返回容器中元素的个数

- `resize(int num);` // 重新指定容器的长度为num，若容器变长，则以默认值填充新位置。

  ​									// 如果容器变短，则末尾超出容器长度的元素被删除

- `resize(int num, elem);` // 重新指定容器的长度为num，若容器变长，则以elem值填充新位置

  ​												// 如果容器变短，则末尾超出容器长度的元素被删除

总结：

- 判断是否为空 -- empty
- 返回元素个数 -- size
- 返回容器数量 -- capacity
- 重新指定大小 -- resize

### 3.2.5 vector插入和删除

功能描述：

- 对vector容器进行插入、删除操作

函数原型：

- `push_back(ele);` // 尾部插入元素ele
- `pop_back();` // 删除最后一个元素
- ` insert(const_iterator pos, ele);` // 迭代器指向位置pos插入元素ele
- `insert(const_iterator pos, int count, ele);` // 迭代器指向位置pos插入count个元素ele
- `erase(const_iterator pos);` // 删除迭代器指向的元素
- `erase(const_iterator start, const_iterator end);` // 删除迭代器从start到end之间的元素
- `clear();` // 删除容器中所有元素

总结：

* 判断是否为空  --- empty
* 返回元素个数  --- size
* 返回容器容量  --- capacity
* 重新指定大小  ---  resize