# Evaluation-of-Four-Arithmetic-Expressions
# 四则运算表达式求值
## 程序框架
![image](https://user-images.githubusercontent.com/58458394/230827348-67263433-f1d3-4009-9d3d-b9784afa33ec.png)
## （1）功能函数主菜单Display()
### ①函数的功能：主要作用是提示用户操作，体现模块化思想，主要是显示出菜单让用户选择要进行的任务。
### ②函数的入口：在main()中的直接被调用。
### ③函数调用关系：被主函数调用，在文中是无返回值的void函数。
### ④函数的出口：当且仅当用户选择退出时，即select的值为0时退出该函数。
## （2）功能函数Instru()
### ①函数的功能：打印使用说明。  
### ②函数的入口：先从main()中第一个switch()开关结构中进入四则运算，即select的值为2时，进入打开文件操作，如果文件打开成功输出“使用说明.txt”中的内容，否则提示文件打开失败。
### ③函数调用关系：仅被主函数调用。
### ④函数的出口：当打印完使用说明或者输出错误提示后返回主菜单。
## （3）功能函数Conver()
### ①函数的功能：将字符串操作单元化，。
### ②函数的入口：在Evalua()函数中进入。
### ③函数调用关系：被Evalua()函数调用。
### ④函数的出口：将字符串操作单元化，并记录在操作单元结构体数组中后返回Evalua函数。
## （4）功能函数Four_arithm()
### ①函数的功能：对接受到的两个运算数根据对应的运算进行相应的四则运算。
### ②函数的入口：在Calculate()函数中进入。
### ③函数调用关系：被Calculate()函数调用。
### ④函数的出口：经过计算，返回四则运算结果到Evalua函数。
## （5）功能函数Calculate()
### ①函数的功能：对操作单元进行计算并根据表达式是否合法，输出相应的结果。
### ②函数的入口：在Evalua()函数中进入。
### ③函数调用关系：被Evalua()函数调用。
### ④函数的出口：经过计算，如果表达式合法，返回正确结果，不合法这将标志变量更新后返回操作数栈的栈底元素到Evalua函数。
