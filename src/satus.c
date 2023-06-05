#include "satus.h"
#include "creatures.h"

struct_satus satus;

void load_satus (void) {
    cd_open();
	cd_read_file("GRASS.TIM", &cd_data[0]);
	cd_read_file("CREATURS.TIM", &cd_data[1]);
	cd_close();

	//audio_init();
	//audio_vag_to_spu((u_char *)cd_data[0], SECTOR * 21, SPU_00CH);
	//audio_play(SPU_00CH);

	sprite_init(&satus.floor, 128, 128, (u_char *)cd_data[0]);
	sprite_setuv(&satus.floor, 0, 0, 128, 128);
	grass.angX = 900;

	sprite_init(&creature[0].spr, 32, 32, (u_char *)cd_data[1]);
	sprite_setuv(&creature[0].spr, 0, 0, 32, 32);
	//flowerboy.posX = 50; flowerboy.posY = 50;
			
	setRGB0(&drawenv[0], 0, 51, 255);
	setRGB0(&drawenv[1], 0, 51, 255);

	free3(cd_data);
}

void update_satus (void) {
    sprite_draw(&satus.floor);
	sprite_draw (&creature[0].spr);	
}