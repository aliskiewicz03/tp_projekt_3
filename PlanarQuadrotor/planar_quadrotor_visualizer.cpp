#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor* quadrotor_ptr) : quadrotor_ptr(quadrotor_ptr) {}

void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer>& gRenderer) {
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    float q_x, q_y, q_theta;

    /* x, y, theta coordinates */
    q_x = state[0];
    q_y = state[1];
    q_theta = state[2];

    int screenWidth, screenHeight;
    SDL_GetRendererOutputSize(gRenderer.get(), &screenWidth, &screenHeight);
    int middle_x = screenWidth / 2;
    int middle_y = screenHeight / 2;

    // 1. Transform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen
    int circleX = middle_x + static_cast<int>(q_x);
    int circleY = middle_y + static_cast<int>(q_y);
    // 2. Use more shapes to represent quadrotor
    // Circle representing the quadrotor body

    // Rectangles representing the arms of the quadrotor
    SDL_SetRenderDrawColor(gRenderer.get(), 0x00, 0x00, 0xFF, 0xFF);
    SDL_Rect main_rectangle = {circleX - 80, circleY - 20, 160, 40};
    SDL_Rect left_rectangle = {circleX - 95, circleY - 80, 15, 100};
    SDL_Rect right_rectangle = {circleX + 80, circleY - 80, 15, 100};
    SDL_RenderFillRect(gRenderer.get(), &main_rectangle);
    SDL_RenderFillRect(gRenderer.get(), &left_rectangle);
    SDL_RenderFillRect(gRenderer.get(), &right_rectangle);

    // 3. Animate propellers (extra points)
    SDL_SetRenderDrawColor(gRenderer.get(), 0x00, 0xFF, 0x00, 0xFF);
    int propellerSize = 20;
    int propellerOffset = 50;

    // Render rotating propellers
    SDL_Rect propeller1 = {circleX - 70, circleY - propellerOffset, propellerSize, propellerSize};
    SDL_RenderFillRect(gRenderer.get(), &propeller1);

    SDL_Rect propeller2 = {circleX - 70, circleY + propellerOffset - propellerSize, propellerSize, propellerSize};
    SDL_RenderFillRect(gRenderer.get(), &propeller2);

    SDL_Rect propeller3 = {circleX + 50, circleY - propellerOffset, propellerSize, propellerSize};
    SDL_RenderFillRect(gRenderer.get(), &propeller3);

    SDL_Rect propeller4 = {circleX + 50, circleY + propellerOffset - propellerSize, propellerSize, propellerSize};
    SDL_RenderFillRect(gRenderer.get(), &propeller4);
}
