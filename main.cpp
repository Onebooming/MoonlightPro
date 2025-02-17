/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-05 21:40:06
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-12 21:35:48
 * @FilePath: /MoonLightPro/main.cpp
 * @Description: main函数
 */
#include "include/hello.h"
#include "include/message.h"
#include "include/capthreadapi.h"
#include <memory>

void testHello() {
    std::shared_ptr<MoonLight::HelloPure> helloPure = std::make_shared<MoonLight::HelloDemo>(MoonLight::Language::Chinese);
    helloPure->sayHello();
    helloPure->setLanguage(MoonLight::Language::English);
    helloPure->sayHello();
    helloPure->setLanguage(MoonLight::Language::French);
    helloPure->sayHello();
    helloPure->setLanguage(MoonLight::Language::Japanese);
    helloPure->sayHello();
    helloPure->setLanguage(MoonLight::Language::Latin);
    helloPure->sayHello();
}

void testMessage() {
    const char *strContent = "{\"name\":\"Onebooming\",\"age\":18}";
    MoonLight::Message mes(1, MoonLight::Identifier::hello, MoonLight::DataType::json, strlen(strContent), strContent);
    auto data = mes.serialize();
    auto rMes = MoonLight::Message::deserialize(*data);
    std::cout << "content = " << std::string(rMes->getDataContent()) << std::endl;
}

void exampleCallback(int id, const std::string& message) {
    int count = 0;
    while (count <= 5)
    {
        auto thread_id = std::hash<std::thread::id>{}(std::this_thread::get_id());
        std::cout << "[thread id = " << thread_id << "], id = " << id << ", message = " << message << ", count = " << count <<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count++;
    }
}

void testCapThreadApi() {
    MoonLight::CapThreadApi capThreadApi1;
    capThreadApi1.setCallback(exampleCallback, 1, "hello");


    MoonLight::CapThreadApi capThreadApi2;
    capThreadApi2.setCallback(exampleCallback, 2, "world");


    MoonLight::CapThreadApi capThreadApi3;
    capThreadApi3.setCallback(exampleCallback, 3, "moon");


    capThreadApi1.start();
    capThreadApi2.start();
    capThreadApi3.start();
    // 等待3s
    std::this_thread::sleep_for(std::chrono::seconds(3));

    capThreadApi1.stop();
    capThreadApi2.stop();
    capThreadApi3.stop();
}

int main() {
    testHello();
    testMessage();
    testCapThreadApi();

    return 0;
}