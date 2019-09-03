# Trader

此项目搬运自https://gitee.com/alenhang/Trader



#### 项目介绍

Trader是一个销售交易软件，后续补充完整。

#### 软件架构
销售模块基本流程：
新建报价单->合同->生产监管->发货
详情后续补充完整


#### 安装教程

使用git把代码克隆下来，配置到QT中进行版本控制。
1、下载QT，下载地址 http://download.qt.io/archive/qt/
![输入图片说明](https://images.gitee.com/uploads/images/2018/1123/183828_d3a088d6_1806689.png "屏幕截图.png")
点击进入5.10/版本，并且选择exe进行下载
![输入图片说明](https://images.gitee.com/uploads/images/2018/1123/183937_a7f6bd56_1806689.png "屏幕截图.png")

#### 使用说明
然后安装
 执行下一步，进入选择界面。

下面，就到了重点了。在选择组件界面，请务必要选对安装 Qt 所需要的组件，否则你安装以后是无法正常运行的。

首先，点击各项前面的 > 箭头展开子项的内容。
![输入图片说明](https://images.gitee.com/uploads/images/2018/1123/184350_db54f0c1_1806689.png "屏幕截图.png")
选项说明（只针对Windows系统）在 Qt5.11 一项中，如果你是使用 MinGW 进行编译，请务必选中 MinGW 模块。而如果你希望调用 VS 的编译器进行编译，则需要勾选对应的 VS 模块。当然，如果希望进行安卓开发，则安卓模块是少不了了。
![输入图片说明](https://images.gitee.com/uploads/images/2018/1123/184402_310ee1a2_1806689.png "屏幕截图.png")




下面，接着看工具项（Tools）的选择。

第一项是CDB的调试器，如果你仅使用 MinGW进行编译，则此项可以不选。

第二项虽然名字带 MinGW，但只是用于交叉编译的（交叉编译即在某一平台上编译用于其他平台的程序），如果用不到，也可以不选。

至于第三项，那是用于 Perl 的。如果你电脑中本身没有安装 Perl，那是装不上的。

选择完成后，继续点击“下一步”。




#### 参与贡献

1. Fork 本项目
2. 新建 Feat_xxx 分支
3. 提交代码
4. 新建 Pull Request


#### 码云特技

1. 使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md
2. 码云官方博客 [blog.gitee.com](https://blog.gitee.com)
3. 你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解码云上的优秀开源项目
4. [GVP](https://gitee.com/gvp) 全称是码云最有价值开源项目，是码云综合评定出的优秀开源项目
5. 码云官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)
6. 码云封面人物是一档用来展示码云会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)