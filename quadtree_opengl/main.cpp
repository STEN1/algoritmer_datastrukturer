#include "quadtree.h"
#include "timer.h"
#include "sprite.h"
#include "shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <thread>
#include <string>




constexpr int window_width = 1024;
constexpr int window_hight = 768;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void init_glfw();
bool create_opengl_window(GLFWwindow*& window);
void input(GLFWwindow* window);
void fancy_clear(double delta_time);
double wait_for_delta_time();

int main()
{
	init_glfw();
	GLFWwindow* window;
	if (create_opengl_window(window)) std::cout << "Window created" << std::endl;

	Shader shader("shader.vert", "shader.frag");
	Rect r = {
	{-1, -1},
	{1, -1},
	{1, 1},
	{-1, 1},
	};

	QuadNode gameworld{ r, &shader };
	gameworld.print_corners();
	std::cout << std::endl << std::boolalpha;
	srand(time(nullptr));
	std::vector<GameObject*> gameobjects;
	for (size_t i = 0; i < 64; i++)
	{
		std::string name;
		(rand() % 2) ? name = "Adrian" : name = "Espen";
		Vector2d pos = {
			(((double)rand() / (double)RAND_MAX) - 0.5) * 2.0,
			(((double)rand() / (double)RAND_MAX) - 0.5) * 2.0
		};
		auto gameobject = new GameObject{ name, pos , &shader, "assets/Ship04.png" };
		gameobjects.push_back(gameobject);
		if (auto [node, confirmation] = gameworld.insert_gameobject(gameobject); confirmation)
		{
			std::cout << "inserted gameobject: " << name << ' ' << pos << " in: ";
			node->print_corners();
		}
		else
		{
			std::cout << "failed insert for pos: " << pos << std::endl;
		}
	}
	gameworld.print_corners();
	std::cout << std::endl;
	gameworld.print_leaf_corners();

	std::string windowtitle = "OpenGL Adventure! fps: ";

	// Disable v-sync
	// glfwSwapInterval(0);

	while (!glfwWindowShouldClose(window))
	{
		double delta_time = wait_for_delta_time();

		std::string titlewithfps = windowtitle + std::to_string(1.0 / delta_time);

		glfwSetWindowTitle(window, titlewithfps.c_str());
		input(window);

		fancy_clear(delta_time);
		gameworld.render_world();
		//gameworld.render_gameobjects();
		for (auto gameobject : gameobjects)
			gameobject->sprite.Render();

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void init_glfw()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef MAC // mac needs this acording to learnopengl.com
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

bool create_opengl_window(GLFWwindow*& window)
{
	// create opengl window with glfw
	window = glfwCreateWindow(window_width, window_hight, "OpenGL Adventure!", NULL, NULL);
	if (!window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	// init opengl functions with glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}

	// where and at what resolution to render inside the window
	glViewport(0, 0, window_width, window_hight);

	// set a function that gets called when resizing the window
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/*
	* There are many callbacks functions we can set to register our own functions.
	* For example, we can make a callback function to process joystick input changes,
	* process error messages etc. We register the callback functions after we've created the window and before the render loop is initiated.
	*
	* https://learnopengl.com/Getting-started/Hello-Window
	*/

	std::cout << "GL version: " << GLVersion.major << "." << GLVersion.minor << std::endl;
	return true;
}


double wait_for_delta_time()
{
	static double max_fps = 100000.0;
	static Timer timer;
	while (timer.GetDelta() < 1.0 / max_fps)
	{
	}
	return timer.GetDeltaAndSetStartCountNow();
}

void input(GLFWwindow* window)
{
	glfwPollEvents();
	if (glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(window, true);
	}
}

void fancy_clear(double delta_time)
{
	static float clear_color_r = 0.f;
	static float clear_color_g = 0.3f;
	static float clear_color_b = 0.6f;
	clear_color_r += (float)delta_time / 2.f;
	clear_color_g += (float)delta_time / 2.f;
	clear_color_b += (float)delta_time / 2.f;
	if (clear_color_r > 1.f) clear_color_r = 0.f;
	if (clear_color_g > 1.f) clear_color_g = 0.f;
	if (clear_color_b > 1.f) clear_color_b = 0.f;
	glClearColor(clear_color_r, clear_color_g, clear_color_b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}