#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAPSIZE 256

// Game engine constants.
const double MOVESPEED = 0.0875;
const double ANGLESPEED = 0.0025625;
const double FOG = 20.0;
const double VERTICALFOV = 1.257;
const double DIST_TO_PROF_PLANE = 1.0; // Corrected from DIT_TO_PROJ_PLANE
const double FPS = 60;

// Useful struct typedefs.
typedef struct fVector2 {
    double x;
    double y;
} fVector2;

// Functions.
fVector2 distanceToWall(fVector2 playerPos, double playerA);
void readMap(fVector2* playerPos, double *playerA);
void playerMove(double dx, double dy);
bool handleEvents(SDL_Event e);
double veclen(fVector2 vec);
void drawScreen(SDL_Renderer* renderer, SDL_Texture* screen); // Corrected from SDL_Texture screen

// Screen dimension constants.
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Create player position.
fVector2 playerPos;
double playerA = 0.0;

// Define map globally -- a lot of functions care about it.
int map[MAPSIZE][MAPSIZE];

// Textures can be global as well.
SDL_Surface* wall_img_surf;

int main() {
    // This controls the main loop.
    bool quit = false; // Corrected from Quit

    // Initialize SDL.
    SDL_Init(SDL_INIT_VIDEO);

    // Create main window and renderer.
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);

    // Create a new texture representing the screen. We will draw on this.
    SDL_Texture* screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Grab mouse and setup event handler.
    SDL_SetRelativeMouseMode(SDL_TRUE);
    SDL_Event e;

    // Read in map from input.
    readMap(&playerPos, &playerA);

    // Load in wall texture image.
    wall_img_surf = SDL_LoadBMP("wall.bmp");
    if (wall_img_surf == NULL) {
        printf("Error Loading wall.bmp\n");
        exit(1);
    }

    // main loop.
    while(!quit) {
        // Get time at start of frame.
        Uint32 framestart = SDL_GetTicks();

        quit = handleEvents(e);
        drawScreen(renderer, screen);
        //SDL_UpdateWindowSurface(window);

        // Get time that frame took.
        Uint32 frameTime = SDL_GetTicks() - framestart;

        // wait until we hit 60 fps.
        Uint32 delayTime = 1000 / FPS - frameTime;
        //printf("%u\n", frameTime);
        if (delayTime > 1000 / FPS) delayTime = 0;
        SDL_Delay(delayTime);
    }

    // Destroy main screen texture.
    SDL_DestroyTexture(screen);

    // Destroy window.
    SDL_DestroyWindow(window);

    // Quit SDL subsystem.
    SDL_Quit();


    return EXIT_SUCCESS;
}


// Return the distance to the wall from the player by casting a ray.
fVector2 distanceToWall(fVector2 playerPos, double playerA) {
    const double raystep = 0.0150; // TO-DO: This should not be fixed-sized.
    // Ray dx and dy are calculated here.
    double dx = raystep * cos(playerA);
    double dy = raystep * sin(playerA);
    double distance = 0.0;

    fVector2 r;

    // Cast ray out from player.
    double x, y;
    for (x = playerPos.x, y = playerPos.y;
        x >= 0 && x < MAPSIZE && y >= 0 && y < MAPSIZE && !map[(int)round(x)][(int)round(y)];
        x += dx, y += dy) {
        distance += raystep;
        if (distance > 10000) {
            r.x = 10000.0;
            r.y = 0.0;
            return r; // Things too far away are set to be 'inf' away.
        }
            }


    /* Decide  wher we hit the wall. If an x or y value is very close to 
    0.5, it has just hit a wall, so we want the OTHER value. This is due
    to rounding, where 0.50 -> 1 and 0.49 -> 0. i.e. we just hit a wall
    The &dx is a dummy. The integral part is thrown away, but we need to
    store it somewhere to not throw a segfault */
    if (fabs(x - round(x)) > fabs(y - round(y)))
        r.y = modf(y, &dx);
    else
        r.y = modf(x, &dx);
    r.x = distance;

    return r;
}


