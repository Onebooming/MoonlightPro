/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-20 22:05:39
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-20 22:09:42
 * @FilePath: /MoonLightPro/src/mnjson.cpp
 * @Description: 项目json api实现
 */
#include "../include/mnjson.h"

namespace MoonLight
{
    bool MNJson::fromJsonString(const std::string &json_str)
    {
        try
        {
            json_data = nlohmann::json::parse(json_str);
            return true;
        }
        catch (const nlohmann::json::parse_error &)
        {
            return false;
        }
    }

    std::string MNJson::toJsonString() const
    {
        return json_data.dump();
    }

    template <typename T>
    void MNJson::set(const std::string &key, const T &value)
    {
        json_data[key] = value;
    }

    template <typename T>
    T MNJson::get(const std::string &key) const
    {
        return json_data.at(key).get<T>();
    }

} // namespace MoonLight