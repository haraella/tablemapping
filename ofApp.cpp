#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(false);
	ofSetFrameRate(30);
	ofSetWindowShape(windowWidth, windowHeight);
	gui.setup("GUIの名前");
	for (int i = 0; i < senderTmp;i++) {

		fbo[i].allocate(windowWidth, windowHeight);
		gui.add(value[i].set("Parameter" + i, 0, 0, 9));
		mov[i].setup();
	}
	serial.setup("COM3",9600);
	fbo[3].allocate(1920,1080);//これとしたのはクレジット用　なのでいらない
	video.loadMovie("動画名");
}
//--------------------------------------------------------------
void ofApp::update(){
	if (serial.isInitialized()) {
		if (serial.available()) {
			Serialtmp = serial.readByte();//シリアル通信の文字格納
			serial.readByte();
			printf_s("%c\n", Serialtmp);//格納した文字を表示
		}
	}
	//1つ目のセンサーの判別式
	if (Serialtmp == 'a') {
		tmp[0] = true;
	}
	if (Serialtmp == 'b') {
		tmp[0] = false;
	}

	//二つ目
	if (Serialtmp == 'c') {
		tmp[1] = true;
	}
	if (Serialtmp == 'd') {
		tmp[1] = false;
	}

	//三つ目
	if (Serialtmp == 'e') {
		tmp[2] = true;
	}
	if (Serialtmp == 'f') {
		tmp[2] = false;
	}

	for (int i = 0; i < senderTmp; i++) {
		mov[i].update();//movのupdateメソッドを更新
	}

	video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	

	for (int i = 0; i < senderTmp; i++) {//この場合3ループ
		ofClear(0);
		fbo[i].begin();//動画をfboにテクスチャとして焼き付け
		if (tmp[i]) {
			mov[i].movieDraw(value[i]);//パラメータの値によって再生させる動画を切り替える
		}
		fbo[i].end();
		fbo[i].draw(0,0);
	}
	if (value[0] != 9 && value[1] != 9 && value[2] != 9) {//このifはいらないです
		for (int i = 0; i < senderTmp; i++) {
			spout[i].sendTexture(fbo[i].getTexture(), "Sensor" + i);//spoutを通してマッドマッパーにテクスチャを送信
		}
	}

		fbo[3].begin();//クレジット再生用なのでここから
		ofClear(0);
		if (value[0] == 9 && value[1] == 9 && value[2] == 9 && check == true) {
			video.play();
			video.draw(0, 0, video.getHeight(), video.getWidth());
		}
		fbo[3].end();
		fbo[3].draw(0,0);
			spout[3].sendTexture(fbo[3].getTexture(), "credit" );//ここまではいらないです
	
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){//基本的にこのメソッド内の記述は必要ない
	if (key == 'a') {//動作確認用　
		tmp[0] = true;
	}
	else tmp[0] = false;

	if (key == 's') {
		tmp[1] = true;
	}
	else tmp[1] = false;

	if (key == 'd') {
		tmp[2] = true;
	}
	else tmp[2] = false;

	if (key == 'c') {
		check = true;
	}
	else check = false;
}

//以下省略
