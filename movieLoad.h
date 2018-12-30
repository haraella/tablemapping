#pragma once

#include "ofMain.h"
#include "ofxWMFVideoPlayer.h"
 class MovieLoad {
public:
	void setup();
	void setMovie();
	void update();
	void movieDraw(int value);
	void movieCheckPlaying(int value);

	ofxWMFVideoPlayer video[9];
	bool isPlaying[9];//再生確認用
	int window_Width = 1000;
	int window_Height = 1000;

};
