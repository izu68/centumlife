#include "psx.h"
#include "sprite.h"
#include "mesh.h"
#include "state.h"

#include "satus.h"

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
	
	game_state = LOAD_SATUS;
	
	while(1) {
		psClear();
		psCamera(cameraX, cameraY, cameraZ, 300, 0, 0);
		update();
		FntPrint ("GRASS X ANG: %d\n", grass.angX);
		FntPrint ("GRASS Y ANG: %d\n", grass.angY);
		FntPrint ("GRASS Z ANG: %d\n", grass.angZ);

		switch (game_state){
		case LOAD_SATUS:
			load_satus ();

			game_state = UPDATE_SATUS;
			break;
		
		case UPDATE_SATUS:
			update_satus ();
			
			break;
		}

		psDisplay();
	}

	return 0;
}