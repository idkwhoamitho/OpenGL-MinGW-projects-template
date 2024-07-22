#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include "VBO.h"
#include "VAO.h"
#include "Shader.h"
using namespace std; 

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    if (!glfwInit())
    {
        cout << "Failed to initialize GLFW" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;
    window = glfwCreateWindow(800, 600, "ZMMR", NULL, NULL);
    if (window == NULL)
    {
        cout << "Failed to open GLFW window" << endl;
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }
    GLfloat vertices[] = 
    {
        0.5f, 0.5f * float(sqrt(0.5f))/0.5f, 0.5f,
        0.5f, -0.5f * float(sqrt(0.5f))/0.5f, 0.5f,
        -0.5f, -0.5f * float(sqrt(0.5f))/0.5f, 0.5f,
    };

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    Shader ShaderProgram("shaders/Default.vert", "shaders/Default.frag");


    VAO VAO1;
    VAO1.bind();

    VBO VBO1(vertices, sizeof(vertices));

    VAO1.LinkVBO(VBO1, 0);
    VAO1.Unbind();
    VBO1.Unbind();


    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        VAO1.bind();
        ShaderProgram.UseProgram();
        glDrawArrays(GL_TRIANGLES, 0 , 3);

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }
    VAO1.Delete();
    VBO1.Delete();
    ShaderProgram.DeleteShader();
    glfwTerminate();
    return 0;
}