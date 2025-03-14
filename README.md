* 有两种实现方式：第一种是QT+OPENGL 第二种是GLFW+GLAD
* 使用qt更偏向于实战开发

先自己跟着文档实现+思考+记录问题 然后可以在看一遍视频，看看其他人的讲解

# 准备步骤
1. 下载glfw,通过cmake构建编译
2. 将include和lib放到统一目录下
3. 通过glad在线服务 生成glad.c 和glad.h khrplatform.h  .c文件添加进项目 .h文件放在同一目录下
4. 新建vs项目，修改项目配置，添加依赖目录和依赖库
5. 添加代码 成功编译运行



# 笔记 
* opengl只是一个规范，具体的实现都是由驱动开发商针对特定显卡实现的。 由于opengl驱动版本太多，大多数函数的位置在编译时无法确定，只能在运行时查询。所以开发者需要在运行时获取函数地址并保存到函数指针中方便后续使用。取地址的方法因平台而异，代码复杂，繁琐，在每个使用函数的过程都要重复这个步骤，但是通过glad就可以简化此过程
* opengl函数指针都由glad管理，所以在调用任何opengl函数前需要初始化GLAD 

# 文件
* FirstOpenGL：用到了glfw初始化，opengl的输入处理，opengl窗口创建，glad初始化（管理opengl函数指针）,视口 ，渲染指令,回调函数。
	* 这里有个问题：viewPort视口大小和opengl窗口大小的关系 viewPort是用来干嘛的？

# 资料
文档 [LearnOpenGL](https://learnopengl-cn.github.io/01%20Getting%20started/04%20Hello%20Triangle/)
视频 [QT+OPENGL](https://www.bilibili.com/video/BV1Qf421q7Dt?spm_id_from=333.788.videopod.episodes&vd_source=643846a492e97467f7a6183131a2b1c0&p=3)
