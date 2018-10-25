# Opengl + SDL2 + GLEW + meson testbed 

## Overview

Simple testbed project that can be used to start hacking on OpenGL/SDL2.

* Uses GLEW and SDL2
* Pulls dependencies if they are not found by pkgconfig via meson wrap system

## Build

cd sdl-gl-meson-testbed
meson build
cd build
ninja
