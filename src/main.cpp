#include "eadkpp.h"
#include "display.h"
#include "palette.h"

const char *text = "Hello hello :)\nNice to meet you, before I fade away\n(Replace by math courses)\na(x-α)-β";

extern const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "Text Viewer";
extern const uint32_t eadk_api_level __attribute__((section(".rodata.eadk_api_level"))) = 0;

int main(int argc, char * argv[]) {
  EADK::Display::pushRectUniform(EADK::Display::Rect(0, 0, Display::Width, Display::Height), Black);
  EADK::Display::drawString(text, EADK::Display::Point(0, 0), false, Black, White);

  while (1) {
	EADK::Keyboard::State keyboardState = EADK::Keyboard::scan();
	if (keyboardState.keyDown(EADK::Keyboard::Key::Back)) {
		break;
	}
  }
}
