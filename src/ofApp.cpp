#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(100);
    
    sender.setup (HOST,PORT);
    
    video.initGrabber(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    
    float r = 0;
    float g = 0;
    float b = 0;
    
    unsigned char * pixels = video.getPixels().getData();;
    
    for (int i = 0;i < ofGetWidth();i++) {
        for (int j = 0;j < ofGetHeight();j++) {
            r += pixels[(j * ofGetWidth() + i)*3];
            g += pixels[(j * ofGetWidth() + i)*3+1];
            b += pixels[(j * ofGetWidth() + i)*3+2];
        }
    }
    
    r /= (ofGetWidth() * ofGetHeight());
    g /= (ofGetWidth() * ofGetHeight());
    b /= (ofGetWidth() * ofGetHeight());
    
    ofxOscMessage m;
    m.setAddress("/rgb");
    if (r >= g) {
        if (r >= b) {
            m.addStringArg("red");
        } else {
            m.addStringArg("blue");
        }
    } else {
        if (g >= b) {
            m.addStringArg("green");
        } else {
            m.addStringArg("blue");
        }
    }
    sender.sendMessage(m);

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
