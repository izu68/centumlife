#include "psx.h"
#include "sprite.h"
#include "mesh.h"
#include "state.h"

long cameraX = 0;
long cameraY = 820;
long cameraZ = 1500;

void update()
{
	if(pad & PADLup){
    	//player.posZ += 5;
    	cameraZ -= 5;
    }
    if(pad & PADLdown){
    	//player.posZ -= 5;
    	cameraZ += 5;
    }
    if(pad & PADLleft){
    	//player.posX -= 5;
    	cameraX += 5;
    }
    if(pad & PADLright){
    	//player.posX += 5;
    	cameraX -= 5;
    }

	if (pad & PADL2) {
		cameraY += 2;
	}
	if (pad & PADR2) {
		cameraY -= 2;
	}
}

int main() {
	psSetup();

	Sprite flowerboy;
	Sprite grass;
	
	game_state = LOAD_FIELD;
	
	while(1) {
		psClear();
		psCamera(cameraX, cameraY, cameraZ, 300, 0, 0);
		update();
		FntPrint ("GRASS X ANG: %d\n", grass.angX);
		FntPrint ("GRASS Y ANG: %d\n", grass.angY);
		FntPrint ("GRASS Z ANG: %d\n", grass.angZ);

		switch (game_state){
		case LOAD_FIELD:
			cd_open();
			cd_read_file("CLACK.VAG", &cd_data[0]);
			cd_read_file("REDCAT.TIM", &cd_data[1]);
			cd_read_file("GRASS.TIM", &cd_data[3]);
			cd_read_file("CREATURS.TIM", &cd_data[2]);
			cd_close();

			audio_init();
			audio_vag_to_spu((u_char *)cd_data[0], SECTOR * 21, SPU_00CH);
			audio_play(SPU_00CH);

			sprite_init(&grass, 128, 128, (u_char *)cd_data[3]);
			sprite_setuv(&grass, 0, 0, 128, 128);
			grass.angX = 900;

			sprite_init(&flowerboy, 32, 32, (u_char *)cd_data[2]);
			sprite_setuv(&flowerboy, 0, 0, 32, 32);
			//flowerboy.posX = 50; flowerboy.posY = 50;
			
			setRGB0(&drawenv[0], 0, 51, 255);
			setRGB0(&drawenv[1], 0, 51, 255);

			free3(cd_data);

			game_state = FIELD;
			break;
		
		case FIELD:
			sprite_draw(&grass);
			sprite_draw (&flowerboy);	
			
			
			break;
		}

		psDisplay();
	}

	return 0;
}