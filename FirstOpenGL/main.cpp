#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>

// 回调函数：窗口大小改变时，视口大小也随之改变
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

// 处理输入
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

int main() {
	// GLFW初始化
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// 创建窗口对象
	GLFWwindow* window = glfwCreateWindow(600, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// 初始化GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	
	glViewport(0, 0, 300, 300); // 视口大小
	// 添加回调 ：视口大小随着窗口大小改变而改变
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	
	while (!glfwWindowShouldClose(window)) {
		processInput(window);
		// 渲染指令
		glClearColor(0.2f, 0.2f, 0.3f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		// 调用事件，交换缓冲
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	// 清理并退出
	glfwTerminate();
	return 0;
}
