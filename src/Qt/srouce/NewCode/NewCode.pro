QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle
LIBS += -lmariadbcpp

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

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

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

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
    RelationalBroker.h \
    TimeInfo.h

INCLUDEPATH += ../../include
