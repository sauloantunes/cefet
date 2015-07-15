#ifndef __HUD_H__
#define __HUD_H__

#include "config.h"

using namespace std;

class HUD{
public:
	int m_score;
	int m_lives;
	int m_level;
	bool m_hasMessage;
	char* m_message;
	string m_bricksFile;
	struct color m_color;

	HUD();
	void draw();
	void drawString(char*);
	void showMessage();
};


#endif