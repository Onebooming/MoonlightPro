#ifndef __MOONLIGHT__
#define __MOONLIGHT__

#include <iostream>
#include <string>

namespace MoonLight {

enum class Language
{
    Chinese,
    English,
    French,
    Japanese,
    Latin
};

class HelloPure{
public:
    ~HelloPure() = default;
    virtual void sayHello() = 0;
    virtual void setLanguage(Language lang) = 0;
};



class HelloDemo : public HelloPure{
public:
    HelloDemo(Language language = Language::English) : __language(language) {}
    ~HelloDemo() = default;
    HelloDemo(const HelloDemo &) = delete;
    HelloDemo &operator=(const HelloDemo &) = delete;

    void sayHello() override;
    void setLanguage(Language lang) override;

private:
    Language __language;
};

}

#endif //__MOONLIGHT__