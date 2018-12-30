#include "movieLoadh.h"

void MovieLoad::setup() {
	setMovie();
	for (int i = 1; i >= 8; i++) {
		video[i].setLoop(false);
	}
}

void MovieLoad::setMovie() {
	//////////////////////////映像をロード
	//////////////////////////8つ用意したので8つ分格納

	video[1].loadMovie("hogehoge.mp4");
	video[2].loadMovie("hogehoge.mp4");
	video[3].loadMovie("hogehoge.mp4");
	video[4].loadMovie("hogehoge.mp4");
	video[5].loadMovie("hogehoge.mp4");
	video[6].loadMovie("hogehoge.mp4");
	video[7].loadMovie("hogehoge.mp4");
	video[8].loadMovie("hogehoge.mp4");
}

void MovieLoad::update() {
	for (int i = 1; i <= 8; i++) {//各映像をアップデート
		video[i].update();
		isPlaying[i] = video[i].isPlaying();//
	}
}
void MovieLoad::movieCheckPlaying(int value) {//映像プレイ用メソッド、複数の映像が同時にプレイしていると重いのでストップをかける

	video[value].play();//valueの値の映像をプレイ
	for (int i = 1; i <= 8; i++) {
		if (i != value) {//もしvalue以外の映像が
			if (isPlaying[i]) {//プレイされていたら
				video[i].stop();//映像をストップする
			}
		}
	}
}

void MovieLoad::movieDraw(int value) {//映像描画メソッド
	switch (value) {
	case 0://パラメーターが規定値なら
		printf_s("null");
		for (int i = 1; i <= 8; i++) {
			if (isPlaying[i]) {//映像がプレイされていたら
				video[i].stop();//すべての映像をストップする
			}
		}
		break;
	case 1:
		printf_s("1");
		movieCheckPlaying(value);
		video[value].draw(0, 0, video[value].getHeight(), video[value].getWidth());
		break;
	case 2:
		printf_s("2");
		movieCheckPlaying(value);
		video[value].draw(0, 0, video[value].getHeight(), video[value].getWidth());
		break;
	case 3:
		printf_s("3");
		movieCheckPlaying(value);
		video[value].draw(0, 0, video[value].getHeight(), video[value].getWidth());
		break;
	case 4:
		printf_s("4");
		movieCheckPlaying(value);
		video[value].draw(0, 0, video[value].getHeight(), video[value].getWidth());
		break;
	case 5:
		printf_s("5");
		movieCheckPlaying(value);
		video[value].draw(0, 0, video[value].getHeight(), video[value].getWidth());
		break;
	case 6:
		printf_s("6");
		movieCheckPlaying(value);
		video[value].draw(0, 0, video[value].getHeight(), video[value].getWidth());
		break;
	case 7:
		printf_s("7");
		movieCheckPlaying(value);
		video[value].draw(0, 0, video[value].getHeight(), video[value].getWidth());
		break;
	case 8:
		printf_s("8");
		movieCheckPlaying(value);
		video[value].draw(0, 0, video[value].getHeight(), video[value].getWidth());
		break;
	default:
		break;
	}
}
