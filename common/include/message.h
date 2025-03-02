/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-05 22:48:05
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-07 20:46:35
 * @FilePath: /2025/MoonLightPro/include/message.h
 * @Description: 消息类
 */
#ifndef __MESSAGE__
#define __MESSAGE__

#include <iostream>
#include <vector>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <memory>

namespace MoonLight {
    enum class Identifier
    {
        hello,
        get,
        edit_config,
        bult
    };

    enum class DataType
    {
        json,
        xml,
        plain,
        protobuf,
        bult
    };

    class Message
    {
    public:
        Message(unsigned int id, Identifier identifier, DataType dataType, unsigned int data_len, const char *data_content)
            : _id(id), _identifier(identifier), _dataType(dataType), _data_len(data_len)
        {
            if(data_len == 0)
            {
                data_content_ = nullptr;
            }
            else
            {
                data_content_ = new char[data_len];
                memcpy(data_content_, data_content, data_len);
            }
        }
        Message(const Message &rMes);
        ~Message();
        //todo: 重载赋值运算符
        Message &operator=(const Message &rMes);

        // 序列化方法
        std::shared_ptr<std::vector<uint8_t>> serialize() const;
        // 反序列化方法
        static std::shared_ptr<Message> deserialize(const std::vector<uint8_t> &data);

        // 获取成员变量的方法
        unsigned int getID() const { return _id; }
        Identifier getIdentifier() const { return _identifier; }
        DataType getDataType() const { return _dataType; }
        unsigned int getDataLen() const { return _data_len; }
        const char *getDataContent() const { return data_content_; }

        // 设置成员变量的方法
        void setID(unsigned int id) { _id = id; }
        void setIdentifier(Identifier identifier) { _identifier = identifier; }
        void setDataType(DataType dataType) { _dataType = dataType; }
        void setDataLen(unsigned int data_len) { _data_len = data_len; }
        void setDataContent(const char *data_content);
        
    private : unsigned int _id;
        Identifier _identifier;
        DataType _dataType;
        unsigned int _data_len;
        char *data_content_;
    };
}

#endif //__MESSAGE__
