#include <math.h>
#include "cprocessing.h"
#include "utils.h"

int IsAreaClicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y)
{
    float half_w = area_width / 2.0f;
    float half_h = area_height / 2.0f;

    return (click_x >= (area_center_x - half_w) &&
        click_x <= (area_center_x + half_w) &&
        click_y >= (area_center_y - half_h) &&
        click_y <= (area_center_y + half_h));
}

int IsCircleClicked(float circle_center_x, float circle_center_y, float diameter, float click_x, float click_y)
{
}

int AreCirclesIntersecting(float c1_x, float c1_y, float r1, float c2_x, float c2_y, float r2)
{
    float dx = c2_x - c1_x;
    float dy = c2_y - c1_y;

    float D = sqrtf(dx * dx + dy * dy);

    if (D < r1 + r2)
    {
        return 1;
    }

    return 0;
}