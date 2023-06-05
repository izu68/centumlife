#pragma once

#include "psx.h"
#include "sprite.h"
#include "mesh.h"
#include "state"

typedef struct {
    Sprite floor;
} struct_satus;
extern struct_satus satus;

void load_satus (void);
void update_satus (void);