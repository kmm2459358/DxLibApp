#include <DxLib.h>

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(1200, 800, 32);
	if (DxLib_Init() == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		ClearDrawScreen();
		DrawBox(0, 0, 600, 400, GetColor(255, 255, 0), TRUE);

		ScreenFlip();
	}
	DxLib_End();

	return 0;
}