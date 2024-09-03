#include "Entity.hpp"

Entity::Entity(float x, float y, float w, float h, float gravityValue, float move)
    : velocityY(0), gravity(gravityValue), move(move) {
    rect = { x, y, w, h };
}

void Entity::applyGravity(int screenHeight) {
    velocityY += gravity;
    rect.y += velocityY;

    // If the entity reaches the bottom of the screen, reset it to the top
    if (rect.y >= screenHeight) {
        resetPosition(screenHeight);
    }
}

void Entity::resetPosition(int screenHeight) {
    rect.y = -rect.h;  // Start falling from above the screen
    velocityY = 0;  // Reset velocity for consistent falling
}

void Entity::control(const Uint8* state) {
    if (rect.y > 0 && rect.y < SCREEN_HEIGHT - rect.h && rect.x > 0 && rect.x < SCREEN_WIDTH - rect.w) {
        if (state != NULL) {
            if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
                rect.y += -move;
            }
            if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) {
                rect.y += move;
            }
            if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
                rect.x += -move;
            }
            if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
                rect.x += move;
            }
        }
    }
}

void Entity::collide(const Uint8* state) {
    if (rect.y > 0 && rect.y < SCREEN_HEIGHT - rect.h && rect.x > 0 && rect.x < SCREEN_WIDTH - rect.w) {
        if (state != NULL) {
            if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
                rect.y += move;
            }
            if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) {
                rect.y += -move;
            }
            if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
                rect.x += move;
            }
            if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
                rect.x += -move;
            }
        }
    }
}

void Entity::movement() {
    rect.y += move * 0;
}