#pragma once

#include <map>

#include "../Maths.h"
#include "../Graphics/Window.h"

//All of these input defines are basically copy-pasted from GLFW with some modification...

//Joystick functionality yet to be implemented.

namespace alpha {
	enum Keyboard {
		ALPHA_KEY_UNKNOWN = -1,

		ALPHA_KEY_SPACE = 32,
		ALPHA_KEY_APOSTROPHE = 39,  /* ' */
		ALPHA_KEY_COMMA = 44,  /* , */
		ALPHA_KEY_MINUS = 45,  /* - */
		ALPHA_KEY_PERIOD = 46,  /* . */
		ALPHA_KEY_SLASH = 47,  /* / */
		ALPHA_KEY_0 = 48,
		ALPHA_KEY_1 = 49,
		ALPHA_KEY_2 = 50,
		ALPHA_KEY_3 = 51,
		ALPHA_KEY_4 = 52,
		ALPHA_KEY_5 = 53,
		ALPHA_KEY_6 = 54,
		ALPHA_KEY_7 = 55,
		ALPHA_KEY_8 = 56,
		ALPHA_KEY_9 = 57,
		ALPHA_KEY_SEMICOLON = 59,  /* ; */
		ALPHA_KEY_EQUAL = 61,  /* = */
		ALPHA_KEY_A = 65,
		ALPHA_KEY_B = 66,
		ALPHA_KEY_C = 67,
		ALPHA_KEY_D = 68,
		ALPHA_KEY_E = 69,
		ALPHA_KEY_F = 70,
		ALPHA_KEY_G = 71,
		ALPHA_KEY_H = 72,
		ALPHA_KEY_I = 73,
		ALPHA_KEY_J = 74,
		ALPHA_KEY_K = 75,
		ALPHA_KEY_L = 76,
		ALPHA_KEY_M = 77,
		ALPHA_KEY_N = 78,
		ALPHA_KEY_O = 79,
		ALPHA_KEY_P = 80,
		ALPHA_KEY_Q = 81,
		ALPHA_KEY_R = 82,
		ALPHA_KEY_S = 83,
		ALPHA_KEY_T = 84,
		ALPHA_KEY_U = 85,
		ALPHA_KEY_V = 86,
		ALPHA_KEY_W = 87,
		ALPHA_KEY_X = 88,
		ALPHA_KEY_Y = 89,
		ALPHA_KEY_Z = 90,
		ALPHA_KEY_LEFT_BRACKET = 91,  /* [ */
		ALPHA_KEY_BACKSLASH = 92,  /* \ */
		ALPHA_KEY_RIGHT_BRACKET = 93,  /* ] */
		ALPHA_KEY_GRAVE_ACCENT = 96,  /* ` */
		ALPHA_KEY_WORLD_1 = 161, /* non-US #1 */
		ALPHA_KEY_WORLD_2 = 162, /* non-US #2 */

