set/multiset以rb_tree为底层结构，因此有元素自动排序，排序依据是key，而set/multiset的value和key合一。

set/multiset提供遍历操作和iterators。按正常规则(++it)遍历，就能获得排序状态。

无法使用set/multiset的iterators改变元素值(因为key有严谨排列规则)，set/multiset的iterator是其底部的RB_tree的const_iterator，就是为了禁止user对元素赋值。

set元素的key必须独一无二，因为其insert调用的是rb_tree的`insert_unique()`

而multiset的insert调用的是`insert_equal()`

set的所有操作，都是转呼叫底层t的操作。

从这层意味看，set未尝不是个container adapter。  



无法使用map/multimap的iterators改变元素的key(因为key有其严谨排列规则)，但可以用它来改变元素的data。因此map/multimap内部自动将user指定的key type设为const，如此就能禁止user对元素的key赋值。

map底层的rb_tree的value_type是`pair<const Key, T>`，而map/multimap的iterator是rb_tree的iterator。

map的operator[]先使用了lower_bound查找key对应的第一个iterator，若没有查找到则获得最适合安插的iterator，然后返回了该iterator指向的pair的second的引用(mapped_type&)，可以修改值。

在插入时，直接使用insert比使用operator[]进行插入更快，因为operator[]需要先使用lower_bound进行查找，再调用insert。