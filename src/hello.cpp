/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-05 21:40:53
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-05 22:05:45
 * @FilePath: /2025/MoonLightPro/src/hello.cpp
 * @Description: 项目测试代码
 */

#include "../include/hello.h"

namespace MoonLight {
    void HelloDemo::sayHello() {
        switch (__language) {
            case Language::Chinese:
                std::cout << "你好，世界！" << std::endl;
                break;
            case Language::English:
                std::cout << "Hello, World!" << std::endl;
                break;
            case Language::French:
                std::cout << "Bonjour, le monde!" << std::endl;
                break;
            case Language::Japanese:
                std::cout << "こんにちは、世界！" << std::endl;
                break;
            case Language::Latin:
                std::cout << "Salve, Orbis Terrarum!" << std::endl;
                break;
            default:
                std::cout << "Hello, World!" << std::endl;
                break;
        }
    }

    // 设置语言
    void HelloDemo::setLanguage(Language lang) {
        __language = lang;
    }
} // namespace MoonLight
