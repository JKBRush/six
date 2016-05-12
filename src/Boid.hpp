#include "ofMain.h"

class Boid {
public:
    Boid();
    
    void applyForce( ofVec3f force );
    void pullToCenter( ofVec3f center );
    
    void update();
    void draw();
    
    float damping;
    ofVec3f pos, vel, acc;
};
