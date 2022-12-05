// #include <iostream>
// #include <GLFW/glfw3.h>

// int main(){
// 	std::cout << "Hello CMake!" << std::endl;
// #ifdef WINDOWS_BUILD
// 	std::cout << "Windows" << std::endl;
// #elif defined LINUX_BUILD
// 	std::cout << "Linux" << std::endl;
// #else
// 	std::cout << "Unknown system" << std::endl;
// 	return __LINE__;
// #endif	
// 	return 0;
// }

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// #define GLM_FORCE_RADIANS
// #define GLM_FORCE_DEPTH_ZERO_TO_ONE
// #include <glm/vec4.hpp>
// #include <glm/mat4x4.hpp>

#include <iostream>

int main() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported\n";

    // glm::mat4 matrix;
    // glm::vec4 vec;
    // auto test = matrix * vec;

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;
}