gl_dep = dependency('gl')

sdl_dep = dependency('sdl2', required : false)
if not sdl_dep.found()
        sdl2 = subproject('sdl2')
        sdl_dep = sdl2.get_variable('sdl2_dep')
endif

glew_dep = dependency('glew', required : false)
if not glew_dep.found()
        glew= subproject('glew')
        glew_dep = glew.get_variable('glew_dep')
endif

sources = [
        'main.cpp',
]

executable(
        'example',
        [ sources ],
        dependencies : [ gl_dep, glew_dep, sdl_dep ],
        install: true
)


