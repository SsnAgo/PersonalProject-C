 ---
[toc]
---

##缩进
*   1.缩进使用TAB键
    2.关键字之后要留空格。象 const、virtual、inline、case 等关键字之后至少要留一
        个空格， 否则无法辨析关键字。象 if、for、while 等关键字之后应留一个空格再跟左
        括号‘（ ’， 以突出关键字。
    3.函数名之后不要留空格， 紧跟左括号’(’ ， 以与关键字区别。
    4.‘( ’ 向后紧跟，‘ )’、‘ ，’、‘ ;’ 向前紧跟， 紧跟处不留空格。
    5.‘ ,’ 之后要留空格， 如 Function(x, y, z)。
    6.值操作符、比较操作符、算术操作符、逻辑操作符、位域操作符，如“ =”、“ +=”
        “ >=”、“ <=”、“ +”、“ *”、“ %”、“ &&”、“ ||”、“ <<” 、“ ^” 等二元操作符
        的前后应当加空格。
    7.一元操作符如“ !”、“ ~”、“ ++”、“ --”、“ &”（ 地址运算符） 等前后不加
        空格。
    8.象“［ ］”、“ .”、“ ->” 这类操作符前后不加空格。

##变量命名
*   变量命名采用驼峰命名法，第一个单词小写，后面的单词均首字母大写表示，如：wordCountTest

##每行最多字符数
*   较长的语句（>80 字符）要分成多行书写。

##函数最大行数
*   暂无限制，合理封装即可，一般扣去可复用部分和变量赋值外，不超过50行。

##函数名和类名命名
*   同使用驼峰命名法，如上。

##常量
*   define定义的常量使用全部大写，单词用下划线“_”分割开。

##空行规则
*   1.程序块之间用空行隔开
    2.功能差别较大的函数声明中间也会用空行隔开

##注释规则
*   一般写在头文件的定义处，对于简单函数使用双斜杠进行简单的注释
    复杂的函数会使用/**/来标注接口，输出，作用等信息。