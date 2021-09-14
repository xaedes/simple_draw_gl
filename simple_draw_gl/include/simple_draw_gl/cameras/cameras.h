#pragma once

#include "simple_draw_gl/cameras/camera.h"
#include "simple_draw_gl/cameras/first_person_view.h"
#include "simple_draw_gl/cameras/look_at_view.h"
#include "simple_draw_gl/cameras/orbital_view.h"
#include "simple_draw_gl/cameras/perspective_projection.h"

namespace simple_draw_gl {
namespace cameras {

    using FirstPersonPerspectiveCamera = Camera<PerspectiveProjection, FirstPersonView>;
    using LookAtPerspectiveCamera = Camera<PerspectiveProjection, LookAtView>;
    using OrbitalPerspectiveCamera = Camera<PerspectiveProjection, OrbitalView>;

} // namespace cameras
} // namespace simple_draw_gl
