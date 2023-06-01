#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr): quadrotor_ptr(quadrotor_ptr) {}

/**
 * TODO: Improve visualizetion
 * 1. Transform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen
 * 2. Use more shapes to represent quadrotor (e.x. try replicate http://underactuated.mit.edu/acrobot.html#section3 or do something prettier)
 * 3. Animate proppelers (extra points)
 */
void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer> &gRenderer) {
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    float q_x, q_y, q_theta, x1, x2, y1, y2;
    const int l = 160, h = 30;
    Sint16 v_x[4];
    Sint16 v_y[4];
    /* x, y, theta coordinates */
    q_x = state[0];
    q_y = state[1];
    q_theta = state[2];
    x1 = q_x + cos(q_theta)*(l/2);
    x2 = q_x - cos(q_theta)*(l/2);
    y1 = q_y - sin(q_theta)*(l/2);
    y2 = q_y + sin(q_theta)*(l/2);
    v_x[0] = x1 - sin(q_theta)*(h/2);
    v_x[1] = x1 + sin(q_theta)*(h/2);
    v_x[2] = x2 + sin(q_theta)*(h/2);
    v_x[3] = x2 - sin(q_theta)*(h/2);
    v_y[0] = y1 - cos(q_theta)*(h/2);
    v_y[1] = y1 + cos(q_theta)*(h/2);
    v_y[2] = y2 + cos(q_theta)*(h/2);
    v_y[3] = y2 - cos(q_theta)*(h/2);

    SDL_SetRenderDrawColor(gRenderer.get(), 0xF5, 0x28, 0x91, 0xCC);
    filledPolygonColor(gRenderer.get(), v_x, v_y, 4, 0xF52891CC);
}