		ALPHA_KEY_ESCAPE = 256,
		ALPHA_KEY_ENTER = 257,
		ALPHA_KEY_TAB = 258,
		ALPHA_KEY_BACKSPACE = 259,
		ALPHA_KEY_INSERT = 260,
		ALPHA_KEY_DELETE = 261,
		ALPHA_KEY_RIGHT = 262,
		ALPHA_KEY_LEFT = 263,
		ALPHA_KEY_DOWN = 264,
		ALPHA_KEY_UP = 265,
		ALPHA_KEY_PAGE_UP = 266,
		ALPHA_KEY_PAGE_DOWN = 267,
		ALPHA_KEY_HOME = 268,
		ALPHA_KEY_END = 269,
		ALPHA_KEY_CAPS_LOCK = 280,
		ALPHA_KEY_SCROLL_LOCK = 281,
		ALPHA_KEY_NUM_LOCK = 282,
		ALPHA_KEY_PRINT_SCREEN = 283,
		ALPHA_KEY_PAUSE = 284,
		ALPHA_KEY_F1 = 290,
		ALPHA_KEY_F2 = 291,
		ALPHA_KEY_F3 = 292,
		ALPHA_KEY_F4 = 293,
		ALPHA_KEY_F5 = 294,
		ALPHA_KEY_F6 = 295,
		ALPHA_KEY_F7 = 296,
		ALPHA_KEY_F8 = 297,
		ALPHA_KEY_F9 = 298,
		ALPHA_KEY_F10 = 299,
		ALPHA_KEY_F11 = 300,
		ALPHA_KEY_F12 = 301,
		ALPHA_KEY_F13 = 302,
		ALPHA_KEY_F14 = 303,
		ALPHA_KEY_F15 = 304,
		ALPHA_KEY_F16 = 305,
		ALPHA_KEY_F17 = 306,
		ALPHA_KEY_F18 = 307,
		ALPHA_KEY_F19 = 308,
		ALPHA_KEY_F20 = 309,
		ALPHA_KEY_F21 = 310,
		ALPHA_KEY_F22 = 311,
		ALPHA_KEY_F23 = 312,
		ALPHA_KEY_F24 = 313,
		ALPHA_KEY_F25 = 314,
		ALPHA_KEY_KP_0 = 320,
		ALPHA_KEY_KP_1 = 321,
		ALPHA_KEY_KP_2 = 322,
		ALPHA_KEY_KP_3 = 323,
		ALPHA_KEY_KP_4 = 324,
		ALPHA_KEY_KP_5 = 325,
		ALPHA_KEY_KP_6 = 326,
		ALPHA_KEY_KP_7 = 327,
		ALPHA_KEY_KP_8 = 328,
		ALPHA_KEY_KP_9 = 329,
		ALPHA_KEY_KP_DECIMAL = 330,
		ALPHA_KEY_KP_DIVIDE = 331,
		ALPHA_KEY_KP_MULTIPLY = 332,
		ALPHA_KEY_KP_SUBTRACT = 333,
		ALPHA_KEY_KP_ADD = 334,
		ALPHA_KEY_KP_ENTER = 335,
		ALPHA_KEY_KP_EQUAL = 336,
		ALPHA_KEY_LEFT_SHIFT = 340,
		ALPHA_KEY_LEFT_CONTROL = 341,
		ALPHA_KEY_LEFT_ALT = 342,
		ALPHA_KEY_LEFT_SUPER = 343,
		ALPHA_KEY_RIGHT_SHIFT = 344,
		ALPHA_KEY_RIGHT_CONTROL = 345,
		ALPHA_KEY_RIGHT_ALT = 346,
		ALPHA_KEY_RIGHT_SUPER = 347,
		ALPHA_KEY_MENU = 348,
		ALPHA_KEY_LAST = ALPHA_KEY_MENU,
		ALPHA_MOD_SHIFT = 0x0001,
		ALPHA_MOD_CONTROL = 0x0002,
		ALPHA_MOD_ALT = 0x0004,
		ALPHA_MOD_SUPER = 0x0008
	};

	enum Mouse {
		ALPHA_MOUSE_BUTTON_1 = 0,
		ALPHA_MOUSE_BUTTON_2 = 1,
		ALPHA_MOUSE_BUTTON_3 = 2,
		ALPHA_MOUSE_BUTTON_4 = 3,
		ALPHA_MOUSE_BUTTON_5 = 4,
		ALPHA_MOUSE_BUTTON_6 = 5,
		ALPHA_MOUSE_BUTTON_7 = 6,
		ALPHA_MOUSE_BUTTON_8 = 7,
		ALPHA_MOUSE_BUTTON_LAST = ALPHA_MOUSE_BUTTON_8,
		ALPHA_MOUSE_BUTTON_LEFT = ALPHA_MOUSE_BUTTON_1,
		ALPHA_MOUSE_BUTTON_RIGHT = ALPHA_MOUSE_BUTTON_2,
		ALPHA_MOUSE_BUTTON_MIDDLE = ALPHA_MOUSE_BUTTON_3
	};

	enum Joystick {
		ALPHA_JOYSTICK_1 = 0,
		ALPHA_JOYSTICK_2 = 1,
		ALPHA_JOYSTICK_3 = 2,
		ALPHA_JOYSTICK_4 = 3,
		ALPHA_JOYSTICK_5 = 4,
		ALPHA_JOYSTICK_6 = 5,
		ALPHA_JOYSTICK_7 = 6,
		ALPHA_JOYSTICK_8 = 7,
		ALPHA_JOYSTICK_9 = 8,
		ALPHA_JOYSTICK_10 = 9,
		ALPHA_JOYSTICK_11 = 10,
		ALPHA_JOYSTICK_12 = 11,
		ALPHA_JOYSTICK_13 = 12,
		ALPHA_JOYSTICK_14 = 13,
		ALPHA_JOYSTICK_15 = 14,
		ALPHA_JOYSTICK_16 = 15,
		ALPHA_JOYSTICK_LAST = ALPHA_JOYSTICK_16
	};

	enum InputType {
		Keyboard,
		Mouse
	};

	class InputManager {
	public:
		InputManager();
		InputManager(Window *window);

		glm::vec2 GetMousePosition();
		glm::vec2 GetWindowPosition();
		glm::vec2 GetWindowSize();
		void AddInput(std::string name, InputType type, int inputPositive, int inputNegative = -2); //-2 because -1 is defined as unknown key.
		int GetInput(std::string name);
	private:
		struct Input {
			int PositiveKey, NegativeKey;
			InputType Type;
		};

		std::map<std::string, Input> m_inputs;
		Window *m_window;
	};
}