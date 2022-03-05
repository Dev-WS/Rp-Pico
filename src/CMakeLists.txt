add_executable(src
        main.c
        )

# pull in common dependencies
target_link_libraries(src pico_stdlib freertos)

# create map/bin/hex file etc.
pico_add_extra_outputs(src)

# add url via pico_set_program_url
#example_auto_set_url(blink)
