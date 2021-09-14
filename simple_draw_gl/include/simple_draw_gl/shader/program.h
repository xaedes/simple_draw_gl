#pragma once

#include <string>
#include <vector>
#include <utility>
#include "simple_draw_gl/imgui_gl.h"
#include "simple_draw_gl/shader/shader.h"

namespace simple_draw_gl {
namespace shader {

    struct Program
    {
        Program()
            : Program("", {})
        {}
        Program(const Program& other)
            : m_name(other.getName())
            , m_glProgram(other.getGlProgram())
            , m_shaders(other.getShaders())
            , m_valid(other.isValid())
        {}        
        Program(const std::vector<Shader>& shaders)
            : Program("", shaders)
        {}
        Program(const std::string& name, const std::vector<Shader>& shaders={})
            : m_name(name)
            , m_shaders(shaders)
            , m_valid(false)
        {}

        virtual void setup()
        {
            m_valid = false;
            m_glProgram = glCreateProgram();
            if (m_glProgram != 0)
            {
                m_valid = Link(getGlProgram(), getShaders());
                if (!m_valid)
                {
                    printSourceWithLineNumbers();
                }
            }
            else
            {
                throw std::runtime_error("could not glCreateProgram");
            }
        }

        bool isValid() const { return m_valid; }
        GLuint getGlProgram() const { return m_glProgram; }
        const std::string& getName() const { return m_name; }
        const std::vector<Shader>& getShaders() const { return m_shaders; }

        virtual Program& use()
        {
            glUseProgram(getGlProgram());
            return *this;
        }

        void printSourceWithLineNumbers() const
        {
            for (const auto& shader : getShaders())
            {
                std::cout << "Shader (type=" << Shader::TypeString(shader.getType()) << ") '" << shader.getName() << "'" << std::endl;
                shader.printSourceWithLineNumbers();
            }
        }

        static bool Link(GLuint programId, const std::vector<Shader>& shaders)
        {
            for (int i = 0; i < shaders.size(); ++i)
            {
                glAttachShader(programId, shaders[i].getGlShader());
            }
            glLinkProgram(programId);

            GLchar infolog[512];
            glGetProgramInfoLog(programId, 512, nullptr, infolog);
            if (infolog[0] != '\0') 
            {
                std::cout << "Error linking shaders into program! " << std::endl;
                std::cout << infolog << std::endl;
                return false;
            }
            return true;
        }


    protected:
        bool m_valid;
        GLuint m_glProgram;

        std::string m_name;
        std::vector<Shader> m_shaders;
    };


} // namespace shader
} // namespace simple_draw_gl
