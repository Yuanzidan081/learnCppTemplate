我们借助这个`main.cpp`里的`SafeDivide3`的例子，帮助大家理解一下这个结构是怎么工作的：

1. 对`SafeDivide3<int>`
+ 通过匹配类模板的泛化形式，计算默认实参，可以知道我们要匹配的模板实参是`SafeDivide3<int, true_type>`

+ 计算两个偏特化的形式的匹配：A得到`<int, false_type>`,和B得到 `<int, true_type>`

+ 最后偏特化B的匹配结果和模板实参一致，使用它。

2. 针对`SafeDivide3<complex<float>>`
+ 通过匹配类模板的泛化形式，可以知道我们要匹配的模板实参是`SafeDivide3<complex<float>, true_type>`

+ 计算两个偏特化形式的匹配：A和B均得到`SafeDivide3<complex<float>, false_type>`

+ A和B都与模板实参无法匹配，所以使用原型，调用`CustomDiv`