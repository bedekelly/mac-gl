# Mac GL

I'm working through the OpenGL SuperBible v.7, using GLFW version 3 on MacOS.

I couldn't get the example code provided with the book working -- probably something to do with different OpenGL versions, or maybe just running on a Mac. So I'm writing all my own code for things like startup, loading shaders, timers and so on.

I'm also making any changes necessary from OpenGL 4.5 to version 4.1, since that's the latest version MacOS Sierra supports. So far, that's only meant one change: `glCreateVertexArrays` -> `glGenVertexArrays`.

Every discrete example of an application in the book gets its own branch in this repository. Here's what I have so far:


### Chapters 1-3: "Following The Pipeline"

1. [Opening a window and setting the clear colour](https://github.com/bedekelly/mac-gl/tree/base)
2. [Making a colour fade with a GLFW timer](https://github.com/bedekelly/mac-gl/tree/fading-colour)
3. [Drawing a point using shaders](https://github.com/bedekelly/mac-gl/tree/shaders)
4. [Drawing a triangle to the screen](https://github.com/bedekelly/mac-gl/tree/triangle)
5. [Moving the triangle using "in" variables](https://github.com/bedekelly/mac-gl/tree/triangle-offset)
6. [Passing data from the Vertex Shader to the Fragment Shader](https://github.com/bedekelly/mac-gl/tree/passing-data)
7. [Loading fragment and vertex shaders from disk](https://github.com/bedekelly/mac-gl/tree/load-shaders-from-file)
8. [Tessellation control and evaluation shaders](https://github.com/bedekelly/mac-gl/tree/tessellation-control)
9. [Geometry shader emitting vertices](https://github.com/bedekelly/mac-gl)
10. [Calculating fragment colour from position](https://github.com/bedekelly/mac-gl/tree/fragment-colour-from-position)
11. [Interpolating colours between vertices](https://github.com/bedekelly/mac-gl/tree/interpolate-colours)


To build the project, you may need to run `brew install glfw3 --static`. Then just run `make` to build the project, making sure you have a `build` directory. The binary is written to `build/main.out`.


**System specs**

* 15" rMBP, mid 2015
* Intel Iris Pro 1536 MB
* Sierra 10.12.3
