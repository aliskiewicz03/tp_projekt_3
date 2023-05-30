#include "planar_quadrotor_visualizer.h"
#include <cmath>
#include <time.h>
#include<random>

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor* quadrotor_ptr) : quadrotor_ptr(quadrotor_ptr) {}

void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer>& gRenderer) {
    Eigen::VectorXf state = quadrotor_ptr->GetState();

    std::uniform_real_distribution<float> y_distribution(-1.0f, 1.0f);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    double randomValue = dist(gen);

    float q_x, q_y, q_theta;

    /* x, y, theta coordinates */
    q_x = state[0];
    q_y = state[1];
    q_theta = state[2];



    int screenWidth, screenHeight;
    SDL_GetRendererOutputSize(gRenderer.get(), &screenWidth, &screenHeight);
    int middle_x = screenWidth / 2;
    int middle_y = screenHeight / 2;
    int circleX = middle_x + static_cast<int>(q_x);
    int circleY = middle_y + static_cast<int>(q_y+ randomValue);

    // main rectangle
    SDL_Rect main_rectangle = {circleX - 80, circleY - 20, 160, 40};
    SDL_SetRenderDrawColor(gRenderer.get(), 0xF5, 0x28, 0x91, 0xCC);
    SDL_RenderFillRect(gRenderer.get(), &main_rectangle);

    // left and right rectangles
    SDL_Rect left_rectangle = {circleX - 65, circleY - 80, 15, 60};
    SDL_Rect right_rectangle = {circleX + 50, circleY - 80, 15, 60};
    SDL_SetRenderDrawColor(gRenderer.get(), 0xBC, 0x83, 0xA3, 0xB3);
    SDL_RenderFillRect(gRenderer.get(), &left_rectangle);
    SDL_RenderFillRect(gRenderer.get(), &right_rectangle);

    // propellers
    SDL_Rect propeller1 = {circleX - 80, circleY - 80, 50, 10};
    SDL_Rect propeller2 = {circleX + 35, circleY - 80, 50, 10};
    SDL_RenderFillRect(gRenderer.get(), &propeller1);
    SDL_RenderFillRect(gRenderer.get(), &propeller2);

}
