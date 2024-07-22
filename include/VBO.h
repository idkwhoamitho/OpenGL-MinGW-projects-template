#ifndef VBO_CLASS_H
#define VBO_CLASS_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VBO
{
private:
    /* data */
public:
    GLuint ID;
    VBO(float* vertices, GLsizeiptr sizeVert);
    void Bind();
    void Unbind();
    void Delete();
    
    ~VBO();
};
#endif //VBO_CLASS_H
