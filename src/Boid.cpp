#include "Boid.hpp"

Boid::Boid(){
    
    damping = ofRandom(0.95, 0.97);
}

void Boid::applyForce(ofVec3f force){
    acc += force;
}

void Boid::pullToCenter(ofVec3f center){
    ofVec3f dir = pos - center;
    float dist = dir.length();
    float maxDistance = 300.0;
    
    if (dist > maxDistance) {
        dir.normalize();
        vel -= dir * (dist / maxDistance) * 0.001f;
    }
}

void Boid::update() {
    
    float minSpeed = 1.0;
    vel += acc;
    vel.limit(3.0);
    
    if (vel.lengthSquared() < minSpeed * minSpeed){
        vel.normalized() * minSpeed;
    }
    
    pos += vel;
    vel *= damping;
    
    acc.set(0);
}

void Boid::draw(){
    
    ofSetColor(0);
    ofDrawCircle(pos, 1);
    
    ofSetColor(255, 255, 0);
    ofDrawLine(pos, pos-vel *2.0);
}
