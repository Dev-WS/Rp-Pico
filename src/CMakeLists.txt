add_executable(src
        main.c
        main.h
        st7789.h
        st7789.c
        )

# pull in common dependencies
target_link_libraries(src pico_stdlib hardware_spi freertos)

# create map/bin/hex file etc.
pico_add_extra_outputs(src)
#pico_add_extra_outputs(include)

# add url via pico_set_program_url
#example_auto_set_url(blink)
