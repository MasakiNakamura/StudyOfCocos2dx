#pragma execution_character_set("utf-8")
#include <time.h>
#include "Layer1.h"
#include "SimpleAudioEngine.h"
#include "ui\CocosGUI.h"
#include <map>
USING_NS_CC;
using namespace ui;

// on "init" you need to initialize your instance
bool Layer1::init()
{
	if (!Layer::init()){
		return false;
	}

	char date[64];
	time_t t = time(NULL);
	/*strftime(date, sizeof(date), "%Y/%m/%d %H:%M:%S.%s", localtime(&t));
	std::string dateStr(date);
	std::string hours = cocos2d::StringUtils::format("%d ", (t / 3600 + 9) % 24);
	std::string minutes = cocos2d::StringUtils::format("%d ", (t / 60 % 60));
	std::string seconds = cocos2d::StringUtils::format("%d ", t % 60);
	std::string timeStamp = dateStr + hours;
	
	CCLOG("timestamp %s", timeStamp.c_str());

	CCLOG("%02ld\n", (t / 3600 + 9) % 24);
	CCLOG("%02ld\n", t / 60 % 60);
	CCLOG("%02ld\n", t % 60);*/


	//timestamp with miliseconds yy/mm/dd HH:MM:SS.sss
	timeval curTime;
	gettimeofday(&curTime, NULL);
	int milli = curTime.tv_usec / 1000;

	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, "%Y/%m/%d %H:%M:%S", timeinfo);

	char currentTime[84] = "";
	sprintf(currentTime, "%s.%d", buffer, milli);
	CCLOG("current time: %s \n", currentTime);



	//getting size of screen
	Size winSize = Director::getInstance()->getWinSize();

	//setting a layer
	auto sprite1 = Sprite::create("blue-panel.png");
	sprite1->setScale(1.4);
	sprite1->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(sprite1);


	/*auto button = Button::create("greenbutton.png", "greenbutton.png");
	button->setScale(0.5);
	button->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type){
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			CCLOG("ohhhhh");
			break;
		}
	this->addChild(button,2);
	});*/
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	/*auto buttonNormal = Sprite::create("greenbutton.png");
	auto buttonSelected = Sprite::create("greenbutton.png");
	auto button = MenuItemSprite::create(buttonNormal, buttonSelected, CC_CALLBACK_1( Layer1::hoho, this));
	button->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(button);*/

ScrollView *scrollView = ui::ScrollView::create();
	scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
	scrollView->setContentSize(Size(300, 200));
	scrollView->setInnerContainerSize(Size(1280, 20*50));
	scrollView->setBackGroundImage("HelloWorld.png");
	//scrollView->setBounceEnabled(true);
	scrollView->setAnchorPoint(Vec2(0.5, 0.5));
	scrollView->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		
	std::map<std::string, std::string> name_map;
	/*name_map[1] = "abc";
	name_map[2] = "def";*/
	
	for (int i = 0; i < 20; i++){
			ui::Button *button = ui::Button::create("linea.png", "linea.png");
			button->setScale(0.7);
			button->setPosition(Vec2(scrollView->getContentSize().width/2, i*50));
			scrollView->addChild(button);

			auto label = Label::createWithSystemFont("Text2 テキスト2 (アウトライン)", "HiraKakuProN-W6", 14);
			label->setColor(Color3B(150, 150, 150));
			button->addChild(label);

			
		}
		this->addChild(scrollView);





	return true;
}

void Layer1::hoho(Ref *sender){
	CCLOG("hohohoho");
}

 