/* Reads in the map from stdin. It sets the user position as well. */
void readMap(fVector2* playerPos, double *playerA) {
    // Zero out map to make sure no garbage is left.
    for (int i = 0; i < MAPSIZE; i++)
        for (int j = 0; j < MAPSIZE; j++)
            map[i][j] = 0;

    // Open map file for reading
    FILE* mapfile = fopen("map.txt", "r");
    if (mapfile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    // Read player starting x and y positions, as well as starting angle.
    char s[MAPSIZE] = { 0 };
    fgets(s, MAPSIZE, mapfile);
    playerPos->x = atof(s);
    fgets(s, MAPSIZE, mapfile);
    playerPos->y = atof(s);
    fgets(s, MAPSIZE, mapfile);
    *playerA = atof(s);

    // Read in map.
    for (int i = 0; fgets(s, MAPSIZE, mapfile) != NULL; i++) {
        char* token = strtok(s, ", ");
        for (int j = 0; token != NULL; j++) {
            map[j][i] = atoi(token);
            token = strtok(NULL, ", ");
        }
    }
    // Close map file.
    fclose(mapfile);
}

// Handles the events queue and keyboard state. Returns signal indicating if
// the user wishes to quit the program.
bool handleEvents(SDL_Event e) {
    // Handle events in the game.
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT)
            return true;
        if (e.type == SDL_MOUSEMOTION) {
            playerA += e.motion.xrel * ANGLESPEED;
        }
    }

    // Scan keyboard.
    const Uint8* currentKeyStates = SDL_GetKeyboardState(0);
    if (currentKeyStates[SDL_SCANCODE_ESCAPE])
        return true;

    if (currentKeyStates[SDL_SCANCODE_W]) {
        double dx = cos(playerA) * MOVESPEED;
        double dy = sin(playerA) * MOVESPEED;
        playerMove(dx, dy);
    }

    if (currentKeyStates[SDL_SCANCODE_S]) {
        double dx = cos(playerA) * MOVESPEED;
        double dy = sin(playerA) * MOVESPEED;
        playerMove(-dx, -dy);
    }

    if (currentKeyStates[SDL_SCANCODE_A]) {
        double dx = cos(playerA - 1.57) * MOVESPEED;
        double dy = sin(playerA - 1.57) * MOVESPEED;
        playerMove(dx, dy);
    }

    if (currentKeyStates[SDL_SCANCODE_D]) {
        double dx = cos(playerA + 1.57) * MOVESPEED;
        double dy = sin(playerA + 1.57) * MOVESPEED;
        playerMove(dx, dy);
    }

    return false;
}


void drawScreen(SDL_Renderer* renderer, SDL_Texture* screen) {
    // Each row has SCREEN WIDTH * 4 byte each for R, G, B, and A.
    void *pixels = NULL;
    int pitch;
    SDL_LockTexture(screen, NULL, &pixels, &pitch);

    // Draw the floor and ceiling.
    for (int y = 0; y < SCREEN_HEIGHT / 2; y++) {
        Uint8 color = 255.0 * 255.0 * ((float)y / (float)SCREEN_HEIGHT);
        Uint32 ceilColor = ((0 + color) << 8) + 255;
        Uint32 floorColor = ((0 + color) << 16) + 255;

        for (int x = 0; x < SCREEN_WIDTH; x++) {
            *(((Uint32*) pixels) + SCREEN_WIDTH * y + x) = ceilColor;
            *(((Uint32*) pixels) + SCREEN_WIDTH * (SCREEN_HEIGHT - 1) - y * SCREEN_WIDTH + x) = floorColor;
        }
    }

    // Draw the wall
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        double rayAngle = atan((x - SCREEN_WIDTH / 2.0) / (SCREEN_WIDTH / 2.0));
        double castAngle = playerA + rayAngle;
        fVector2 rayReturn = distanceToWall(playerPos, castAngle);

        double distance = cos(rayAngle) * rayReturn.x;
        Uint8 color = 255.0 * exp(-distance/FOG);

        int wallHeight = DIST_TO_PROF_PLANE / distance * SCREEN_HEIGHT;
        int actualWallHeight = wallHeight;
        wallHeight = (wallHeight > SCREEN_HEIGHT) ? SCREEN_HEIGHT : wallHeight;
        int wallY = (int) ((SCREEN_HEIGHT - wallHeight) / 2);

        double wallcoord = rayReturn.y;

        for (int y = wallY; y < wallHeight+wallY; y++) {
            int texture_x = 0;
            int texture_y = 0;
            if (distance > DIST_TO_PROF_PLANE) {
                texture_x = wallcoord * 127;
                texture_y = (y - wallY) / (float)wallHeight * 127;
            }
            else {
                texture_x = wallcoord * 127;
                texture_y = ((actualWallHeight - wallHeight) / 2.0 + y) / (float)actualWallHeight * 127;
            }

            Uint8 r = *(((Uint8*) (wall_img_surf->pixels)) + texture_y * 3*128 + 3*texture_x + 0);
            Uint8 g = *(((Uint8*) (wall_img_surf->pixels)) + texture_y * 3*128 + 3*texture_x + 1);
            Uint8 b = *(((Uint8*) (wall_img_surf->pixels)) + texture_y * 3*128 + 3*texture_x + 2);
            r *= color / 255.0;
            g *= color / 255.0;
            b *= color / 255.0;

            Uint32 wallColor = 0;
            wallColor = (((((b << 8) + g) << 8) + r) << 8) + 255;
            *(((Uint32*) pixels) + SCREEN_WIDTH * y + x) = wallColor;
        }
    }

    SDL_UnlockTexture(screen);
    SDL_RenderCopy(renderer, screen, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void playerMove(double dx, double dy) {
    if (dx + playerPos.x >= 0 && dx + playerPos.x < MAPSIZE && !map[(int)round(playerPos.x + dx)][(int)round(playerPos.y)])
        playerPos.x += dx;
    if (dy + playerPos.y >= 0 && dy + playerPos.y < MAPSIZE && !map[(int)round(playerPos.x)][(int)round(playerPos.y + dy)])
        playerPos.y += dy;
}

double veclen(fVector2 vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}
