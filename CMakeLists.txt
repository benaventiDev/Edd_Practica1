cmake_minimum_required(VERSION 3.15)
project(EDDPractica1)

set(CMAKE_CXX_STANDARD 14)
set(LIB_LOCATION C:/MinGW64/x86_64-w64-mingw32/include/pdcurs36/wincon)


add_executable(EDDPractica1 main.cpp  edd/node.h edd/stack.h edd/queue.h edd/linkedList.h edd/doubleLinkedList.h
        edd/circularLinkedList.h
        editor/Buffer.h editor/Buffer.cpp editor/EditorFirst.h editor/EditorFirst.cpp
        editor/TBuffer.h editor/TBuffer.cpp editor/Editor.cpp editor/Editor.h)


target_link_libraries(EDDPractica1  ${LIB_LOCATION}/pdcurses.a)