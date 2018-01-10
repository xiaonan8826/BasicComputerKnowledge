# 8个标记符号玩转Markdown

标签（空格分隔）： Markdown

---

> Markdown 可以制作出相当精美的文档，可是初学者往往被那些看上去复杂的`标记符号`所困惑，其实这些标记符号没有多少，常用的也就是那几个,我们把这几个常用的标记符号记住，就能处理大部分的文档编辑任务了 <i class="icon-smile"></i>
其实我们只要记住下面8个`标记符号`，玩转Markdown就能6的飞起

## 1. 标题
**要记住的:**

- Markdown中的标题用`#`来表示
- 一共有六个级别的标题，分别从`#`到`######`

**示例：**
`#一级标题`
>#一级标题

`##二级标题`
>##二级标题

`######六级标题`
>######六级标题
## 2. 分割线
**要记住的**

- 分割线能使文档结构更清晰，用`---`来表示

**示例：**
`---`或`------`
> ---
## 3. 引用
**要记住的**

- 引用表示该文字是引用的别处的，其底色会置灰
- 用`>`表示

**示例：**
```
> 有些鸟儿是注定不能被关在笼子里的
           因为它们的羽毛太过艳丽
            -----《肖申克的救赎》
                
```
> 有些鸟儿是注定不能被关在笼子里的
            因为它们的羽毛太过艳丽
            -----《肖申克的救赎》
## 4. 列表
**要记住的**

- 列表可以用`-`或`*`或`+`来表示

**示例：**
```
- c
- java
- python
```

- c
- java
- python 

**如果想要在列表前加上check选项**

- [ ] check
```
- [ ] notcheck
- [x] check
```
- [ ] notcheck
- [x] chech

## 5. 链接和图片
**要记住的**

- 链接：有两种形式
    - 1.`[要显示的链接名](url)`
    - 2.`[要显示的链接名][别名]`其中`[别名]`要在另外的地方用`[别名]:url`定义
- 图片：只需要在链接前加上！就行了`![图片坏了时显示的名字](url)`

**示例**
```
百度链接：[<i class="icon-link"></i>](https://www.baidu.com)
或
百度链接：[<i class="icon-link"></i>][alias1]
```
> 百度链接：[<i class="icon-link"></i>](https://www.baidu.com>)
> 或
> 百度链接：[<i class="icon-link"></i>][alias1]
```
图片链接：![糟糕](url)
```
> 图片链接：![糟糕](https://www.baidu.com)

## 6. 代码
**要记住的**

- 代码框出了一个代码块的位置，用` ``` `表示
- ` ```c++ `说明了代码的类型，可以显示符合该类型语言的样式

**示例**

```c
/*c语言示例*/
void main(){
    int i,j;
    int str[] = "hello world";
    i = 0;
    j = 0;
    printf("output:i=%d,j=%d,str=%c",i,j,str);
}
```

## 7. 公式
公式在编辑文档的时候必不可少，其实有很简单的记忆规则
**要记住的**

- 公式用`$`套起来，比如这样`$\sqrt{a}$`，如果想单独一行就用`$$`
- 用Markdown的公式符号可以表示很复杂的公式

**示例**

- 1.表示二元一次方程的解
```
$$x=\frac{-b\pm\sqrt{b^2+4ac}}{2a}$$
```

$$x=\frac{-b\pm\sqrt{b^2+4ac}}{2a}$$
其中`\frac{a}{b}`表示分数fraction，a为分子
而如果`\tfrac{a}{b}`,加上`t`则表示小号的分数
$$x=\tfrac{-b\pm\sqrt{b^2+4ac}}{2a}$$

- 2.表示正态分布

$$f(x)=\frac{1}{\sqrt{2\pi}\delta}\exp\left(-\frac{(x-\mu^2)}{2\delta^2}\right)$$
**几个要记住的公式符号**

: 1.^上标,_下标
    : `$a^2 a_1$`
    : $a^2 a_1
    
: 2.各种括号
    : 小括号(,暂时没找到标记符号
    : 中括号 `\lbrack`$\lbrack$，`\rbrack`$\rbrack$，`\brack`$\brack$
    : 大括号 `\lbrace`$\lbrace$，`\brace`$\rbrace$，`\rbrace`$\brace$
    : 如果需要括号适应大小要加`\left`或`\right`,要成对出现
    `$\left(\frac{abc}{\frac{abc}{abc}\times abc}\right)$`
    $\left(\frac{abc}{\frac{abc}{abc}\times abc}\right)$
    
: 3.累加 累积
    : 累加`\sum`$\sum_{i=0}^{i=n}$
    : 累积`\prod`$\prod_{i=0}^{i=n}$

: 4.积分
    ：积分intergration `$\int$`$\int$ `\iint`$\iint$
    
: 5.无穷
    : `\infty`$\infty$

: 6.省略号
靠下`\ldots`$a,b,\ldots$
居中`\cdots`$a,b,\cdots$
**公式符号有点多但并不复杂，记住几个常用的，就能扫倒一大片了**
## 8. 表格
表格在文档编辑中必不可少，Markdown的表格编辑非常简单
**要记住的**

- 表格可以用`|`来形象化的分割表示
- 可以`---:`用来设置表格内容居左中右

**示例**
```
|表头1|表头2|表头3|
|:----|:---:|----:|
|1    |2    |3    |
|a    |b    |c    |
```
|表头1|表头2|表头3|
|:----|:---:|----:|
|1    |2    |3    |
|a    |b    |c    |

___
>**现在常用的8个Markdown标记已经掌握了**
**有了这8个利器就可以在Markdown的世界里自由驰骋了**
**如果还想为自己的文档添加点特色，下面这些也要了解下**

##Icon

* Icon可以给文档添加各种小图标

**示例**
`<i class="icon-file"></i>`
<i class="icon-file"></i>
放大`<i class="icon-file icon-2x"></i>`
<i class="icon-file icon-2x"></i>
常用的图标有file<i class="icon-file"></i>，list<i class="icon-list"></i>，reorder<i class="icon-reorder"></i>，home<i class="icon-home"></i>，cloud<i class="icon-cloud"></i>，thumbs-up<i class="icon-thumbs-up"></i>，adjust<i class="icon-adjust"></i>，heart<i class="icon-heart"></i>，mail-forward<i class="icon-mail-forward"></i>，pencil<i class="icon-pencil"></i>
**可以在[fontawesome](http://fontawesome.io/3.2.1/icons/)里查，有很多**

## 脚注
可以用脚注`[^text]`使用时要在文档末尾加上`[^text]:abcd`

**示例**
对创新最好的评价就是“这太显而易见了，我怎么就没想到”[^1]

## 内嵌HTML

- 可以嵌入table表格的HTML代码和其他的HTML


**示例**
<span style="font-size:23em">hello <b>world</b><span>

## 目录

- 最后看一下目录`[toc]`table of content

[toc]




[alias1]:https://baidu.com

[^1]:脚注