#include "eadkpp.h"
#include "display.h"
#include "palette.h"
#include "text.cpp"

#define CHAR_SIZE_H 14
#define NB_LINES 17
#define NB_CHARS_LINE 46
#define KEYPRESS_DELAY 75

extern const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "Text Viewer";
extern const uint32_t eadk_api_level __attribute__((section(".rodata.eadk_api_level"))) = 0;

int count()
{
    int c=0;
    for(int i=0;i<100;i++)
    {
        if(text[i])
            c++;
    }
    return c;
}

void draw_lines(int index) {
    EADK::Display::pushRectUniform(EADK::Display::Rect(0, 0, Display::Width, Display::Height), Black);
    for (int l = index ; l < index + NB_LINES; l++) {
        if (text[l]) {
            EADK::Display::drawString(text[l], EADK::Display::Point(0, CHAR_SIZE_H * (l - index)), false, Black, White);
        }
    }
}

int main()
{
    int index = 0;
	EADK::Display::pushRectUniform(EADK::Display::Rect(0, 0, Display::Width, Display::Height), Black);
    draw_lines(index);

	while (1)
	{
		EADK::Keyboard::State keyboardState = EADK::Keyboard::scan();
		if (keyboardState.keyDown(EADK::Keyboard::Key::Back))
		{
			break;
		} else if (keyboardState.keyDown(EADK::Keyboard::Key::Down)) {
            if (index + 1 <= count() - NB_LINES) {
                index += 1;
                draw_lines(index);
                EADK::Timing::msleep(KEYPRESS_DELAY);
            }
        } else if (keyboardState.keyDown(EADK::Keyboard::Key::Up)) {
            if (index - 1 > 0) {
                index -= 1;
                draw_lines(index);
                EADK::Timing::msleep(KEYPRESS_DELAY);
            }
        }
	}
}
