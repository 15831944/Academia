#pragma once
#ifndef _MOUSE_H_
#define _MOUSE_H_

class Mouse
{
private:
	Mouse() {}
	~Mouse() {}

public:
	static D3DXVECTOR3 getMousePos()
	{
		POINT pt = {};
		GetCursorPos(&pt);
		ScreenToClient(g_hWnd, &pt);

		return D3DXVECTOR3((float)pt.x, (float)pt.y, 0.0f);
	}
};

#endif