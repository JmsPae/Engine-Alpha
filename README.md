# Engine Alpha

https://trello.com/b/WPf6CoEn/engine-alpha

## Documentation and how to get started
You can find the manual for Engine-Alpha and a guide on how the get started at
[docs.Engine-Alpha](https://unpause.github.io/docs.Engine-Alpha/)

## How to create a game
1. Include `Engine.h` in your main source file.
2. `#define ALPHA_ENTRY_POINT` before the `Engine.h` header file.
3. Create a function `alpha::Scene* alpha::CreateMainScene()` returning a pointer to your main scene.

If you want to define your own entry point only do step 1 and define your own entry point

![Alpha](https://i.imgur.com/vNyRzwO.png)
