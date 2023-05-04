#pragma once

struct InputCommands
{
	bool forward;
	bool back;
	bool right;
	bool left;
	bool rotRight;
	bool rotLeft;
	bool rotUp;
	bool rotDown;

	int mouse_X;
	int mouse_Y;
	bool mouse_LB_Down;
	bool mouse_RB_Down;

	int itemInteract;

	bool itemRotate;
	bool itemMove;
	bool itemSelect;
	bool itemScale;
};
