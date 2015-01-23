#include "lvl1Scene.h"
#include "creditosScene.h"

#include "cocostudio/CocoStudio.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace cocostudio;

lvl1::lvl1()	{
	//TOUCH
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(lvl1::onTouchBegan, this);
	//listener->onTouchMoved = CC_CALLBACK_2(lvl1::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}

lvl1::~lvl1()	{
}

Scene* lvl1::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = lvl1::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

//INIT
bool lvl1::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//Limites
    limx=visibleSize.width;
    limy=visibleSize.height;
	//UPDATE
	this->schedule(schedule_selector(lvl1::update));
	//TOUCH
	this->setTouchEnabled(true);

	//Music - Brackground
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("theme.3ga",true);

    //BackGround
    background = Sprite::create("HelloWorld.png");
    background->setPosition(Vec2(limx/2, limy/2));
    this->addChild(background, 0);
	//Animations
	megaman=Armature::create("megaman");
	megaman->getAnimation()->playByIndex(0);
	megaman->setPosition(Vec2(limx/2, limy/2));
	//megaman->setScale(0.15);
	addChild(megaman,1);

    return true;
}

void lvl1::update(float dt){

}

bool lvl1::onTouchBegan(Touch* touch, Event* event) {
	String currentAnim;
	currentAnim = megaman->getAnimation()->getCurrentMovementID();
	if (currentAnim.compare("walk"))	{
	megaman->getAnimation()->play("on");
	} else if (currentAnim.compare("on"))	{
	megaman->getAnimation()->play("fire");
	} else {
	megaman->getAnimation()->play("walk");
	}

	return true;
}
