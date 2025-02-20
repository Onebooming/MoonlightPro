/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-20 22:04:11
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-20 22:09:58
 * @FilePath: /MoonLightPro/include/mnjson.h
 * @Description: 项目json api
 */
#ifndef MNJSON_H
#define MNJSON_H

#include "third_party/json.hpp"
#include <string>
#include <map>

namespace MoonLight
{
    class MNJson
    {
    public:
        bool fromJsonString(const std::string &json_str);
        std::string toJsonString() const;

        template <typename T>
        void set(const std::string &key, const T &value);
        template <typename T>
        T get(const std::string &key) const;

    private:
        nlohmann::json json_data;
    };
} // namespace MoonLight

#endif // MNJSON_H