cmake_minimum_required(VERSION 3.4.1)
add_library( # 生成的so库名称，此处生成的so文件名称是libnative-lib.so
             native-lib
             # SHARED是动态库，会被动态链接，在运行时被加载
             # STATIC：静态库，是目标文件的归档文件，在链接其它目标的时候使用
             # MODULE：模块库，是不会被链接到其它目标中的插件
             SHARED
             # 资源路径是相对路径，相对于本CMakeLists.txt所在目录
             src/main/cpp/native-lib.cpp )
# 从系统查找依赖库
find_library( # android系统每个类型的库会存放一个特定的位置，而log库存放在log-lib中
              log-lib
              # android系统在c环境下打log到logcat的库
              log )
# 配置库的链接（依赖关系）
target_link_libraries( # 目标库
                       native-lib
                       # 依赖于
                       ${log-lib} )