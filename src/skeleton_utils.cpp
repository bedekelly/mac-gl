#include <iostream>
#include <string>
#include "GLFW/glfw3.h"
#include "skeleton_utils.h"
#include <fstream>
#include <sstream>


/**
 * A simple error callback for GLFW to run whenever it encounters a problem.
 */
void simpleErrorCallback(int errorCode, const char* errorMessage) {
  std::cout << "Error (code" << errorCode << "): \""
	    << errorMessage << "\"."<<std::endl;
}


/**
 * Create, initialize and return a GLFW window. The OpenGL context for it
 * should be made current.
 */
GLFWwindow* createWindow(const char* title) {
  GLFWwindow* window;
  glfwSetErrorCallback(simpleErrorCallback);

  if (!glfwInit())
    exit(EXIT_FAILURE);

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window = glfwCreateWindow(640, 480, title, NULL, NULL);
  if (!window)
    dirtyExit();

  // Todo: Setup other callbacks like key, mouse cursor position and so on.

  // Make sure OpenGL stores state about this current window.
  glfwMakeContextCurrent(window);

  // Enable V-sync.
  glfwSwapInterval(1);

  // Set the default clear-color to a nice blue.
  glClearColor(0.1, 0.3, 0.5, 1.0);

  return window;
}



/**
 * When we're finished with a program using a GLFW window, we can
 * terminate this window and exit cleanly.
 */
void cleanExit(GLFWwindow* window) {
  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}


/**
 * Used in the event of any errors occurring, this function will
 * terminate GLFW and exit the program without using a window handle.
 */
void dirtyExit() {
  glfwTerminate();
  exit(EXIT_FAILURE);
}


/**
 * Load the source code for a shader with a given filename.
 */
std::string loadShaderSource(std::string filename) {
  std::string line;
  std::string total;
  std::ifstream myfile("src/shaders/" + filename);

  if (myfile.is_open()) {
    while (std::getline(myfile, line)) {
      total.append(line);
      total.append("\n");
    }
    myfile.close();
  } else {
    std::cerr << "Unable to open file." << std::endl;
  }

  return total;
}


GLuint compileShader(GLenum shaderType, std::string shaderFile) {

  // Read in the shader source from disk:
  std::string shaderStr = loadShaderSource(shaderFile);

  // Cast the source string to a format GL will recognise:
  const GLchar *shaderSource = const_cast<GLchar*>(shaderStr.c_str());

  // Create and compile the shader:
  GLuint shaderID = glCreateShader(shaderType);
  glShaderSource(shaderID, 1, &shaderSource, NULL);
  glCompileShader(shaderID);

  // Display the shader's compilation info log:
  GLint logLength;
  glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);
  GLchar infoLog[logLength];
  glGetShaderInfoLog(shaderID, logLength, NULL, infoLog);
  std::cout << infoLog << std::endl;

  return shaderID;
}
