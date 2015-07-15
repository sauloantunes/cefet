#include "raytracer.h"
#include "vector.h"
#include <limits>

#include <iostream>
using namespace std;


// MÉTODO que gera um "raio inicial" (ou primário): aquele que parte do olho (câmera) e passa pelo pixel (i,j)
Ray RayTracer::generateInitialRay(Camera& camera, int row, int column, const int height, const int width) {
	Vector3 gridPointInCameraSpace = Vector3(column - width/2.0f, row - height/2.0f, -1);
	Ray ray;
	ray.p0 = camera.eye;
	ray.v = Vector3(gridPointInCameraSpace.diff(ray.p0));
	ray.v.normalize();
	return ray;
}

Vector3 RayTracer::castRay(Scene& scene, Ray& ray) {
	// Para todos os objetos da cena, verifica se o raio o acerta e pega aquele
	// que foi atingido primeiro (menor "t")
	double minimumT = numeric_limits<double>::max();
	Vector3 intersectionNormal;
	Vector3 intersectionPoint;
	Object* closestObjectHit = NULL;
	for (int c = 0; c < scene.numObjs; c++) {
		Object* currentObject = &(scene.objects[c]);
		if (currentObject->intersectsWith(ray)) {
			if (ray.intersectionT < minimumT) {
				minimumT = ray.intersectionT;
				intersectionNormal = ray.intersectionNormal;
				intersectionPoint = ray.intersectionPoint;
				closestObjectHit = currentObject;
			}
		}
	}


	// Verifica se um objeto foi atingido. Se tiver sido, colore o pixel
	if (closestObjectHit != NULL) {
		// material e pigmento deste objeto
		Material* material = closestObjectHit->material;
		Pygment*  pygment  = closestObjectHit->pygment;

        // Em vez de retornar um vetor com uma cor constante, criamos uma variável
		// onde construiremos (iremos somando) a cor iluminada/sombreada
		Vector3 shadingColor = Vector3(1,1,1);

        //---------------------------------------------------------------------------------------------------------
		// Aqui começamos a implementar a equaçăo de Phong (e armazenar o resultado parcial em shadingColor)
		// Sugiro seguir as anotaçőes do prof. David Mount (p. 83)

		// Exercício 1: Coloque a compnente ambiente  na cor resultante
        // luz ambiente: coefAmbienteLuz*corMat
		shadingColor = (pygment->color1).mult(material->ambientCoefficient);
		
		// Um objeto foi atingido
		// Verificamos se as fontes de luz estão iluminando este objeto
		for (int c = 0; c < scene.numLights; c++) {


			Light* light = &(scene.lights[c]);

            // Para verificar,
			// Exercício 2: crie um raio do ponto de interseção com o objeto até a fonte de luz
			Ray raio;
			raio.p0 = intersectionPoint;
			raio.v = (light->position).diff(intersectionPoint);
			raio.v.normalize();



            // Verificamos se o raio atinge algum objeto ANTES da fonte de luz
			// Se for o caso, esta fonte de luz (c) não contribui para a luz do objeto
            bool hitsAnotherObjectBeforeLight = false;
			// Exercício 3: Percorra os objetos da cena verificando se houve interseção com eles,
			// antes da interseção com a fonte luminosa

            for (int i = 0; i < scene.numObjs; ++i){
            	Object* currentObject = &(scene.objects[c]);

            	if(currentObject == closestObjectHit)
            		continue;

            	if(currentObject->intersectsWith(raio)){
            		hitsAnotherObjectBeforeLight = true;
            		break;
            	}
            }








			if (!hitsAnotherObjectBeforeLight) {

                // Exercício 4: Devemos terminar de calcular a equaçăo de Phong (atenuação, componente difusa e comp. especular)
				// e somar o resultado na cor resultante (shadingColor)


				// PASSO 1: Definição das variáveis

				//	Coeficientes do Material
				double pa = material->ambientCoefficient;
				double pd = material->diffuseCoefficient;
				double ps = material->specularCoefficient;
				double alpha = material->specularExponent;

				// Coeficientes de Atenuação
				double ca = light->constantAttenuation;
				double la = light->linearAttenuation;
				double qa = light->quadraticAttenuation;

				// Distancia entre o ponto de interseção e a fonte de luz
				Vector3 v1 = (light->position).diff(intersectionPoint);
				double di = v1.norm();

				// Cor do Objeto
				Vector3 C = pygment->color1;

				// Cor ambiente
				Vector3 Li = light->color;

				// PASSO 2: Definição dos vetores

				Vector3 vn, vh, vl, vv, vr;

				// Vetor normal
				vn = intersectionNormal;
				vn.normalize();

				// Vetor que aponta para a luz
				vl = raio.v;
				vl.normalize();

				// Vetor que aponta para o observador
				vv = scene.camera.eye.diff(intersectionPoint);
				vv.normalize();
				
				// halfway-vector
				vh = vl.add(vv);
				vh.normalize();

				// reflection-vector
				vr = vn.mult(vn.dotProduct(vl)*2);
				vr = vr.diff(vl);
				vr.normalize();


				// PASSO 3: Cálculo

				// Difusa
				Vector3 Id;
				Id = Li.cwMult(C);
				Id = Id.mult(max(0.0, vn.dotProduct(vl)) * pd);

				shadingColor = shadingColor.add(Id);

				// Especular
				Vector3 Is;
				Is = Li.mult(ps);
				Is = Is.mult(pow(max(0.0, vr.dotProduct(vv)),alpha));

				shadingColor = shadingColor.add(Is);

			}
		}

		// trunca a cor: faz r, g e b ficarem entre 0 e 1, caso tenha excedido
		shadingColor.truncate();
		return shadingColor;
	}

	// nada foi atingido. Retorna uma cor padrão (de fundo)
	return Vector3(0, 0, 0);
}


// MÉTODO que renderiza uma cena, gerando uma matriz de cores.
// Parâmetros:
//   1. Scene& scene: um objeto do tipo Scene contendo a descrição da cena (ver scene.h)
//   2. Vector3** pixels: uma matriz de cores (representadas em Vector3 - r,g,b) que vamos "colorir"
//   3. const int height: altura da imagem que estamos gerando (e.g., 600px)
//   4. const int width: largura da imagem que estamos gerando (e.g., 800px)
void RayTracer::renderScene(Scene& scene, Vector3** pixels, const int height, const int width) {

	// Para cada pixel, lança um raio
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			// cria um raio primário
			Ray ray = generateInitialRay(scene.camera, i, j, height, width);

			// lança o raio e recebe a cor
			Vector3 color = this->castRay(scene, ray);

			// salva a cor na matriz de cores
			pixels[i][j] = color;
		}
	}
}
