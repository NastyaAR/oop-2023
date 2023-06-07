QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractloadcontroller.cpp \
    basebuilder.cpp \
    basecameraimplementor.cpp \
    basedirector.cpp \
    baseloader.cpp \
    basematrix.cpp \
    basemodelimplementor.cpp \
    basesceneimplementor.cpp \
    camera.cpp \
    camerabuilder.cpp \
    cameracommand.cpp \
    cameradirector.cpp \
    cameraimplementor.cpp \
    composite.cpp \
    drawmanager.cpp \
    drawmanagercreator.cpp \
    edge.cpp \
    errors.cpp \
    facade.cpp \
    filemodelloader.cpp \
    loadmanager.cpp \
    loadmanagercreator.cpp \
    main.cpp \
    mainwindow.cpp \
    matrix_base.cpp \
    mediator.cpp \
    model.cpp \
    modelbuilder.cpp \
    modelcommand.cpp \
    modeldirector.cpp \
    modelimplementor.cpp \
    modelloadcontroller.cpp \
    modelloadcontrollercreator.cpp \
    modelstructure.cpp \
    object.cpp \
    point.cpp \
    qtdrawer.cpp \
    qtdrawerfactory.cpp \
    scene.cpp \
    scenebuilder.cpp \
    scenecommand.cpp \
    scenedirector.cpp \
    sceneimplementor.cpp \
    sceneloadcontroller.cpp \
    sceneloadcontrollercreator.cpp \
    scenemanager.cpp \
    scenemanagercreator.cpp \
    transformmanager.cpp \
    transformmanagercreator.cpp

HEADERS += \
    BaseCommand.h \
    BaseManager.h \
    abstractdrawer.h \
    abstractdrawerfactory.h \
    abstractloadcontroller.h \
    basebuilder.h \
    basecameraimplementor.h \
    basecameraloader.h \
    basedirector.h \
    baseloader.h \
    basematrix.h \
    basemodelimplementor.h \
    basemodelloader.h \
    basesceneimplementor.h \
    camera.h \
    camerabuilder.h \
    cameracommand.h \
    cameradirector.h \
    cameraimplementor.h \
    composite.h \
    const_matrix_iterator.h \
    const_matrix_iterator.hpp \
    drawmanager.h \
    drawmanagercreator.h \
    edge.h \
    errors.hpp \
    facade.h \
    filemodelloader.h \
    loadmanager.h \
    loadmanagercreator.h \
    mainwindow.h \
    matrix.h \
    matrix.hpp \
    matrix_base.hpp \
    matrix_iterator.h \
    matrix_iterator.hpp \
    mediator.h \
    model.h \
    modelbuilder.h \
    modelcommand.h \
    modeldirector.h \
    modelimplementor.h \
    modelloadcontroller.h \
    modelloadcontrollercreator.h \
    modelstructure.h \
    myerror.h \
    object.h \
    point.h \
    qtdrawer.h \
    qtdrawerfactory.h \
    scene.h \
    scenebuilder.h \
    scenecommand.h \
    scenedirector.h \
    sceneimplementor.h \
    sceneloadcontroller.h \
    sceneloadcontrollercreator.h \
    scenemanager.h \
    scenemanagercreator.h \
    transformmanager.h \
    transformmanagercreator.h \
    visitor.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
