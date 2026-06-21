# 项目目录结构规划 (Directory Structure)

为了保证后期代码的可维护性和模块化，本项目采用标准的 C++ 工程目录结构（将头文件、源文件、数据文件分开）。以下是完整的目录结构设计及说明：

```text
SportsMetting_Manage_System_CPP/
├── bin/                    # 存放最终编译生成的可执行文件，不会提交到Git
├── build/                  # 存放编译时产生的临时中间文件 (.o, .obj等)，不会提交到Git
│
├── data/                   # 专门存放系统运行产生的本地持久化数据文件
│   ├── .gitkeep            # 用于保留 data 空目录
│   ├── item.dat            # （运行时生成）项目数据
│   ├── university.dat      # （运行时生成）参赛学校信息数据
│   └── score.dat           # （运行时生成）运动员成绩数据
│
├── include/                # 存放所有的头文件 (.h / .hpp)
│   ├── models.h            # 核心数据结构定义 (athlete, item, university)
│   ├── input_module.h      # 模块1: 信息输入与报名函数声明
│   ├── match_module.h      # 模块2: 检录与比赛成绩录入函数声明
│   ├── query_module.h      # 模块3: 信息查询与排行榜统计函数声明
│   └── utils.h             # 通用工具函数声明 (菜单UI显示、文件读写、内存释放等)
│
├── src/                    # 存放所有的实现源文件 (.cpp)
│   ├── main.cpp            # 主程序入口，负责系统初始化与主菜单循环调度
│   ├── input_module.cpp    # 模块1的具体逻辑实现
│   ├── match_module.cpp    # 模块2的具体逻辑实现
│   ├── query_module.cpp    # 模块3的具体逻辑实现
│   └── utils.cpp           # 通用工具的具体实现代码
│
├── CMakeLists.txt          # CMake 构建配置文件
├── README.md               # 项目总体说明文档
├── REQUIREMENTS.md         # 整理细化后的业务需求说明
├── REQUIREMENTS.txt        # 原始需求记录材料
├── TASK.md                 # 开发任务清单（包含 Checklist）
├── .gitignore              # Git 忽略配置
└── DIRECTORY_STRUCTURE.md  # 本目录结构说明文件 (当前文件)
```

## 结构设计优势

1. **模块与职责分离**：将复杂的系统解耦为 `input` (信息录入), `match` (比赛成绩), `query` (查询统计) 三个独立模块，防止功能堆积在单一文件内，增强可读性。
2. **读写数据隔离**：程序产生的持久化 txt 数据统一放在 `data/` 目录，从工程中剥离开来，防止由于程序的频繁读写造成代码区文件状态紊乱，且利用 `.gitignore` 省去了追踪这些动态数据的麻烦。
3. **符合C++工程标准**：`src` (源文件) 加 `include` (头文件) 双独立目录是最经典的 C/C++ 协作项目设计规范，对于后期借助 CMake 等构建工具，或迁移至不同平台（Linux/Windows）极其友好。
