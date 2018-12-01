#include <stdio.h>
#include <ctype.h>
#include "a4.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

PIXEL *generate_random_image(int width, int height, int max_color)
{

  int NumPixels = height*width;
  PIXEL *temp2;
  temp2 = (PIXEL *)malloc(NumPixels*sizeof(PIXEL));

  for(int i=0;i<NumPixels;i++)
  {

    int randred = (rand() % (max_color+1));
    int randgreen = (rand() % (max_color+1));
    int randblue = (rand() % (max_color+1));

    temp2[i].r=randred;
    temp2[i].g=randgreen;
    temp2[i].b=randblue;

  }

  return temp2;
}

Individual *generate_population(int population_size ,int width ,int height ,int max_color)
{

  Individual *pop;
  pop = (Individual *)malloc(population_size*sizeof(Individual));
  PIXEL *image;

  for(int i =0; i<population_size;i++)
  {
    image = generate_random_image(width, height, max_color);
    PPM_IMAGE temp;
    temp.data = image;
    temp.height = height;
    temp.width = width;
    temp.max_color = max_color;
    pop[i].image = temp;
  }

  return pop;

}
