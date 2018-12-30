#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "movieLoadh.h"
#include "ofxSpout2Sender.h"
#include "ofxWMFVideoPlayer.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		const int senderTmp = 3;//実際に同時再生する動画の数

		ofxSpout2::Sender spout[3];//動画送信用
		ofFbo fbo[3];//fbo宣言
		bool tmp[3];

		ofSerial serial;//シリアル通信
		int  windowWidth = 1000;//画面サイズ適当
		int windowHeight = 1000;

		ofParameter <int> value[3];//切り替え用のパラメーターを宣言
		//ofParameterGroup parameters;
		ofxPanel gui;//guiを用意

		char Serialtmp;//シリアル通信で受け取った文字列を格納する変数
		ofxWMFVideoPlayer video;//ビデオプレイヤーの定義
		MovieLoad  mov[3];//MovieLoad型の配列を宣言
		bool check=false;//クレジットを出すか出さないかの切り替え
		
};
