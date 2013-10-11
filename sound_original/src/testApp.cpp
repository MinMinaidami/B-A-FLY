#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // sound input
    soundStream.listDevices();
	int bufferSize = 256;
	left.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);
	bufferCounter	= 0;
	drawCounter		= 0;
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofBackground(255,255,255);
    ofSoundUpdate();
    ofNoFill();

    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 0.1, true);
	volHistory.push_back( scaledVol );
	if( volHistory.size() >= 400 ){
		volHistory.erase(volHistory.begin(), volHistory.begin()+1);
	}
    if (ofGetElapsedTimef()>255) {
        ofGetElapsedTimef()==20;
    }


}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i=0; i<NUM; i++){
        time[i]+=scaledVol;
        float posx =ofNoise(time[i]*50)*800;
        float posy =ofNoise(time[i]*30)*1250;
        ofEllipse(posx, posy-20,30, 15);
        ofLine(posx+15, posy-20, posx+35, posy-50);
        ofFill();
        ofSetColor(220,ofGetElapsedTimef()*20,ofGetElapsedTimef()*5);
        ofEllipse(posy, posx+20, 35, 18);
        ofLine(posy+15, posx+20, posy+35, posx-10);
        ofSetColor(100,ofGetElapsedTimef()*20,ofGetElapsedTimef()*5);
        ofFill();
        
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){
    
    
	float curVol = 0.0;
	int numCounted = 0;
	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		curVol += left[i] *left[i];
		numCounted+=2;
	}
	
	curVol /= (float)numCounted;
	curVol = sqrt( curVol );
	smoothedVol *= 0.93;//smootheoVol shi cai ji de sheng yin shu ju
	smoothedVol += 0.07 * curVol;
	bufferCounter++;
}
