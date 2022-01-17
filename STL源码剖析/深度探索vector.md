## 深度探索vector

vector中只包含三根指针：start，finish，end_of_storage，分别指向开头，size结尾，capacity结尾。 

对于G2.9，`vector<T>::iterator`只是一个简单的non-class _Tp*。

对于G4.9，`vector<T>::iterator`是一个class iterator。

## 深度探索array

```c++
int a[100];	// OK!
int[100] a;	// Error!
typedef int T[100];
T c;		
```

