/* Programming Abstractions in C++
 *
 * Exercise 08-13
 *
 * Many of Mondrian’s geometrical paintings fill in the rectangular regions with
 * some color, as in his “Composition with Color Planes and Gray Lines 1”
 * shown in Figure 8-6. Extend the Mondrian program from the text so that it
 * fills in some fraction of the rectangular regions it creates with randomly
 * chosen colors.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <stdio.h>

#include "../../StanfordCPPLib/include/gwindow.h"
#include "../../StanfordCPPLib/include/random.h"

const double MIN_AREA = 5000;
const double MAX_AREA = 10000;
const double MIN_EDGE = 20;
const int LINE_THICKNESS = 5;

void setRandomColor(GWindow &gw);
void subdivideCanvas(GWindow &gw, double x, double y, double width,
                     double height);

int main() {
  GWindow gw;
  subdivideCanvas(gw, 0, 0, gw.getWidth(), gw.getHeight());
  return 0;
}

void subdivideCanvas(GWindow &gw, double x, double y, double width,
                     double height) {
  if (width * height >= MIN_AREA) {
    if (width > height) {
      double mid = randomReal(MIN_EDGE, width - MIN_EDGE);

      subdivideCanvas(gw, x, y, mid, height);
      subdivideCanvas(gw, x + mid, y, width - mid, height);
      gw.setColor("Black");
      gw.fillRect(x + mid, y, LINE_THICKNESS, height);
      if (width * height <= MAX_AREA) {
        setRandomColor(gw);
        gw.fillRect(x, y, width, height);
      }
    } else {
      double mid = randomReal(MIN_EDGE, height - MIN_EDGE);
      subdivideCanvas(gw, x, y, width, mid);
      subdivideCanvas(gw, x, y + mid, width, height - mid);
      gw.setColor("Black");
      gw.fillRect(x, y + mid, width, LINE_THICKNESS);
      if (width * height <= MAX_AREA) {
        setRandomColor(gw);
        gw.fillRect(x, y, width, height);
      }
    }
  }
}

void setRandomColor(GWindow &gw) {
  int color = randomInteger(0, 2);
  switch (color) {
  case 0:
    gw.setColor("Red");
    break;
  case 1:
    gw.setColor("Blue");
    break;
  case 2:
    gw.setColor("Yellow");
    break;
  default:
    break;
  }
}
