#ifndef VAO_CLASS_H
#define VAO_CLASS_H
#include <glad/glad.h>
#include "VBO.h"

class VAO
{
private:
    /* data */
public:
    GLuint ID;
    VAO(/* args */);
    void LinkVBO(VBO VBO, GLuint Layout);
    void bind();
    void Unbind();
    void Delete();
    ~VAO();
};





#endif