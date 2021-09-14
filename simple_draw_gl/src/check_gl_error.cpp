#include "simple_draw_gl/imgui_gl.h"
#include "simple_draw_gl/check_gl_error.h"

#include <iostream> 


namespace simple_draw_gl {

    void checkGLError()
    {
        GLenum err;
        bool hasError = false;
        while ((err = glGetError()) != GL_NO_ERROR) {
            std::cout << err;
            hasError = true;
        }
        if (hasError)
            throw std::runtime_error("Open GL Error");
    }

} // namespace simple_draw_gl
