stack或queue都不允许遍历，也不提供iterator。

stack和queue都可选择list或deque作为底层结构。

```c++
stack<string, list<string>> c;
for (long i = 0; i < 10; ++i){
    snprintf(buf, 10, "%d", rand());
    c.push(string(buf));
}
queue<string, list<string>> c;
for (long i = 0; i < 10; ++i){
    snprintf(buf, 10, "%d", rand());
    c.push(string(buf));
}
```

stack可选择vector做底层结构，但queue不可选择vector做底层结构。

这是因为queue的`pop()`在vector中找不到对应的`pop_front()`。

如果在用queue时确实没有使用pop()，那可以用vector做底层结构。

stack和queue都不可选择set或map作为底层结构。

