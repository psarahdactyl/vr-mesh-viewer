#include <igl/readOFF.h>
#include <igl/opengl/glfw/Viewer.h>
#include <iostream>
#include "tutorial_shared_path.h"
#include <igl/png/writePNG.h>
#include <igl/png/readPNG.h>



int main(int argc, char *argv[])
{
	Eigen::MatrixXd V;
	Eigen::MatrixXi F;
	igl::readOFF(TUTORIAL_SHARED_PATH "/bunny.off", V, F);

	std::cerr << "Press 1 to render the scene and save it in a png." << std::endl;
	std::cerr << "Press 2 to load the saved png and use it as a texture." << std::endl;

	// Plot the mesh and register the callback
	igl::opengl::glfw::Viewer viewer;
	viewer.callback_key_down = &key_down;
	viewer.data().set_mesh(V, F);
	viewer.launch();
}




 





















