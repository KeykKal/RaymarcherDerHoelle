#include <iostream>
#include <iterator>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include "scene.h"
#include "utils.h"


void print_color(const std::string& text, int r, int g, int b, bool background = false);
void startColor(int r, int g, int b, bool background = false);
void endColor(bool background=false);
int windowWidth = 500, windowHeight = 500;

// "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'.";

int main() {

    // std::string test = "\u2588\u2589";
    // std::cout << "Hello " << "\u2589" << "\u258A" << "\u258B" << "\u258C" << "\u258D" << "\u258E" << "\u258F" << "\n";
    // std::cout << "";
    Scene s;
    
    s.render();
    

    return 0;
}


