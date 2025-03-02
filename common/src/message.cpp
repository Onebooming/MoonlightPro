/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-05 22:48:30
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-07 21:04:38
 * @FilePath: /MoonLightPro/src/message.cpp
 * @Description: Message类的实现
 */
#include "../include/message.h"
#include <iostream>
#include <vector>
#include <arpa/inet.h>
#include <stdio.h>

namespace MoonLight {
    Message::Message(const Message &rMes)
    {
        _id = rMes._id;
        _identifier = rMes._identifier;
        _dataType = rMes._dataType;
        _data_len = rMes._data_len;
        if(rMes.data_content_ == nullptr)
        {
            data_content_ = nullptr;
        }
        else
        {
            data_content_ = new char[_data_len];
            memcpy(data_content_, rMes.data_content_, _data_len);
        }
    }

    Message::~Message()
    {
        if(data_content_ != nullptr)
        {
            delete[] data_content_;
        }
    }

    Message &Message::operator=(const Message &rMes)
    {
        if(this == &rMes)
        {
            return *this;
        }
        _id = rMes._id;
        _identifier = rMes._identifier;
        _dataType = rMes._dataType;
        _data_len = rMes._data_len;
        if(rMes.data_content_ == nullptr)
        {
            data_content_ = nullptr;
        }
        else
        {
            data_content_ = new char[_data_len];
            memcpy(data_content_, rMes.data_content_, _data_len);
        }
        return *this;
    }

    void Message::setDataContent(const char *data_content)
    {
        if(data_content_ != nullptr)
        {
            delete[] data_content_;
        }
        if(data_content == nullptr)
        {
            _data_len = 0;
            data_content_ = nullptr;
        }
        else
        {
            _data_len = strlen(data_content);
            data_content_ = new char[_data_len];
            memcpy(data_content_, data_content, _data_len);
        }
    }

    std::shared_ptr<std::vector<uint8_t>> Message::serialize() const
    {
        std::shared_ptr<std::vector<uint8_t>> data(new std::vector<uint8_t>);

        // 将id转为网络字节序
        uint32_t id = htonl(static_cast<uint32_t>(_id));
        data->insert(data->end(), reinterpret_cast<uint8_t *>(&id), reinterpret_cast<uint8_t *>(&id) + 4);
        
        // 将identifier转为网络字节序
        uint32_t identifier = htonl(static_cast<uint32_t>(_identifier));
        data->insert(data->end(), reinterpret_cast<uint8_t *>(&identifier), reinterpret_cast<uint8_t *>(&identifier) + 4);

        // 将dataType转为网络字节序
        uint32_t dataType = htonl(static_cast<uint32_t>(_dataType));
        data->insert(data->end(), reinterpret_cast<uint8_t *>(&dataType), reinterpret_cast<uint8_t *>(&dataType) + 4);

        // 将data_len转为网络字节序
        uint32_t data_len = htonl(static_cast<uint32_t>(_data_len));
        data->insert(data->end(), reinterpret_cast<uint8_t *>(&data_len), reinterpret_cast<uint8_t *>(&data_len) + 4);

        // 将data_content插入到data中
        data->insert(data->end(), reinterpret_cast<uint8_t *>(data_content_), reinterpret_cast<uint8_t *>(data_content_) + _data_len);

        return data;
    }

    std::shared_ptr<Message> Message::deserialize(const std::vector<uint8_t> &data)
    {
        std::shared_ptr<Message> rMes = std::make_shared<Message>(0, Identifier::hello, DataType::plain, 0, nullptr);

        // 从data中读取id
        uint32_t id = 0;
        memcpy(&id, &data[0], 4);
        rMes->_id = ntohl(id);

        // 从data中读取identifier
        uint32_t identifier = 0;
        memcpy(&identifier, &data[4], 4);
        rMes->_identifier = static_cast<Identifier>(ntohl(identifier));

        // 从data中读取dataType
        uint32_t dataType = 0;
        memcpy(&dataType, &data[8], 4);
        rMes->_dataType = static_cast<DataType>(ntohl(dataType));

        // 从data中读取data_len
        uint32_t data_len = 0;
        memcpy(&data_len, &data[12], 4);
        rMes->_data_len = ntohl(data_len);

        // 从data中读取data_content
        if(rMes->_data_len == 0)
        {
            rMes->data_content_ = nullptr;
        }
        else
        {
            rMes->data_content_ = new char[rMes->_data_len];
            memcpy(rMes->data_content_, &data[16], rMes->_data_len);
        }

        return rMes;
    }
    
} // namespace MoonLight