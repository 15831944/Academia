#include "stdafx.h"
#include "MainGame.h"

int main(void)
{
	srand(unsigned(time(NULL)));

	MainGame textRPG;

	bool isPlayed = textRPG.Init();
	if (isPlayed == TRUE)
	{
		textRPG.Progress();
		textRPG.Release();
	}

	return 0;
}