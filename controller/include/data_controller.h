/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-03-02 21:23:08
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-03-02 21:25:23
 * @FilePath: /MoonlightPro/controller/include/data_controller.h
 * @Description: 数据控制器
 */
#ifndef __DATA_CONTROLLER_H__
#define __DATA_CONTROLLER_H__

#include <string>

namespace MoonLight {
    class DataController {
    public:
       virtual ~DataController() = default;

       // 处理请求并返回响应
       virtual std::string ProcessAndResponse(const std::string& request) = 0;
       
    private:
        
    };
}

#endif // __DATA_CONTROLLER_H__