#pragma once

struct InputCommands
{
	bool forward;
	bool back;
	bool right;
	bool left;

	int mouse_X;
	int mouse_Y;
	bool mouse_LB_Down;
	bool mouse_RB_Down;

	int itemInteract;

	bool itemRotate;
	bool itemMove;
	bool itemSelect;
	bool itemScale;

	bool controlKey;
	bool delKey;
	bool vKey;
	bool cKey;
	bool zKey;
	bool yKey;
	
};
