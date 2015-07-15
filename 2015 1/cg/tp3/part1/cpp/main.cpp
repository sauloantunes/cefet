#include "scene.h"
#include "raytracer.h"
#include "output.h"
#include <iostream>
#include <sstream>
using namespace std;

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char* argv[]) {
	// Carrega cena do arquivo cujo nome foi passado como o primeiro parâmetro
	cout << "Carregando arquivo: " << argv[1] << endl;
	Scene s = Scene::fromFile(argv[1]);
	RayTracer tracer;


	// Matriz de pixels que serão "coloridos"
	Vector3** pixels = new Vector3*[HEIGHT];
	for (int i = 0; i < HEIGHT; i++) {
		pixels[i] = new Vector3[WIDTH];
	}
	tracer.renderScene(s, pixels, HEIGHT, WIDTH);


	// Transforma os pixels de double (0..1) para byte (0..255)
	unsigned char* buffer = new unsigned char[HEIGHT * (3 * WIDTH)];
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			Vector3* p = &(pixels[i][j]);
			buffer[i*WIDTH*3 + j*3+0] = min((int)(p->r * 255), 255);
			buffer[i*WIDTH*3 + j*3+1] = min((int)(p->g * 255), 255);
			buffer[i*WIDTH*3 + j*3+2] = min((int)(p->b * 255), 255);
		}
	}

	// Escreve um arquivo ppm e outro bmp
	cout << "Salvando arquivos: " << argv[2] << "-cpp.bmp e " << argv[2] << "-cpp.ppm" << endl;
	stringstream bmp, ppm;
	bmp << string(argv[2]) << string("-cpp.bmp");
	ppm << string(argv[2]) << string("-cpp.ppm");

	writeImageBmp(bmp.str().c_str(), WIDTH, HEIGHT, buffer);
	writeImagePpm(ppm.str().c_str(), WIDTH, HEIGHT, buffer);

	return 0;
}
