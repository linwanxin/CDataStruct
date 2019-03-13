cmake_minimum_required(VERSION 3.12)
project(CDataStruct)

set(CMAKE_CXX_STANDARD 11)

add_executable(CDataStruct main.cpp Queue/SqQueue.cpp Queue/SqQueue.h Queue/LinkQueue.cpp Queue/LinkQueue.h Queue/QElemType.h Question/DanceQuestion.cpp Stack/ElemType.h Stack/LinkStack.cpp Stack/LinkStack.h Question/Shuzhi.cpp Question/Kuohao.cpp Question/biaodashi.cpp String/String.h String/ModelPiPei.cpp Question/BingDu.cpp Tree/BiTree.h Tree/TElemType.h Tree/BiTree.cpp Question/HuffmanCode.cpp Question/BiaoDaShiTree.cpp Question/BiaoDaShi.h Map/Map.h Map/Map.cpp Map/MinTree.cpp Map/MostShortRoad.cpp)