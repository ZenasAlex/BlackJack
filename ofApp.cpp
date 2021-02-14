#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	gStateMgr = GameStateManager::getInstance();
	gStateMgr->changeState(new PlayState());

}

//--------------------------------------------------------------
void ofApp::update(){
	gStateMgr->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	gStateMgr->draw();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	gStateMgr->keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	gStateMgr->keyPressed( key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	gStateMgr->mouseMoved( x,  y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	gStateMgr->mouseDragged( x, y,  button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	gStateMgr->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	
	gStateMgr->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
