project(soundkonverter_replaygain_vorbisgain)

find_package(KF5 REQUIRED COMPONENTS WidgetsAddons)

set(soundkonverter_replaygain_vorbisgain_SRCS
   soundkonverter_replaygain_vorbisgain.cpp
)

add_library(soundkonverter_replaygain_vorbisgain MODULE ${soundkonverter_replaygain_vorbisgain_SRCS})
target_link_libraries(soundkonverter_replaygain_vorbisgain KF5::WidgetsAddons soundkonvertercore)

########### install files ###############

install(TARGETS soundkonverter_replaygain_vorbisgain DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES soundkonverter_replaygain_vorbisgain.desktop DESTINATION ${SERVICES_INSTALL_DIR})
