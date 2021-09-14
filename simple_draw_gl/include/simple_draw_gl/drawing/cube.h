#pragma once

#include <array>
#include <glm/glm.hpp>
#include "simple_draw_gl/drawing/drawable.h"

namespace simple_draw_gl {
namespace drawing {

    class Cube : public Drawable
    {
    public:
        Cube() : Cube(glm::vec3(0,0,0), 0) {}
        Cube(glm::vec3 position, float size) 
        {

        }

        virtual ~Cube() {}

        void setup() override
        {
            glGenVertexArrays(1, &m_vertexArray);
            glBindVertexArray(m_vertexArray);

            // This will identify our vertex buffer
            // Generate 1 buffer, put the resulting identifier in vertexbuffer
            glGenBuffers(1, &m_vertexBuffer);
            // The following commands will talk about our 'vertexbuffer' buffer
            glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
            // Give our vertices to OpenGL.
            glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertexBufferData), m_vertexBufferData, GL_STATIC_DRAW);

            // This will identify our vertex buffer
            // Generate 1 buffer, put the resulting identifier in vertexbuffer
            glGenBuffers(1, &m_colorBuffer);
            // The following commands will talk about our 'vertexbuffer' buffer
            glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer);
            // Give our vertices to OpenGL.
            glBufferData(GL_ARRAY_BUFFER, sizeof(m_colorBufferData), m_colorBufferData, GL_STATIC_DRAW);

            // 1st attribute buffer : vertices
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
            glVertexAttribPointer(
               0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
               3,                  // size
               GL_FLOAT,           // type
               GL_FALSE,           // normalized?
               0,                  // stride
               (void*)0            // array buffer offset
            );
            glEnableVertexAttribArray(1);
            glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer);
            glVertexAttribPointer(
               1,                  // attribute 1. No particular reason for 1, but must match the layout in the shader.
               3,                  // size
               GL_FLOAT,           // type
               GL_FALSE,           // normalized?
               0,                  // stride
               (void*)0            // array buffer offset
            );
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);

        }
        void draw() override
        {
            glBindVertexArray(m_vertexArray);
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
            glVertexAttribPointer(
               0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
               3,                  // size
               GL_FLOAT,           // type
               GL_FALSE,           // normalized?
               0,                  // stride
               (void*)0            // array buffer offset
            );
            glEnableVertexAttribArray(1);
            glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer);
            glVertexAttribPointer(
               1,                  // attribute 1. No particular reason for 1, but must match the layout in the shader.
               3,                  // size
               GL_FLOAT,           // type
               GL_FALSE,           // normalized?
               0,                  // stride
               (void*)0            // array buffer offset
            );
            glDrawArrays(GL_TRIANGLES, 0, 12*3); 
            glDisableVertexAttribArray(0);
            glDisableVertexAttribArray(1);            
        }
    protected:
        GLuint m_vertexArray;
        GLuint m_vertexBuffer;
        GLuint m_colorBuffer;

        // http://www.opengl-tutorial.org/beginners-tutorials/tutorial-4-a-colored-cube/
        // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
        // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
        static constexpr GLfloat m_vertexBufferData[] = {
            -1.0f, -1.0f, -1.0f, // triangle 1 : begin
            -1.0f, -1.0f, +1.0f,
            -1.0f, +1.0f, +1.0f, // triangle 1 : end
            +1.0f, +1.0f, -1.0f, // triangle 2 : begin
            -1.0f, -1.0f, -1.0f,
            -1.0f, +1.0f, -1.0f, // triangle 2 : end
            +1.0f, -1.0f, +1.0f,
            -1.0f, -1.0f, -1.0f,
            +1.0f, -1.0f, -1.0f,
            +1.0f, +1.0f, -1.0f,
            +1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f, -1.0f,
            -1.0f, +1.0f, +1.0f,
            -1.0f, +1.0f, -1.0f,
            +1.0f, -1.0f, +1.0f,
            -1.0f, -1.0f, +1.0f,
            -1.0f, -1.0f, -1.0f,
            -1.0f, +1.0f, +1.0f,
            -1.0f, -1.0f, +1.0f,
            +1.0f, -1.0f, +1.0f,
            +1.0f, +1.0f, +1.0f,
            +1.0f, -1.0f, -1.0f,
            +1.0f, +1.0f, -1.0f,
            +1.0f, -1.0f, -1.0f,
            +1.0f, +1.0f, +1.0f,
            +1.0f, -1.0f, +1.0f,
            +1.0f, +1.0f, +1.0f,
            +1.0f, +1.0f, -1.0f,
            -1.0f, +1.0f, -1.0f,
            +1.0f, +1.0f, +1.0f,
            -1.0f, +1.0f, -1.0f,
            -1.0f, +1.0f, +1.0f,
            +1.0f, +1.0f, +1.0f,
            -1.0f, +1.0f, +1.0f,
            +1.0f, -1.0f, +1.0f
        };
        static constexpr GLfloat m_colorBufferData[] = {
             0.0f,  0.0f,  0.0f, // triangle 1 : begin
             0.0f,  0.0f, +1.0f,
             0.0f, +1.0f, +1.0f, // triangle 1 : end
            +1.0f, +1.0f,  0.0f, // triangle 2 : begin
             0.0f,  0.0f,  0.0f,
             0.0f, +1.0f,  0.0f, // triangle 2 : end
            +1.0f,  0.0f, +1.0f,
             0.0f,  0.0f,  0.0f,
            +1.0f,  0.0f,  0.0f,
            +1.0f, +1.0f,  0.0f,
            +1.0f,  0.0f,  0.0f,
             0.0f,  0.0f,  0.0f,
             0.0f,  0.0f,  0.0f,
             0.0f, +1.0f, +1.0f,
             0.0f, +1.0f,  0.0f,
            +1.0f,  0.0f, +1.0f,
             0.0f,  0.0f, +1.0f,
             0.0f,  0.0f,  0.0f,
             0.0f, +1.0f, +1.0f,
             0.0f,  0.0f, +1.0f,
            +1.0f,  0.0f, +1.0f,
            +1.0f, +1.0f, +1.0f,
            +1.0f,  0.0f,  0.0f,
            +1.0f, +1.0f,  0.0f,
            +1.0f,  0.0f,  0.0f,
            +1.0f, +1.0f, +1.0f,
            +1.0f,  0.0f, +1.0f,
            +1.0f, +1.0f, +1.0f,
            +1.0f, +1.0f,  0.0f,
             0.0f, +1.0f,  0.0f,
            +1.0f, +1.0f, +1.0f,
             0.0f, +1.0f,  0.0f,
             0.0f, +1.0f, +1.0f,
            +1.0f, +1.0f, +1.0f,
             0.0f, +1.0f, +1.0f,
            +1.0f,  0.0f, +1.0f
        };
    };

} // namespace drawing
} // namespace simple_draw_gl
