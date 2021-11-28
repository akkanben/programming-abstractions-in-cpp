/* Programming Abstractions in C++
 *
 * Exercise 02-17
 *
 * One of the principles that defines Taoist philosophy is that dichotomies do
 * not have sharp boundaries, and that there is mixing even between categories
 * that most people see as opposites. This idea is captured in the Yin-Yang
 * symbol, in which each region contains a bit of the other color:
 *
 * <image of Taijitu Symbol>
 *
 * Write a graphics program to draw this symbol at the center of an empty
 * graphics window. The challenge here is to decompose the drawing in such a
 * way that you can create it using only the methods in Table 2-2, which do not
 * include facilities for drawing and filling arcs and semicircles.
 *
 *
 * Solution 2021 Ben Mills
 *
 * I took some inspiration for how to draw in a cirular shape from Jose
 * Gonzalez's answer here:
 * https://stackoverflow.com/questions/27903333/how-can-i-use-a-for-loop-to-create-circles-in-a-circle-in-processing
 *
 */

#include "../../StanfordCPPLib/include/gwindow.h"
#include <cmath>

int const WINDOW_SIZE = 800;
int const STROKE = 10;
int const RESOLUTION = 50;
int const CENTER = WINDOW_SIZE / 2;
int const LRG_CIRCLE = WINDOW_SIZE - STROKE;
int const MED_CIRCLE = LRG_CIRCLE / 2;
int const SM_CIRCLE = MED_CIRCLE / 5;

void drawBaseBlackCircle(GWindow &gw);
void paintBlackSemiCircle(
    GWindow &gw); // paints RESOLUTION number of circles in an arc
void paintWhiteSemiCircle(GWindow &gw); // same but in white
void drawMediumWhiteCircle(GWindow &gw);
void drawSmallCircles(GWindow &gw);

int main() {
  GWindow gw(WINDOW_SIZE, WINDOW_SIZE);
  drawBaseBlackCircle(gw);
  paintWhiteSemiCircle(gw);
  paintBlackSemiCircle(gw);
  drawMediumWhiteCircle(gw);
  drawSmallCircles(gw);
  return 0;
}

void drawBaseBlackCircle(GWindow &gw) {
  gw.setColor("BLACK");
  gw.fillOval(0, 0, LRG_CIRCLE + STROKE, LRG_CIRCLE + STROKE);
}

void paintBlackSemiCircle(GWindow &gw) {
  double incrementingAngle = 0.0;
  for (int i = 0; i < RESOLUTION; i++) {
    int x = MED_CIRCLE / 2 * sin(incrementingAngle) + (MED_CIRCLE + STROKE) / 2;
    int y = MED_CIRCLE / 2 * cos(incrementingAngle) + (MED_CIRCLE + STROKE) / 2;
    gw.setColor("BLACK");
    gw.fillOval(x, y, MED_CIRCLE, MED_CIRCLE);
    incrementingAngle += M_PI / RESOLUTION;
  }
}

void paintWhiteSemiCircle(GWindow &gw) {
  double incrementingAngle = 0.0;
  for (int i = 0; i < RESOLUTION; i++) {
    int x = MED_CIRCLE / 2 * sin(incrementingAngle) + (MED_CIRCLE + STROKE) / 2;
    int y = MED_CIRCLE / 2 * cos(incrementingAngle) + (MED_CIRCLE + STROKE) / 2;
    gw.setColor("WHITE");
    gw.fillOval(x, y, MED_CIRCLE, MED_CIRCLE);
    incrementingAngle += -M_PI / RESOLUTION;
  }
}

void drawMediumWhiteCircle(GWindow &gw) {
  gw.setColor("WHITE");
  gw.fillOval(MED_CIRCLE - (MED_CIRCLE / 2), STROKE / 2, MED_CIRCLE,
              MED_CIRCLE);
}

void drawSmallCircles(GWindow &gw) {
  gw.setColor("BLACK");
  gw.fillOval(CENTER - SM_CIRCLE / 2, CENTER - MED_CIRCLE / 2 - SM_CIRCLE / 2,
              SM_CIRCLE, SM_CIRCLE);
  gw.setColor("WHITE");
  gw.fillOval(CENTER - SM_CIRCLE / 2, CENTER + MED_CIRCLE / 2 - SM_CIRCLE / 2,
              SM_CIRCLE, SM_CIRCLE);
}
