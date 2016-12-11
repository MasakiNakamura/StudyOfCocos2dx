#include "Layer1.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;


// on "init" you need to initialize your instance
bool Layer1::init()
{
	if (!Layer::init()){
		return false;
	}
	this->setTouchEnabled(true);
	//this->setTouchMode(kCCTouchesOneByOne);
	//this->setTouchPriority(kCCMenuH);


	//getting size of screen
	Size winSize = Director::getInstance()->getWinSize();

	//setting a layer
	auto sprite1 = Sprite::create("blue-panel.png");
	sprite1->setScale(1.4);
	sprite1->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(sprite1);
	return true;
}



 

