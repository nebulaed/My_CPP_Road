Red-Black tree(红黑树)是平衡二分查找树中常被使用的一种。

平衡二分查找树的特征：排列规则有利search和insert，并保持适度平衡——无任何节点过深。

 rb_tree提供两种insertion操作：`insert_unique()`和`insert_equal()`。前者表示节点的key一定在整个tree中独一无二，否则安插失败。后者表示节点的key可重复。

 