#pragma once

#include <string>
#include "simple_draw_gl/shader/shader.h"
#include "simple_draw_gl/shader/program.h"

namespace simple_draw_gl {
namespace shader {

    Shader defaultVertexShader();
    Shader defaultFragmentShader();
    Program defaultProgram();

    std::string defaultVertexShaderCode();
    std::string defaultFragmentShaderCode();

}
}
