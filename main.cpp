#include <Novice.h>

const char kWindowTitle[] = "LC!C_01_アオキ_コウシ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	int glaphHandle1;
	glaphHandle1 = Novice::LoadTexture("./Resources/de.png");
	int glaphHandle2;
	glaphHandle2 = Novice::LoadTexture("./Resources/jp.png");
	int glaphHandle3;
	glaphHandle3 = Novice::LoadTexture("./Resources/dk.png");

	    // キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		Novice::DrawBox(0, 0, 256, 57, 0.0f, 0x000000FF, kFillModeSolid);
		Novice::DrawBox(0, 58,256 , 57,0.0f, 0xFF0000FF, kFillModeSolid);
		Novice::DrawBox(0, 115, 256,57, 0.0f, 0xFFD700FF, kFillModeSolid);
		Novice::DrawBox(260, 0, 256, 170, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawEllipse(388,85,50,50, 0.0f, RED, kFillModeSolid);
		Novice::DrawBox(530, 0, 256, 170, 0.0f, RED, kFillModeSolid);
		Novice::DrawBox(610, 0, 20, 170, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(530, 85, 256, 20, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawSprite(0,260, glaphHandle1, 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(260, 260, glaphHandle2, 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(530, 260, glaphHandle3, 1, 1, 0.0f, 0xFFFFFFFF);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
