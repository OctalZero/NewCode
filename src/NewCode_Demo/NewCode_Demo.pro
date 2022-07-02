TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt
LIBS+=-lmariadbcpp

SOURCES += \
        Blog.cpp \
        BlogBrokeroker.cpp \
        BlogInterface.cpp \
        BlogProxy.cpp \
        BlogSocialControl.cpp \
        Comment.cpp \
        CommentBroker.cpp \
        CommentInterface.cpp \
        CommentProxy.cpp \
        Material.cpp \
        MaterialBroker.cpp \
        MaterialInterface.cpp \
        MaterialProxy.cpp \
        Netizen.cpp \
        NetizenBroker.cpp \
        NetizenInterface.cpp \
        NetizenProxy.cpp \
        RelationalBroker.cpp \
        main.cpp

HEADERS += \
    Blog.h \
    BlogBroker.h \
    BlogInterface.h \
    BlogProxy.h \
    BlogSocialControl.h \
    Comment.h \
    CommentBroker.h \
    CommentInterface.h \
    CommentProxy.h \
    Material.h \
    MaterialBroker.h \
    MaterialInterface.h \
    MaterialProxy.h \
    Netizen.h \
    NetizenBroker.h \
    NetizenInterface.h \
    NetizenProxy.h \
    RelationalBroker.h
