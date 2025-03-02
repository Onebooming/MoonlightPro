<!--
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-03-02 17:46:38
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-03-02 21:20:54
 * @FilePath: /MoonlightPro/README.md
 * @Description: readme
-->
## 编译项目

./bulid.sh


假设客户端和服务端是基于message.proto格式的数据模型进行通信的
0.在server端实现一个虚基类：DataController类，1）包含一个纯虚函数ProcessAndResponse，入参是序列化数据（request data），出参是序列化数据（response data）；2）包含一个实例化

1.在server端实现一个RequestRouter类：
    1）如果是OperationType operation == REGISTER，则调用register方法处理用户注册，存redis数据库中，返回客户端响应OperationType operation == RESPONSE
    2）如果是OperationType operation == LOGIN，则调用login方法，检查redis数据库是否存在对应的用户名和密码，如果想匹配，则生成唯一的session id（），返回给客户端，返回客户端响应OperationType operation == RESPONSE；
    3）请operation都需要先校验session id，然后根据data_type + opteration 调用对应数据模型处理；

2.server端的所有数据模型都定义一个xxxxDataController的类，用于操作.proto的数据，继承DataController类，以UserInfo和user.proto为例
