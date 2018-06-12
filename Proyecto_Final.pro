#-------------------------------------------------
#
# Project created by QtCreator 2018-05-25T12:36:09
#
#-------------------------------------------------

QT       += core gui sql  \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto_Final
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ventana.cpp \
    Capucho.cpp \
    Esmad.cpp \
    Madera.cpp \
    Score.cpp \
    multiplayer.cpp \
    login.cpp \
    registro.cpp \
    clasebase.cpp \
    level1.cpp \
    level2.cpp \
    level3.cpp \
    level4.cpp \
    level5.cpp \
    multi.cpp \
    objetos.cpp \
    options.cpp \
    options2.cpp \
    options3.cpp \
    options4.cpp \
    options5.cpp

HEADERS += \
        mainwindow.h \
    ventana.h \
    Capucho.h \
    Esmad.h \
    Madera.h \
    Score.h \
    multiplayer.h \
    login.h \
    registro.h \
    clasebase.h \
    level1.h \
    level2.h \
    level3.h \
    level4.h \
    level5.h \
    multi.h \
    objetos.h \
    options.h \
    options2.h \
    options3.h \
    options4.h \
    options5.h

FORMS += \
        mainwindow.ui \
    ventana.ui \
    multiplayer.ui \
    login.ui \
    registro.ui \
    level1.ui \
    level2.ui \
    level3.ui \
    level4.ui \
    level5.ui \
    multi.ui \
    options.ui \
    options2.ui \
    options3.ui \
    options4.ui \
    options5.ui

RESOURCES += \
    gif.qrc
