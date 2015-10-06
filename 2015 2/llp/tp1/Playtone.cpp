#include "Playtone.h"

#define BEEP_PATH "/usr/bin/beep"

Playtone::Playtone(float f, float d){
	frequencia = f;
	duracao = d;
}
 
int Playtone::beep(){
    char cmd[256];
 
    snprintf(cmd, sizeof(cmd), "%s -f %.02f -l %.02f",
    BEEP_PATH, frequencia, duracao);
 
    return system(cmd);
}