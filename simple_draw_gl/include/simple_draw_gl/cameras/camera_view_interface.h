#pragma once

#include <glm/glm.hpp>

namespace simple_draw_gl {
namespace cameras {

    class CameraViewInterface
    {
    public:
        CameraViewInterface(){}
        virtual ~CameraViewInterface(){}
        glm::mat4 mat() const { return *this; }
        virtual operator glm::mat4() const = 0;
    };

} // namespace cameras
} // namespace simple_draw_gl
