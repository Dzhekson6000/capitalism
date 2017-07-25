#include "../Classes/AppDelegate.h"

int main(int  /*argc*/, char ** /*argv*/)
{
    // create the application instance
    auto app = std::make_unique<AppDelegate>();
    return cocos2d::Application::getInstance()->run();
}
