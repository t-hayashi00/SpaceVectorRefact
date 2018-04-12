#include "sound.h"

int sound[7];
int music[2];

void playMusic(const char* name) {
	if (name == "title") {
		PlaySoundMem(music[0], DX_PLAYTYPE_BACK, TRUE);
	}else if (name == "ingame"){
		PlaySoundMem(music[1], DX_PLAYTYPE_LOOP, TRUE);
	}
}

void stopMusic() {
	StopSoundMem(music[0]);
	StopSoundMem(music[1]);
}

void playSound(const char* name) {
	if (name == "damage") {
		PlaySoundMem(sound[0], DX_PLAYTYPE_BACK, TRUE);
	}
	else if (name == "accel") {
		PlaySoundMem(sound[1], DX_PLAYTYPE_BACK, TRUE);
	}
	else if (name == "brake") {
		PlaySoundMem(sound[2], DX_PLAYTYPE_BACK, TRUE);
	}
	else if (name == "shoot") {
		PlaySoundMem(sound[3], DX_PLAYTYPE_BACK, TRUE);
	}
	else if (name == "bomb") {
		PlaySoundMem(sound[4], DX_PLAYTYPE_BACK, TRUE);
	}
	else if (name == "dead") {
		PlaySoundMem(sound[5], DX_PLAYTYPE_BACK, TRUE);
	}
	else if (name == "clash") {
		PlaySoundMem(sound[6], DX_PLAYTYPE_BACK, TRUE);
	}
}


void setupSound() {
	sound[0] = LoadSoundMem("sound/bom17_b.wav");
	sound[1] = LoadSoundMem("sound/tm2_laser002.wav");
	sound[2] = LoadSoundMem("sound/tm2_power001.wav");
	sound[3] = LoadSoundMem("sound/tm2_shoot003.wav");
	sound[4] = LoadSoundMem("sound/tm2_bom003.wav");
	sound[5] = LoadSoundMem("sound/tm2_death000.wav");
	sound[6] = LoadSoundMem("sound/tm2_bom002.wav");
	music[0] = LoadSoundMem("sound/jingle.wav");
	music[1] = LoadSoundMem("sound/loop.mp3");
}