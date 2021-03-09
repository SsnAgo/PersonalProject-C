# 代码规范

1. 缩进  

4个空格
```
for i in range(10):
    print(i)
```

2. 变量命名 

下划线法命名
```
input_file = sys.argv[1]
```

3. 每行最多字符数  

每行不超过`80`个字符（除非有很长的URL）
```
line += "".join(random.sample(string.ascii_letters +
                              string.digits, n))
```

4. 函数、类命名  

函数采用下划线法命名
```
def say_hi():
    print("hi")
```
类采用大驼峰法命名
```
class TestWord(TestCase):
    # do something...
```

5. 常量  

`python`没有常量，一般用全部大写表示常量，并用下划线分隔

6. 空行规则  
    + 函数与函数之间、类与类之间用两个空行隔开
    + 方法中不同的逻辑相关之间用一个空行隔开

7. 注释规则  

`#`后面一般空一格再跟上注释内容

8. 操作符前后空格  

在操作符前后各加一个空格
```
lines += 1
```
在参数的逗号后面加一个空格
```
def count_word(line, count):
    # do something...
```
参数中，默认值的等号两边不加空格
```
def say_hi(age, name="hi"):
    pass
```

9. 其他规则  
参考[PEP 8](https://www.python.org/dev/peps/pep-0008/)