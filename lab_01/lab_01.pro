QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canvas.cpp \
    errors.cpp \
    event_handler.cpp \
    facet.cpp \
    facets.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    point.cpp \
    points.cpp

HEADERS += \
    canvas.h \
    errors.h \
    event_handler.h \
    facet.h \
    facets.h \
    mainwindow.h \
    model.h \
    point.h \
    points.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
