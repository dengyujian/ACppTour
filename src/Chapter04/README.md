#  第 4 章 结构体、函数和 `#include`

### 1. 头文件

`#include <系统头文件>`
`#include "用户定义的头文件"`

使用 `#ifndef` 避免头文件重复包含

在自定义头文件中不应该包含有 using 声明，而应该给标准库的名称明确地加一个命名空间前缀 。

### 2. 类型

`T&`：对类型为 T 的对象的一个引用

`const T&`：也是对类型为 T 的对象的一个引用，但是不可以修改引用的对象的值

“左值”的概念

### 3. 结构体


```
struct type-name {
    type-name var_a;
    type-name var_b;
    ...
}
```

### 4. 函数

函数声明：
```
ret-type function-name(parm-decls);
```

函数定义：
```
ret-type function-name(parm-decls) {
    // 函数体
}
```

内联函数（用于编译器优化函数调用）：
```
[inline] ret-type function-name(parm-decls) {
    // 函数体
}
```

函数调用：
- 按值调用（call by value）
- 按引用调用

### 5. 异常处理

try-catch：
```
try {
    // 正常执行的代码
} catch (t) {
    // 处理异常的代码
}
```
异常类：
- logic_error
- domain_error
- e.what()
- ...

### 6. 库工具

s1 < s2：字符串比较
s.width(n)：
setw(n)：设置输出内容的宽度
