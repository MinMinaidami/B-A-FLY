#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255, 255, 255);
    ofSetCircleResolution(100);
    
    M==100;
    
    for(int i=0; i<M ; i++){
        
        pos[i].set(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()));   // set the random position of every circle
    }
    n==1;

    verdana14A.loadFont("verdana.ttf", 50, true,true,true);
	letter = '$';
	testChar = verdana14A.getCharacterAsPoints(letter);
	ofSetFullscreen(false);
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofSetLineWidth(1);
    
    
    
       
    ofSetColor(24, 58, 117,50);
    
    ofSeedRandom(0);
    for(int i=0; i<M ; i++){
        
        mouse.x=mouseX;
        mouse.y=mouseY;
        int distance= (pos[i] - mouse).length()/6;
        distance=ofClamp(distance, 0, ofRandom(5,100));
        //ofRect(pos[i],  distance, ofRandom(0,ofGetHeight()));
        
        
        //ofLine(ofRandom(0, ofGetHeight()), pos[i].y, distance,distance);
        //ofLine(ofRandom(0,ofGetWidth()), pos[i].x,distance, distance);
        ofSetLineWidth(0.5);
        
        ofSetColor(24, 58, 117,50);
        ofLine(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetWidth()), ofRandom(ofGetWidth()/2,ofGetWidth()/2), distance*n);
        //ofSetColor(189, 252, 168);
        //ofLine(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetWidth()), ofRandom(ofGetWidth()/2,ofGetWidth()/2), distance*n);
        //ofSetColor(245, 195, 197);
        //ofLine(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetWidth()), ofRandom(ofGetWidth()/2,ofGetWidth()/2), distance*n);

    }
   

    
    
    ofSetColor(0, 90, 60);
	ofFill();
    string str = "";
	str += char(letter);
    
	verdana14A.drawString(str, 50, 250);
    
    testChar.setFilled(true);
    testChar.draw(200,250);
    testChar.setFilled(false);
    testChar.draw(350,250);
    
    
    	ofFill();
	ofPushMatrix();
    ofTranslate(550, 250, 0);
    ofBeginShape();
    for(int k = 0; k <(int)testChar.getOutline().size(); k++){
        if( k!= 0)ofNextContour(true) ;
        for(int i = 0; i < (int)testChar.getOutline()[k].size(); i++){
            ofVertex(testChar.getOutline()[k].getVertices()[i].x, testChar.getOutline()[k].getVertices()[i].y);
        }
    }
    ofEndShape( true );
	ofPopMatrix();
    

    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key==OF_KEY_ESC) return;
	testChar = verdana14A.getCharacterAsPoints(key);
	letter = key;

    
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
    
    if (n<8) {
        n+=1;
    }
        else
        n=1;
    
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
