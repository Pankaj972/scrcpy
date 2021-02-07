#ifndef SC_FRAME_TEXTURE_H
#define SC_FRAME_TEXTURE_H

#include "common.h"

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <libavformat/avformat.h>

#include "coords.h"
#include "opengl.h"

struct sc_frame_texture {
    SDL_Renderer *renderer; // owned by struct screen

    bool mipmaps;
    struct sc_opengl gl;

    SDL_Texture *texture;
    struct size texture_size;
};

bool
sc_frame_texture_init(struct sc_frame_texture *ftex, SDL_Renderer *renderer,
                      bool mipmaps, struct size initial_size);

void
sc_frame_texture_destroy(struct sc_frame_texture *ftex);

bool
sc_frame_texture_update(struct sc_frame_texture *ftex, const AVFrame *frame);

#endif
