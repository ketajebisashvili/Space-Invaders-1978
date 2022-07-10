#include <cstdio>
#include <GL/glew.h> //function loading library
#include <GLFW/glfw3.h>

#define GL_ERROR_CASE(glerror)\
    case glerror: snprintf(error, sizeof(error), "%s", #glerror)


void error_callback(int error, const char* description) //error callback which puts error description into stderr
{
   GLenum err;
    while((err = glGetError()) != GL_NO_ERROR){
        char error[128];

        switch(err) {
            GL_ERROR_CASE(GL_INVALID_ENUM); break;
            GL_ERROR_CASE(GL_INVALID_VALUE); break;
            GL_ERROR_CASE(GL_INVALID_OPERATION); break;
            GL_ERROR_CASE(GL_INVALID_FRAMEBUFFER_OPERATION); break;
            GL_ERROR_CASE(GL_OUT_OF_MEMORY); break;
            default: snprintf(error, sizeof(error), "%s", "UNKNOWN_ERROR"); break;
        }

    fprintf(stderr, "Error: %s\n", description);
    }
}

int main()
{
    glfwSetErrorCallback(error_callback);

    if(!glfwInit()) //initialize GLFW library
     {
    return -1;
     }

    GLFWwindow* window;

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //Context at least version 3.3
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    window = glfwCreateWindow(640, 480, "Space Invaders 1978", NULL, NULL); //create a window
    if(!window)
     {
    glfwTerminate(); //Let GLFW destroy its resources if there where any problems creating the window.
    return -1;
     }
    glfwMakeContextCurrent(window);

    GLenum err = glewInit(); //initialize GLEW library 
    if(err != GLEW_OK)
     {
    fprintf(stderr, "Error initializing GLEW.\n");
    glfwTerminate();
    return -1;
     }

     int glVersion[2] = {-1, 1};
     glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
     glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);
     printf("Using OpenGL: %d.%d\n", glVersion[0], glVersion[1]);


    glClearColor(1.0, 0.0, 0.0, 1.0); //very simple inginite gameloop
    while (!glfwWindowShouldClose(window))
       {
         glClear(GL_COLOR_BUFFER_BIT);
         glfwSwapBuffers(window);
         glfwPollEvents();
       }
    



}


