#include < DxLib.h>

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC) {
	int model1;
	VECTOR pos = VGet(600.0f, 300.0f, -400.0f);
	int key;
	enum Direction { DOWN, LEFT, UP, RIGHT } direction = DOWN;
	MATRIX mat1, mat2;   // šš’Ç‰Á

	ChangeWindowMode(TRUE);
	SetGraphMode(1200, 800, 32);
	if (DxLib_Init() == -1) {
		return -1;
	}
	//ƒ‚ƒfƒ‹“Ç‚İ‚İ
	model1 = MV1LoadModel("Player/PC.mv1");
	if (model1 == -1) {
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//ƒL[‘€ì
		key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if (key & PAD_INPUT_DOWN) { pos.z -= 4.0f; direction = DOWN; }
		if (key & PAD_INPUT_UP) { pos.z += 4.0f; direction = UP; }
		if (key & PAD_INPUT_LEFT) { pos.x -= 4.0f; direction = LEFT; }
		if (key & PAD_INPUT_RIGHT) { pos.x += 4.0f; direction = RIGHT; }

		ClearDrawScreen();
		DrawBox(0, 0, 1200, 800, GetColor(255, 255, 255), TRUE);

		// MV1SetRotationXYZ(model1, VGet(0.0f, 1.57f * direction, 0.0f));  // ššƒŒƒ€‰»
		// MV1SetPosition(model1, pos);           // ššƒŒƒ€‰»
		mat1 = MGetRotY(1.57f * direction);       // šš’Ç‰Á
		mat2 = MGetTranslate(pos);                // šš’Ç‰Á
		MV1SetMatrix(model1, MMult(mat1, mat2));  // šš’Ç‰Á

		MV1DrawModel(model1);
		ScreenFlip();
	}
	DxLib_End();
	return 0;
}