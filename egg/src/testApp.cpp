#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
    v1.loadSound("v1.mp3");
    starImage.loadImage("star.png");
	c.loadImage("c.png");
    c.resize(c.width / 5, c.height / 5);
	starImage.resize(starImage.width/10, starImage.height/10);
    time=0.06;
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		//particles[i].addForce(0,0.04);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}
    
    
    
    pos.x = (1-time) * pos.x + (time) * mouseX;
    pos.y = (1-time) * pos.y + (time) * mouseY;
    float dx = pos.x - prevPos.x;
    float dy = pos.y - prevPos.y;
    angle = atan2(dy, dx);
    prevPos=pos;

}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(0x000000);
    
    ofEnableAlphaBlending();
	
    ofSetColor(255,255,255);

    
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
    
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(angle * RAD_TO_DEG);
    c.draw( 0,0);
    ofPopMatrix();

    
    
        //starImage.draw(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    
    
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    if (particles.size() > 100){
        particles.erase(particles.begin());
    }
    float vx = ofRandom(-4,4);
    float vy = ofRandom(-4,4);
    particle temp;
    temp.setInitialCondition(mouseX,mouseY,vx, vy);	
    temp.star = &starImage;
    particles.push_back(temp);

    
    

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
    v1.play();
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
