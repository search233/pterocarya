- - # 第6讲 HTML和XML(补充)
  
    ## HTML语言介绍
  
    ### HTML概念
    - HTML（Hyper Text Markup Language，超文本标识语言）是一种用来制作超文本文档的简单标记语言。
    - 用HTML编写的超文本文档称为HTML文档。
  
    ### HTML文档的编写方法
    1. 手工直接编写：使用记事本等工具，存成.htm或.html格式。
    2. 使用可视化HTML编辑器：如Frontpage、Dreamweaver等。
    3. 由Web服务器实时动态生成。
  
    ### 网页文件命名
    - 文件扩展名：*.htm或*.html。
    - 文件名要求：无空格、无特殊符号（只允许下划线“_”，只能为英文、数字）。
    - 区分大小写。
    - 首页文件名默认为：index.htm或index.html。
  
    ### HTML文件结构
    - 基本结构：`<html>...</html>`、`<head>...</head>`、`<body>...</body>`。
    - 元素：HTML语言的基本部分，元素总是成对出现，如`<body>`和`</body>`。
  
    ### HTML基本结构的有关元素和元素属性
    - `<head>`元素：出现在文档开头部分，其内容不会在浏览器窗口显示，但有特殊重要意义。
      - `<title>`：定义HTML文档的标题，内容显示在浏览器窗口的标题栏。
      - `<meta>`：可以插入多种属性，如：
        - `<meta name="keywords" content="study,computer">`：标记搜索引擎关键词。
        - `<meta name="author" content="wutao">`：标记文档作者。
        - `<meta http-equiv="Content-Type" content="text/html; charset=gb2312">`：标记页面解码方式。
        - `<meta http-equiv="refresh" content="5;URL=http://www.wust.edu.cn">`：自动刷新网页。
    - `<body>`元素：HTML文档的主体部分，包含其他元素和属性。
      - 属性：
        - `bgcolor`：设置背景颜色，如`bgcolor="#CCFFCC"`。
        - `background`：设置背景图片，如`background="images/bg.gif"`。
        - `bgproperties="fixed"`：使背景图片成水印效果。
        - `text`：设置正文文字颜色，如`text="#FF6666"`。
        - 超链接颜色：`link`、`vlink`、`alink`分别控制普通超级链接、访问过的超级链接、当前活动超级链接颜色。
        - `leftmargin`和`topmargin`：设置网页主体内容距离网页顶端和左端的距离。
  
    ### 文字标签属性
    - 文字颜色：`<font color=#> ... </font>`，如`<font color="#ff0000">红色文本</font>`。
    - 文字字体：`<font face="#, #, ..., #"> ... </font>`，如`<font face="Arial, Helvetica, sans-serif">字体示例</font>`。
    - 文字大小：`<font size=#> ... </font>`，如`<font size="4">大号文本</font>`。
    - 文字标题：`<h#> ... </h#>`，如`<h1>一级标题</h1>`。
  
    ### 文字布局
    - 段落：`<p>`，如`<p>这是一个段落。</p>`。
    - 换行：`<br>`，如`<br>`。
    - 不换行：`<nobr>`，如`<nobr>不换行文本</nobr>`。
    - 文本格式化：`<i>`、`<b>`、`<u>`、`<s>`，如`<i>倾斜文本</i>`、`<b>粗体文本</b>`。
    - 文本对齐：`<hn align=#>`、`<p align=#>`，如`<h1 align="center">居中标题</h1>`。
    - 分区显示：`<div align=#>`，如`<div align="right">右对齐文本</div>`。
  
    ### 超级链接
    - 普通超级链接：`<a href="URL">链接文本</a>`，如`<a href="http://www.wust.edu.cn">指向学院的超级链接</a>`。
    - E-mail超级链接：`<a href="mailto:email地址">链接文本</a>`，如`<a href="mailto:simon@wust.edu.cn">指向Email地址的超级链接</a>`。
    - 新开链接窗口：`<a href="URL" target="_blank">链接文本</a>`。
    - 锚点（书签）：`<a name="锚点名称">`、`<a href="#锚点名称">链接文本</a>`。
  
    ### 图片控制
    - 基本语法：`<img src="图片名称">`。
    - 替代文本：`<img src="图片名称" alt="替代文本">`。
    - 显示大小：`<img src="图片名称" width="宽度" height="高度">`。
    - 边框：`<img src="图片名称" border="边框宽度">`。
    - 对齐方式：`<img src="图片名称" align="对齐方式">`。
    - 与文本的间距：`<img src="图片名称" hspace="水平间距" vspace="垂直间距">`。
    - 图像的超级链接：`<a href="URL"><img src="图片名称"></a>`。
    - 图像映射：由`<map>`定义，`<img>`元素通过`usemap`属性引用。
  
    ### 表格
    - 基本结构：`<table>`、`<tr>`、`<td>`、`<th>`。
    - 属性：
      - `width`、`height`：指定表格或单元格的宽度和高度。
      - `border`：表格边框粗细。
      - `bgcolor`、`background`：背景颜色和背景图片。
      - `bordercolor`、`bordercolorlight`、`bordercolordark`：边框颜色。
      - `align`、`valign`：内容对齐方式。
      - `cellspacing`、`cellpadding`：单元格间距和边距。
      - `colspan`、`rowspan`：单元格跨越列数和行数。
  
    ### 表单
    - 功能：收集客户端提交的信息，实现网页与浏览器端的交互。
    - 基本语法：`<form action="url" method="get/post">...</form>`。
    - 表单元素：
      - 文本框：`<input type="text" name="名称" value="默认值" size="长度" maxlength="最大字符数">`。
      - 密码框：`<input type="password" name="名称" value="默认值" size="长度" maxlength="最大字符数">`。
      - 文本域：`<textarea name="名称" rows="行数" cols="列数">...</textarea>`。
      - 按钮：`<input type="submit" value="提交">`、`<input type="reset" value="重置">`。
      - 复选框：`<input type="checkbox" name="名称" value="值">`。
      - 单选框：`<input type="radio" name="名称" value="值">`。
      - 下拉列表/列表框：`<select name="名称">...<option value="值">选项</option>...</select>`。
      - 图像域：`<input type="image" src="图片URL">`。
  
    ### 网页中的框架
    - 基本语法：`<frameset>`、`<frame src="url">`、`<noframes>`。
    - 属性：
      - `rows`、`cols`：定义框架的行和列。
      - `bordercolor`：框架边框颜色。
      - `frameborder`：是否显示边框。
      - `framespacing`：框架边框宽度。
      - `name`：框架名称。
      - `target`：目标框架。
      - `scrolling`：是否显示滚动条。
      - `noresize`：是否允许调整大小。
    - 内含窗口：`<iframe src="url" name="名称">...</iframe>`。
  
    ## XML语言
  
    ### XML概述
    - XML（eXtensible Markup Language，可扩展置标语言）是一种元置标语言，用于创建结构化、自我描述的文档。
    - XML是一种结构化和语义化的标记语言，用于传输信息，与平台、软件和硬件无关。
    - XML文档需要遵循语法规则（语法），通过DTD（Document Type Definition）或XML Schema验证其合法性。
  
    ### XML应用实例
    - 示例：联系人列表的XML表示。
      ```xml
      <联系人列表>
        <联系人>
          <姓名>张三</姓名>
          <ID>001</ID>
          <公司>A公司</公司>
          <EMAIL>zhang@aaa.com</EMAIL>
          <电话>(010)62345678</电话>
          <地址>
            <街道>五街1234号</街道>
            <城市>北京市</城市>
            <省份>北京</省份>
          </地址>
        </联系人>
        <联系人>
          <姓名>李四</姓名>
          <ID>002</ID>
          <公司>B公司</公司>
          <EMAIL>li@bbb.org</EMAIL>
          <电话>(021)87654321</电话>
          <地址>
            <街道>南京路9876号</街道>
            <城市>上海市</城市>
            <省份>上海</省份>
          </地址>
        </联系人>
      </联系人列表>
      ```
  
    ### XML和HTML比较
    | 特点             | HTML                         | XML                                     |
    | ---------------- | ---------------------------- | --------------------------------------- |
    | 可扩展性         | 不具有扩展性                 | 是元置标语言，可用于定义新的置标语言    |
    | 侧重点           | 侧重于如何表现信息           | 侧重于如何结构化地描述信息              |
    | 语法要求         | 不要求标记的嵌套、配对等     | 严格要求嵌套、配对，并遵循DTD的树形结构 |
    | 可读性及可维护性 | 难于阅读、维护               | 结构清晰，便于阅读、维护                |
    | 数据和显示的关系 | 内容描述与显示方式整合为一体 | 内容描述与显示方式相分离                |
    | 保值性           | 不具有保值性                 | 具有保值性                              |
    | 编辑及浏览工具   | 已有大量的编辑、浏览工具     | 编辑、浏览工具尚不成熟                  |
  
    ### XML语法
    - XML文档的逻辑结构：
      - XML声明：`<?xml version="1.0" encoding="GB2312" standalone="no"?>`
      - 元素：通过元素组织XML数据，如`<元素名称>内容</元素名称>`。
      - CDATA节：用于包含不应由XML解析器解析的文本。
      - 注释：`<!-- 注释内容 -->`。
      - 处理指令：提供给XML处理程序的指示信息。
    - XML文档的物理结构：
      - 参数实体引用与通用实体引用的差异。
  
    ### DTD的建立和使用
    - DTD概述：
      - 是一套关于标记符的语法规则。
      - 可以是XML文档的一部分，但通常是一份单独的或一系列的文档。
      - 行业或组织可定义自己的DTD。
      - 规定了语法分析器解释所有细节。
    - 内部DTD：文档由前导说明和文档体构成，前导说明中包含XML声明和DTD定义。
    - 外部DTD：引用外部文件中的DTD。
    - 公用DTD：由权威机构制定，提供给特定行业或公众使用的DTD。
    - 元素定义：
      - 元素可以为空，也可以是纯文本或若干个子元素。
      - 子元素可以有各自的子元素。
      - DTD通过元素之间的父子关系描述整个文档的结构关系。
    - 定义元素属性：
      - 属性名、属性类型、缺省值。
      - 示例：
        - `<!ATTLIST 元素名 属性名 属性类型 #REQUIRED>`：属性必须存在。
        - `<!ATTLIST 元素名 属性名 属性类型 #IMPLIED>`：属性可选。
        - `<!ATTLIST 元素名 属性名 属性类型 #FIXED"缺省值">`：属性有固定值。
        - `<!ATTLIST 元素名 属性名 属性类型 "缺省值">`：属性有默认值。
  
    ### Schema的建立与应用
    - Schema是XML的一种应用，将DTD重新按照XML语言规范来定义。
    - 示例：
      ```xml
      <Schema xmlns="urn:schemas-microsoft-com:xml-data"
              xmlns:dt="urn:schemas-microsoft-com:datatypes">
        <AttributeType name="年级"/>
        <AttributeType name="班级"/>
        <ElementType name="姓名"/>
        <ElementType name="籍贯"/>
        <ElementType name="年龄"/>
        <ElementType name="电话" dt:type="fixed.14.4"/>
        <ElementType name="学生" content="eltOnly"/>
        <ElementType name="学生花名册" content="eltOnly">
          <attribute type="年级"/>
          <attribute type="班级"/>
        </ElementType>
      </Schema>
      ```
    - Schema的优点：
      - 一致性：与DTD类似，易于理解。
      - 扩展性：引入数据类型、命名空间。
      - 互换性：可以进行文档验证和数据交换。
      - 规范性：定义了XML文档的整体结构。
      - 易用性：可以用DOM和SAX访问。
  
    ## 示例HTML文档
    ```html
    <html>
    <head>
      <title>my first page</title>
      <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    </head>
    <body>
      <H1 align="center">Welcome to My Homepage!</H1>
      <H2>Name: Simon.Gu</H2>
      <P>Addr: 30406<br>School: Computer Science<br></p>
      <a href="mailto:simon@wust.edu.cn">mail to Me!</a>&nbsp;&nbsp;
      <a href="http://www.wust.edu.cn">Visit WUST</a>
    </body>
    </html>
    ```