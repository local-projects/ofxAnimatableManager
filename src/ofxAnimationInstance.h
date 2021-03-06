#pragma once
#include "ofMain.h"
#include "ofxAnimation.h"
#include "ofxJSONElement.h"
#include "ofxAnimatableFloat.h"

const string DURATION = "duration";
const string DELAY = "delay";
const string TIMING_FUNCTION = "timing-function";
const string ITERATION_COUNT = "iteration-count";

class ofxAnimation;
class ofxAnimationKeyframe;
class ofxAnimationInstance : public ofxAnimatableFloat{
public:
    ofxAnimationInstance();
    ~ofxAnimationInstance();
    void update(float dt);
    void setID(string ID);
    string getID();
    void setAnimation(ofxAnimation* animation);
    void setDelay(float delay);
    float getDelay();
    void setDuration(float duration);
    float getDuration();
    void play();
    ofxAnimationKeyframe* getCurrentKeyframe();
    ofxAnimationKeyframe* getNextKeyframe();
    
    void setAnimatable(string key, ofxAnimatableFloat* floatAnimatable);
    void setAnimatable(string key, ofxAnimatableOfColor* colorAnimatable);
    void finished(AnimationEvent& args);
    void looped(AnimationEvent& args);
    void applyKeyframe(ofxAnimationKeyframe* keyframe);
    void animateToKeyframe(ofxAnimationKeyframe* keyframe, float duration);
    void trigger();
    void animateToNextKeyframe();
    set<string> getKeys();
    bool started;
    void init(ofxJSONElement animationInstanceData);
    ofxAnimationInstance* clone();
    ofxAnimation* getAnimation();
protected:
    string ID;
    string stateID;
    float duration, delay;
    ofxAnimation* animation;
    int keyframeIndex;
    map<string, ofxAnimatableOfColor*> colorAnimatables;
    map<string, ofxAnimatableFloat*> floatAnimatables;
};