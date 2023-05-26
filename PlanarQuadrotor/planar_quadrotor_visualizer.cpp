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
    float q_x, q_y, q_theta;

    /* x, y, theta coordinates */
    q_x = state[0];
    q_y = state[1];
    q_theta = state[2];

    int screenWidth, screenHeight;
    SDL_GetRendererOutputSize(gRenderer.get(), &screenWidth, &screenHeight);
    int middle_x=screenWidth/2;
    int middle_y=screenHeight/2;
    SDL_SetRenderDrawColor(gRenderer.get(), 0xFF, 0x00, 0x00, 0xFF);

    int circleX = middle_x + static_cast<int>(q_x);
    int circleY = middle_y + static_cast<int>(q_y);

   filledCircleColor(gRenderer.get(), circleX, circleY, 30, 0x43FF64FF);
   SDL_Rect main_rectangle = {q_x , q_y, 160, 40};
   SDL_Rect left_rectangle = {q_x - 80, q_y, 15, 60};
   SDL_Rect right_rentangle = {q_x + 80, q_y, 15, 60};
}
