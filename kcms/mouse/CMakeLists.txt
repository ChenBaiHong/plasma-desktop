if(NOT X11_Xinput_FOUND)
    message(FATAL_ERROR "Xinput not found")
endif()

# KI18N Translation Domain for this library
add_definitions(-DTRANSLATION_DOMAIN=\"kcmmouse\")

add_subdirectory( misc )

## Add common files here.
set(common_SRCS
    inputbackend.cpp
)

include(ECMQtDeclareLoggingCategory)
ecm_qt_declare_logging_category(common_SRCS
    HEADER
        logging.h
    IDENTIFIER
        KCM_MOUSE
    CATEGORY_NAME
        kcm_mouse
    DEFAULT_SEVERITY
        Critical
)

set(klauncher_xml ${KINIT_DBUS_INTERFACES_DIR}/kf5_org.kde.KLauncher.xml)
qt5_add_dbus_interface(common_SRCS ${klauncher_xml} klauncher_iface)

include(backends/x11.cmake)
include(backends/kwin_wl.cmake)

########### next target ###############

add_executable(kapplymousetheme
    kapplymousetheme.cpp
    ${common_SRCS}
    ${backend_SRCS}
)

target_link_libraries(kapplymousetheme
    ${backend_LIBS}
    Qt5::Gui
    Qt5::DBus
    KF5::CoreAddons
    KF5::ConfigCore
    KF5::I18n
)

install(TARGETS kapplymousetheme ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

########### next target ###############

set(common_SRCS
    ${common_SRCS}
    plugin.cpp
    kcm/configcontainer.cpp
    kcm/configplugin.cpp
    kcm/libinput/libinput_config.cpp
    kcm/xlib/xlib_config.cpp
)

ki18n_wrap_ui(common_SRCS kcm/xlib/kcmmouse.ui)

qt5_add_resources( common_SRCS kcm/resources.qrc )

add_library(kcm_mouse MODULE
    ${common_SRCS}
    ${backend_SRCS}
)

target_link_libraries(kcm_mouse
    ${backend_LIBS}
    KF5::KCMUtils
    KF5::I18n
    KF5::KIOCore
    KF5::KIOWidgets
    KF5::Declarative

    Qt5::DBus
    Qt5::QuickWidgets
)

install(TARGETS kcm_mouse  DESTINATION ${KDE_INSTALL_PLUGINDIR} )

########### install files ###############

install( FILES mouse.desktop  DESTINATION  ${KDE_INSTALL_KSERVICES5DIR} )
