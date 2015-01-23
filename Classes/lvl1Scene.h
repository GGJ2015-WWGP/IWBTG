#ifndef __LVL1_SCENE_H__
#define __LVL1_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace cocostudio;

class lvl1 : public cocos2d::Layer
{
public:
	//Constructor and Destructor
	lvl1();
	~lvl1();
	//Scene
    static Scene* createScene();
	virtual bool init();
    //Limites
	float limx;
	float limy;
	//UPDATE
	void update(float dt);
	//TOUCH
	bool onTouchBegan(Touch* touch, Event* event);
	//void onTouchMoved(Touch* touch, Event* event);

	//Global Variables
	int stepCount;

	//SPRITES
	Sprite *background;
	//ANIMATIONS
	Armature* megaman;

    // implement the "static create()" method manually
    CREATE_FUNC(lvl1);
};

#endif // __LVL1_SCENE_H__
