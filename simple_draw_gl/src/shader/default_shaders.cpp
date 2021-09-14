#include "simple_draw_gl/shader/default_shaders.h"

namespace simple_draw_gl {
namespace shader {

    Shader defaultVertexShader()
    {
        return Shader(Shader::ShaderType::Vertex, "default", defaultVertexShaderCode());
    }

    Shader defaultFragmentShader()
    {
        return Shader(Shader::ShaderType::Fragment, "default", defaultFragmentShaderCode());
    }
    
    Program defaultProgram()
    {
        return Program("default", {defaultVertexShader(), defaultFragmentShader()});
    }

    std::string defaultVertexShaderCode()
    {
        // https://github.com/opengl-tutorials/ogl/blob/master/tutorial04_colored_cube/TransformVertexShader.vertexshader        
        return 
        "#version 330 core                                                   \n"
        "                                                                    \n"
        "// Input vertex data, different for all executions of this shader.  \n"
        "layout(location = 0) in vec3 vertexPosition_modelspace;             \n"
        "layout(location = 1) in vec3 vertexColor;                           \n"
        "                                                                    \n"
        "// Output data ; will be interpolated for each fragment.            \n"
        "out vec3 fragmentColor;                                             \n"
        "// Values that stay constant for the whole mesh.                    \n"
        "uniform mat4 projection_view_model;                                 \n"
        "                                                                    \n"
        "void main(){                                                        \n"
        "                                                                    \n"
        "    // Output position of the vertex, in clip space : projection_view_model * position \n"
        "    gl_Position =  projection_view_model * vec4(vertexPosition_modelspace,1);          \n"
        "                                                                    \n"
        "    // The color of each vertex will be interpolated                \n"
        "    // to produce the color of each fragment                        \n"
        "    fragmentColor = vertexColor;                                    \n"
        "}                                                                   \n"
        ;
    }

    std::string defaultFragmentShaderCode()
    {
        // https://github.com/opengl-tutorials/ogl/blob/master/tutorial04_colored_cube/ColorFragmentShader.fragmentshader
        return 
        "#version 330 core                                           \n"
        "                                                            \n"
        "// Interpolated values from the vertex shaders              \n"
        "in vec3 fragmentColor;                                      \n"
        "                                                            \n"
        "// Ouput data                                               \n"
        "out vec3 color;                                             \n"
        "                                                            \n"
        "void main(){                                                \n"
        "                                                            \n"
        "    // Output color = color specified in the vertex shader, \n"
        "    // interpolated between all 3 surrounding vertices      \n"
        "    color = fragmentColor;                                  \n"
        "                                                            \n"
        "}                                                           \n"
        ;
    }

}
}