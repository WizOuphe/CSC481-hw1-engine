#include "main.hpp"
#include <memory>

int main(int argc, char* argv[]) {
	initSDL();

	Entity solidRect(300, 300, 100, 100, 0, 0);  // Static solid shape
	Entity controllableRect(500, 500, 50, 50, 0, 10);  // Controllable shape

	// Gravity applied to an entity for continuous falling
	Entity fallingRect((SCREEN_WIDTH - 50) / 2, -50, 50, 50, 0.005f, 0);

	Entity movingRect(1500, 500, 100, 200, 0, 5);

	while (1) {
		prepareScene();

		const Uint8* state = doInput();

		controllableRect.control(state);

		//movingRect.movement();

		// Section 3: Apply gravity to fallingRect for continuous falling
		fallingRect.applyGravity(SCREEN_HEIGHT);

		// Section 5: Check collision
		if (SDL_HasIntersectionF(&controllableRect.rect, &solidRect.rect)) {
			controllableRect.collide(state);
		}
		if (SDL_HasIntersectionF(&controllableRect.rect, &movingRect.rect)) {
			controllableRect.collide(state);
		}
		if (SDL_HasIntersectionF(&controllableRect.rect, &fallingRect.rect)) {
			controllableRect.collide(state);
		}

		// Render the solid static shape
		SDL_SetRenderDrawColor(app->renderer, 255, 0, 0, 255);  // Red color
		SDL_RenderFillRectF(app->renderer, &solidRect.rect);

		// Render the controllable shape
		SDL_SetRenderDrawColor(app->renderer, 0, 255, 0, 255);  // Green color
		SDL_RenderFillRectF(app->renderer, &controllableRect.rect);

		// Render the falling shape
		SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 255);  // Black color
		SDL_RenderFillRectF(app->renderer, &fallingRect.rect);

		// Render the moving shape
		SDL_SetRenderDrawColor(app->renderer, 255, 0, 255, 255);  // Purple color
		SDL_RenderFillRectF(app->renderer, &movingRect.rect);

		presentScene();

		SDL_Delay(16);
	}

	return 0;
}