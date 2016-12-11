#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Layer1.h"
#include "ui\CocosGUI.h"

USING_NS_CC;
using namespace ui;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    auto sprite = Sprite::create("background.jpg");
	sprite->setScale(1.5);
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
	auto play = Button::create("start.PNG", "start.PNG");
	play->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 22));
	play->setScale(1.5);
	play->setSwallowTouches(true);

	play->addTouchEventListener([&](Ref *Sender, Widget::TouchEventType type)
	{
		switch (type){
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			CCLOG("aaaaaaa");
			Layer1 *layer1 = Layer1::create();
			this->addChild(layer1, 1);
			break;
		}
	});
	this->addChild(play);

	auto options = Button::create("options.PNG", "options.PNG");
	options->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 35));
	
	options->setScale(1.5);
	//auto menu1 = Menu::create(play, options, NULL);
	//menu1->setPosition(Vec2::ZERO);
	//this->addChild(menu1, 0);
	return true;
}

void HelloWorld::clickStart(cocos2d::Ref* pSender){
	CCLOG("aaaaaaa");
	Layer1 *layer1 = Layer1::create();
	this->addChild(layer1, 1);
}

void HelloWorld::clickOption(cocos2d::Ref* pSender){
	CCLOG("aaaaaaa");
}


void HelloWorld::menuCloseCallback(cocos2d::Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
