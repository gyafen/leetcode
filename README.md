# 1、优先队列模型

以最小元素优先级最高为例，优先队列是允许至少下列两种操作的模型：

1. 插入元素：将新来的元素插入到优先队列的容器中
2. 删除最大元素：找出、返回、并删除优先队列中的最小元素

![image-20220519192345123](https://cloud-storage-1305188020.cos.ap-chengdu.myqcloud.com/image/markdownimage-20220519192345123.png)

怎么去实现这样一个模型呢？

# 2、二叉堆

二叉堆是实现优先队列非常普遍的一种工具，以至于堆这个词不加修饰地使用在优先队列的上下文时，一般都是指优先队列的实现。

![image-20220519192430296](https://cloud-storage-1305188020.cos.ap-chengdu.myqcloud.com/image/markdownimage-20220519192430296.png)

## 2.1、二叉堆的结构性质

堆是一棵被完全填满的二叉树，有可能的例外是在底层，底层的元素从左到右填入，即是一棵完全二叉树。一颗高度为h的完全二叉树有 2<sup>h</sup> 到 2<sup>h+1</sup>-1 个节点，这也意味着完全二叉树的高度为⌊log N⌋。

由于完全二叉树的存储非常有规律，因此可以用数组而非链结构来表示它。对于数组中任意一个位置i上的元素，它的左儿子总是在位置2i上，右儿子总是在位置2i+1上，它的父亲节点总是在位置⌊i/2⌋上。例如上图中的完全二叉树可以表示为：

![image-20220519194704646](https://cloud-storage-1305188020.cos.ap-chengdu.myqcloud.com/image/markdownimage-20220519194704646.png)

## 2.2、二叉堆的堆序性质

让操作快速执行的性质是堆序性质。由于想要找到最小元，因此最小元应该在根节点上。如果考虑任何一棵子树也应该是一个堆，那么任意节点就应该小于它的所有后裔。

## 2.3、基本的堆操作

**insert（插入）**

为了将一个元素x插入到堆中，可在下一个可用位置创建一个空穴。如下：

![image-20220519195949938](https://cloud-storage-1305188020.cos.ap-chengdu.myqcloud.com/image/markdownimage-20220519195949938.png)

以插入x=14为例，由于将14插入空穴破坏了堆序性质（31>14），因此将需将31移入到空穴中：

![image-20220519200421621](https://cloud-storage-1305188020.cos.ap-chengdu.myqcloud.com/image/markdownimage-20220519200421621.png)

同样，21>14，所以将21移入到空穴中：

![image-20220519200546016](https://cloud-storage-1305188020.cos.ap-chengdu.myqcloud.com/image/markdownimage-20220519200546016.png)

重复这种策略，直到将14插入到正确位置：

![image-20220519200641402](https://cloud-storage-1305188020.cos.ap-chengdu.myqcloud.com/image/markdownimage-20220519200641402.png)

这种策略称为**上滤**。







