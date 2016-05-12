#include "ofMain.h"
#include "FlockController.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    FlockController flocker;
    
    ofEasyCam cam;
    
    ofImage ff;
    
    int x_pos, y_pos;
};