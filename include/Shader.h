#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H
#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <string>


class Shader
{
private:
    /* data */
public:
    GLuint ID;
    Shader(const char* vertexShaderFilePath, const char* fragmentShaderFilePath); 
    std::string ReadFile(std::string filePath);
    void UseProgram();
    void DeleteShader();
    ~Shader();
};





#endif
