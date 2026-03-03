struct Node
{
    int value;
    Node* left;
    Node* right;
    Node(int i = 0): value(i), left(nullptr), right(nullptr) {}
};

auto left = &Node::left; // left 成员相对于 Node 类起始地址的偏移量（比如偏移 4 字节）
auto right = &Node::right; // right 成员相对于 Node 类起始地址的偏移量（比如偏移 12 字节）
// &Node::left和&Node::right 存储的是偏移量，而非具体内存地址 —— 这是编译器在编译期就能确定的，完全不需要创建对象实例。

/*
折叠形式	参数包args...展开规则	适用场景
(init op ... op args)	二元左折叠：((init op arg1) op arg2) op arg3	有初始值的链式运算
(args op ... op init)	二元右折叠：arg1 op (arg2 op (arg3 op init))	有初始值的链式运算
(args op ...)	一元左折叠：((arg1 op arg2) op arg3) op ...	无初始值的参数包链式运算
(... op args)	一元右折叠：... op (arg2 op arg3)	无初始值的参数包链式运算
*/
template <typename T, typename... TP>
Node* traverse(T np, TP... paths)
{
    return (np->* ... ->* paths);  // np ->* paths1 ->* paths2 ...
} 

/*
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);

    // 两种写法等价
    Node* p1 = root->left;                // 普通写法
    Node* p2 = root->*(&Node::left);      // 成员指针写法
    Node* p3 = root->*left;               // 用定义的left变量

    std::cout << p1->value << std::endl; // 输出2
    std::cout << p2->value << std::endl; // 输出2
    std::cout << p3->value << std::endl; // 输出2

    delete root->left;
    delete root;
    return 0;
}

*/
