#pragma once

#include <string>
#include <vector>
#include <utility>
#include "simple_draw_gl/imgui_gl.h"
#include "simple_draw_gl/shader/program.h"
#include "simple_draw_gl/shader/default_shaders.h"
#include "simple_draw_gl/shader/program_uniform.h"

namespace simple_draw_gl {
namespace shader {

    struct DefaultProgram : public Program
    {
        DefaultProgram()
            : Program("Default", {defaultVertexShader(), defaultFragmentShader()})
        {}
        void setup() override
        {
            m_shaders[0].setup();
            m_shaders[1].setup();
            Program::setup();
            projection_view_model.init(getGlProgram(), "projection_view_model");
        }
        ProgramUniform<glm::mat4> projection_view_model;
    };


} // namespace shader
} // namespace simple_draw_gl
