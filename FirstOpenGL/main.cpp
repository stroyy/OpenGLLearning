#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>

// �ص����������ڴ�С�ı�ʱ���ӿڴ�СҲ��֮�ı�
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

// ��������
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

int main() {
	// GLFW��ʼ��
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// �������ڶ���
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// ��ʼ��GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// ��Ⱦ
	//glViewport(0, 0, 600, 300); // �ӿڴ�С
	// ��ӻص� ���ӿڴ�С���Ŵ��ڴ�С�ı���ı�
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// ��Ⱦѭ��
	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// �����˳�
	glfwTerminate();
	return 0;
}
