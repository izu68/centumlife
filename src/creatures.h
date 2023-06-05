#pragma once

#include "psx.h"
#include "sprite.h"
#include "mesh.h"

typedef struct {
    Sprite spr;
} creatures;
extern creatures creature[100];

void make_them_move (void);