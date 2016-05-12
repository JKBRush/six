#include "ofApp.h"

void ofApp::setup(){
    
    ofBackground( 0 );
    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    ofEnableDepthTest();
    ofHideCursor();
    
    ff.load("ff.png");
    x_pos = (ofGetWidth()-ff.getWidth())/2;
    y_pos = (ofGetHeight()-ff.getHeight())/2;
    
    cam.setDistance( 718 );
    flocker.addParticle(400);

}

void ofApp::update(){
    
    flocker.applyForces(150, 0.4, 0.75, 0.007, 0.003, 0.09);
    flocker.update();
}

void ofApp::draw(){
    
    ofSetWindowTitle( ofToString( ofGetFrameRate() ) );
    
    float time = ofGetElapsedTimef();
    float angle = time*10;
    
    cam.begin();
    
    ofPushMatrix();
    ofTranslate( 0, 0, 0 );
    
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2 - 35, -ofGetHeight()/2);
    ff.draw(x_pos, y_pos);
    ofPopMatrix();
    
    ofRotate( angle, 0, 1, 0 );
    flocker.draw();
    ofPopMatrix();
    
    cam.end();

}