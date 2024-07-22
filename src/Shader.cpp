#include "Shader.h"


std::string Shader::ReadFile(std::string filePath)
{
   const char* file = filePath.c_str();
   std::ifstream in(file, std::ios::binary);
   if(in)
   {
        std::string contens;
        in.seekg(0, std::ios::end);
        contens.resize(in.tellg());
        in.seekg(0, std::ios::beg);            
        in.read(&contens[0],contens.size());
        in.close();
        return contens;
   }
   else{
    std::cerr << "[Shader] error reading file: no such file" << std::endl;
    throw errno;
   }
}


Shader::Shader(const char* vertexShaderFilePath, const char* fragmentShaderFilePath)
{
    std::string vertexShadersSource = ReadFile(vertexShaderFilePath);
    std::string fragmentShadersSource = ReadFile(fragmentShaderFilePath);

    const char* vertexSource =  vertexShadersSource.c_str();
    const char* fragmentSource = fragmentShadersSource.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);

    glLinkProgram(ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::UseProgram()
{
    glUseProgram(ID);
}

void Shader::DeleteShader()
{
    glDeleteProgram(ID);
}


Shader::~Shader()
{
}
