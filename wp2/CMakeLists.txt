project(wp2)

add_library(${PROJECT_NAME} SHARED db.cpp LabelWidgetPair.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
    ${Boost_THREAD_LIBRARY}
    ${Boost_SYSTEM_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_SIGNALS_LIBRARY}
    ${Boost_DATE_TIME_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${Boost_REGEX_LIBRARY}
    ${OPENSSL_LIBRARIES} ${wt} ${wtdbo} ${wtdbopostgres}
)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)
install(FILES BaseApp.hpp db.hpp LabelWidgetPair.hpp DESTINATION include/wp2)
