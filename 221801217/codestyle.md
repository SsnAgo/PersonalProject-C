# 221801217的代码规范约定

* 缩进：一个Tab

* 命名

  * 普通变量和参数变量：首字母小写驼峰  例如:seStuCnt
  * 常量：常量命名全部大写，单词间用下划线隔开  例如：MAX_CNT
  * 函数名：首字母小写驼峰 例如：getStuCnt



* 空行规则

  * 函数之间空两格

  * 括号使用：不另起一行

  * ```
    for(int i = 0; i < cnt; i++){
    	total += i；
    }
    ```

​    

* 注释规则
  * 做到每个类，每个方法（get，set除外）都有注释
  * 单行注释  //或# 多行注释/**/
* 操作符前后均添加空格