#include <igl/readOFF.h>
#include <igl/opengl/glfw/Viewer.h>
#include <iostream>
#include "tutorial_shared_path.h"
#include <igl/png/writePNG.h>
#include <igl/png/readPNG.h>

// This function is called every time a keyboard button is pressed


int main(int argc, char *argv[])
{
  // Load a mesh in OFF format
  

  

  // Plot the mesh and register the callback
  igl::opengl::glfw::Viewer viewer;
  viewer.load_mesh_from_file(std::string(TUTORIAL_SHARED_PATH) + "/cube.obj");
  unsigned int left_view, right_view;

  viewer.callback_init = [&](igl::opengl::glfw::Viewer &)
  {
	  viewer.core().viewport = Eigen::Vector4f(0, 0, 640, 800);
	  left_view = viewer.core_list[0].id;
	  right_view = viewer.append_core(Eigen::Vector4f(640, 0, 640, 800));
	  return false;
  };

  viewer.callback_post_resize = [&](igl::opengl::glfw::Viewer &v, int w, int h) {
	  v.core(left_view).viewport = Eigen::Vector4f(0, 0, w / 2, h);
	  v.core(right_view).viewport = Eigen::Vector4f(w / 2, 0, w - (w / 2), h);
	  return true;
  };
  viewer.launch();
}




 





















