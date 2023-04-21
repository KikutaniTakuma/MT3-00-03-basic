#include <Novice.h>
#include "Vector3D/Vector3D.h"
#include "Mat4x4/Mat4x4.h"

const char kWindowTitle[] = "LE2A_04_キクタニ_タクマ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Vector3D translate(4.1f, 2.6f, 0.8f);
	Vector3D scale(1.5f, 5.2f, 7.3f);
	Mat4x4 translateMatrix = MakeMatrixTranslate(translate);
	Mat4x4 scaleMatrix = MakeMatrixScalar(scale);
	Vector3D point(2.3f, 3.8f, 1.4f);
	Mat4x4 transformMatrix({
		1.0f, 2.0f, 3.0f, 4.0f,
		3.0f, 1.0f ,1.0f, 2.0f,
		1.0f, 4.0f, 2.0f, 3.0f,
		2.0f, 2.0f, 1.0f, 3.0f
	});
	Vector3D transformed = point * transformMatrix;

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
		Vec3ScreenPrintf(0, 0, transformed, "transformed");
		MatrixScreenPrintf(0, 20, translateMatrix, "translateMatrix");
		MatrixScreenPrintf(0, 20 + kRowheight * 5, scaleMatrix, "scaleMatrix");
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
