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
    const int l = 150, h = 20;
    Sint16 vx[4];
    Sint16 vy[4];
    Sint16 vz[4];
    Sint16 vx_1[4];
    Sint16 vy_1[4];
    /* x, y, theta coordinates */
    q_x = state[0];
    q_y = state[1];
    q_theta = state[2];
    x1 = q_x + cos(q_theta)*(l/2);
    x2 = q_x - cos(q_theta)*(l/2);
    y1 = q_y - sin(q_theta)*(l/2);
    y2 = q_y + sin(q_theta)*(l/2);
    vx[0] = x1 - sin(q_theta)*(h/2);
    vx[1] = x1 + sin(q_theta)*(h/2);
    vx[2] = x2 + sin(q_theta)*(h/2);
    vx[3] = x2 - sin(q_theta)*(h/2);
    vy[0] = y1 - cos(q_theta)*(h/2);
    vy[1] = y1 + cos(q_theta)*(h/2);
    vy[2] = y2 + cos(q_theta)*(h/2);
    vy[3] = y2 - cos(q_theta)*(h/2);

   vx_1[0]=x1+20*cos(q_theta);
   vy_1[0]=y1-20*sin(q_theta);
   vx_1[1]=x1+30*cos(q_theta);
   vy_1[1]=y1-30*sin(q_theta);
   vx_1[2]=vx_1[0]-70*sin(q_theta);
   vy_1[2]=vy_1[0]-70*cos(q_theta);
   vx_1[3]=vx_1[1]-70*sin(q_theta);
   vy_1[3]=vy_1[1]-70*sin(q_theta);






    SDL_SetRenderDrawColor(gRenderer.get(), 0xFF, 0x00, 0x00, 0xFF);
    //filledCircleColor(gRenderer.get(), q_x, q_y, 30, 0xFF0000FF);
    filledPolygonColor(gRenderer.get(), vx, vy, 4, 0xFFFFFF00);
    //filledCircleColor(gRenderer.get(), x1, y1, 30, 0xFF0000FF);
    //filledCircleColor(gRenderer.get(), x2, y2, 30, 0xFF0000FF);

}
