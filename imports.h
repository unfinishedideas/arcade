#pragma once

// System ----------------------|
#include <iostream>
#include <stdio.h>
#include <cstring>

// SDL -------------------------|
#include <SDL.h>
#include <SDL_image.h>

// Constants -------------------|
//Uint32 CHROMA_VALUE = SDL_MapRGB(NULL, 255, 0, 255);
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Classes ---------------------|
#include "Texture.h"

#define WITH_SDL2
#include "soloud.h"
#include "soloud_wav.h"
