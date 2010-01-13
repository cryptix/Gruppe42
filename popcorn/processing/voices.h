#ifndef VOICES_H
#define VOICES_H

#include "oscillators.h"
#include "tools.h"
#include "effects.h"

#define voiceCount 32

typedef struct voice {
	char act;
	struct voice *preVoice, *postVoice;
	float freq;
	int velocity;
	float* output;
} voice;

extern voice voices[voiceCount];
extern voice *firstVoice, *lastVoice;
extern float actVoices;


/* --- Initialization --- */

void initVoices();
void initVoice(voice*);


/* Control */

void playSound(int note, int velocity);
void stopSound(int note, int velocity);

#endif