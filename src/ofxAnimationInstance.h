#include "ofMain.h"
#include "ofxAnimation.h"
#include "ofxAnimatableFloat.h"

class ofxAnimationInstance : public ofxAnimatableFloat{
public:
    ofxAnimationInstance();
    ofxAnimationInstance(ofxAnimation* animation);
    void update(float dt);
    void setID(string ID);
    string getID();
    void setDelay(float delay);
    float getDelay();
    void setDuration(float duration);
    float getDuration();
    void play();
    void setStateID(string stateID);
    string getStateID();
    ofxAnimationKeyframe* getCurrentKeyframe();
    ofxAnimationKeyframe* getNextKeyframe();
    
    void setAnimatable(string key, ofxAnimatableFloat* floatAnimatable);
    void setAnimatable(string key, ofxAnimatableOfColor* colorAnimatable);
    void finished(AnimationEvent& args);
    void applyKeyframe(ofxAnimationKeyframe* keyframe);
    void animateToKeyframe(ofxAnimationKeyframe* keyframe, float duration);
    
    void animateToNextKeyframe();
    
    bool started;

protected:
    string ID;
    string stateID;
    float duration, delay;
    ofxAnimation* animation;
    int keyframeIndex;
    map<string, ofxAnimatableOfColor*> colorAnimatables;
    map<string, ofxAnimatableFloat*> floatAnimatables;
};