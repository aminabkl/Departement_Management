QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcoord.cpp \
    addprof.cpp \
    addsalle.cpp \
    coordinateur.cpp \
    deletecoord.cpp \
    deleteprof.cpp \
    deletesalle.cpp \
    editcoord.cpp \
    editprof.cpp \
    editsalle.cpp \
    main.cpp \
    login.cpp \
    navmenu.cpp \
    prof.cpp \
    salle.cpp \
    signup.cpp

HEADERS += \
    addcoord.h \
    addprof.h \
    addsalle.h \
    coordinateur.h \
    deletecoord.h \
    deleteprof.h \
    deletesalle.h \
    editcoord.h \
    editprof.h \
    editsalle.h \
    login.h \
    navmenu.h \
    prof.h \
    salle.h \
    signup.h

FORMS += \
    addcoord.ui \
    addprof.ui \
    addsalle.ui \
    coordinateur.ui \
    deletecoord.ui \
    deleteprof.ui \
    deletesalle.ui \
    editcoord.ui \
    editprof.ui \
    editsalle.ui \
    login.ui \
    navmenu.ui \
    prof.ui \
    salle.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
