#pragma once

#include "simple_draw_gl/drawing/drawable.h"

namespace simple_draw_gl {
namespace drawing {

    class Grid : public Drawable
    {
    public:
        Grid() {}
        virtual ~Grid() {}

        void setup() override
        {}
        void draw() override
        {}
    };

} // namespace drawing
} // namespace simple_draw_gl
