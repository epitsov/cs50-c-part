#include <stdio.h>
#include <cs50.h>
void draw(int h);
int main(void)

{
    int x = get_int("heigh: ");
    draw(x);

}
void draw(int h)
{
    if (h == 0)
    {
        return;
    }
    draw(h - 1);

    for (int i = 0; i < h; i++)
    {
        printf("#");
    }
    printf("\n");
}