#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>
#include "defs.hpp"

class Entity {
public:
    SDL_FRect rect;
    float velocityY;  // Vertical velocity
    float gravity;    // Gravity value
    float move; //Movement value, allows game to change how much movement there is, 0 for non-controllable entities. Also determines the step size of steps in movement

    Entity(float x, float y, float w, float h, float gravityValue, float moveMult);

    // Apply gravity to the entity
    void applyGravity(int screenHeight);

    // Reset the entity position when it reaches the bottom
    void resetPosition(int screenHeight);

    // Turns keyboard state into a movement
    void control(const Uint8* state);

    // Handles collisions for controllable entities
    void collide(const Uint8* state);

    // Handles movement for non-controllable entities
    void movement();
};

#endif