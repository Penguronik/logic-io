QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Backend/circuitcomponent.cpp \
    Backend/components.cpp \
    Backend/componenttreeitem.cpp \
    Backend/componenttreemodel.cpp \
    Backend/gates.cpp \
    Backend/pinbase.cpp \
    Backend/pinin.cpp \
    Backend/pinout.cpp \
    Backend/wire.cpp \
    Frontend/graphicscircuitcomponent.cpp \
    Frontend/graphicscircuitcomponent_copy.cpp \
    Frontend/graphicscomponents.cpp \
    Frontend/graphicsgates.cpp \
    Frontend/graphicspinbase.cpp \
    Frontend/graphicspinin.cpp \
    Frontend/graphicspinout.cpp \
    Frontend/graphicswire.cpp \
    Frontend/main.cpp \
    Frontend/mainwindow.cpp \
    Frontend/scene.cpp \
    Frontend/view.cpp

HEADERS += \
    Backend/circuitcomponent.h \
    Backend/componenttreeitem.h \
    Backend/componenttreemodel.h \
    Backend/pinbase.h \
    Backend/pinin.h \
    Backend/pinout.h \
    Backend/wire.h \
    Frontend/constants.h \
    Frontend/graphicscircuitcomponent.h \
    Frontend/graphicscomponents.h \
    Frontend/graphicsgates.h \
    Frontend/graphicspinbase.h \
    Frontend/graphicspinin.h \
    Frontend/graphicspinout.h \
    Frontend/graphicswire.h \
    Frontend/mainwindow.h \
    Frontend/scene.h \
    Frontend/view.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Backend/SavedComponents.json \
    Frontend/types_reference

resources.files = \
    icons/AND_Gate.png \
    icons/OR_Gate.png \
    icons/NOT_Gate.png \
    icons/NAND_Gate.png \
    icons/NOR_Gate.png \
    icons/XOR_Gate.png \
    icons/XNOR_Gate.png \
    icons/BUFFER_Gate.png \
    icons/Trash_Icon.png \
    icons/Folder_Icon.png # get screenshots of icons and use them for each circuit icon from dropdown
resources.prefix = /

RESOURCES = resources
