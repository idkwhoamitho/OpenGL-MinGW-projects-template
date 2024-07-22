#include "VAO.h"

VAO::VAO()
{
    glGenVertexArrays(1, &ID);
}

void VAO::LinkVBO(VBO VBO, GLuint Layout)
{
    VBO.Bind();
    glVertexAttribPointer(Layout, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(Layout);
    VBO.Unbind();
}

void VAO::bind()
{
    glBindVertexArray(ID);
}
void VAO::Unbind()
{
    glBindVertexArray(0);

}

void VAO::Delete()
{
    glDeleteVertexArrays(1, &ID);
}

VAO::~VAO()
{

}
