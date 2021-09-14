#pragma once

namespace simple_draw_gl {
namespace drawing {

    class Drawable
    {
    public:
        Drawable() {}
        virtual ~Drawable() {}

        virtual void setup() {}
        virtual void draw() {}
    };

} // namespace drawing
} // namespace simple_draw_gl
